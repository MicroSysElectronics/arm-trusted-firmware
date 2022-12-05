// SPDX-License-Identifier: BSD-3-Clause
/*
 * Copyright 2020-2021 NXP
 */

#include <common/fdt_wrappers.h>
#include <stdio.h>
#include <lib/mmio.h>
#include <libfdt.h>
#include <drivers/delay_timer.h>
#include <drivers/nxp/s32/i2c/s32_i2c.h>
#include "s32_clocks.h"
#include "s32g_pinctrl.h"

/* Register index */
#define IBAD	0
#define IBFD	1
#define IBCR	2
#define IBSR	3
#define IBDR	4

#define IBSR_RXAK	BIT(0)
#define IBSR_IBIF	BIT(1)
#define IBSR_IBAL	BIT(4)
#define IBSR_IBB	BIT(5)

#define IBCR_RSTA	BIT(2)
#define IBCR_NOACK	BIT(3)
#define IBCR_TX		BIT(4)
#define IBCR_MSSL	BIT(5)

#define IBSR_IBIF_CLEAR	BIT(1)
#define IBSR_IBAL_CLEAR	BIT(4)
#define IBCR_MDIS_EN	(0 << 7)
#define IBCR_MDIS_DIS	BIT(7)

#define I2C_READ	1
#define I2C_WRITE	0

#define I2C_MAX_RETRY_CNT               10

#define I2C_IDLE			0
#define I2C_TRANSMISSION_COMPLETE	2
#define I2C_BUSY			3

static uint16_t s32_clk_div[][2] = {
	{  34, 0x00}, {  36, 0x01}, {  38, 0x02}, {  40, 0x03}, {  42, 0x04},
	// {  44, 0x08},
	{  44, 0x05}, {  46, 0x06}, {  48, 0x09}, {  52, 0x0a}, {  54, 0x07},
	//{  64, 0x10},
	//{  72, 0x11},
	{  56, 0x0b}, {  60, 0x0c}, {  64, 0x0d}, {  72, 0x0e}, {  80, 0x12},
	//{  96, 0x18},
	{  84, 0x0f}, {  88, 0x13}, {  96, 0x14}, { 104, 0x15}, { 112, 0x19},
	//{ 160, 0x20},
	{ 120, 0x16}, { 128, 0x1a}, { 144, 0x17}, { 160, 0x1c}, { 176, 0x1d},
	//{ 256, 0x23},
	{ 192, 0x21}, { 208, 0x1e}, { 224, 0x22}, { 256, 0x1f}, { 288, 0x24},
	//{ 320, 0x28},
	//{ 384, 0x29},
	{ 320, 0x25}, { 384, 0x26}, { 448, 0x2a}, { 480, 0x27}, { 512, 0x2b},
	//{ 640, 0x30},
	//{ 768, 0x31},
	{ 576, 0x2c}, { 640, 0x2d}, { 768, 0x2e}, { 896, 0x32}, { 960, 0x2f},
	//{1280, 0x38},
	//{1536, 0x39},
	{1024, 0x33}, {1152, 0x34}, {1280, 0x35}, {1536, 0x36}, {1792, 0x3a},
	{1920, 0x37}, {2048, 0x3b}, {2304, 0x3c}, {2560, 0x3d}, {3072, 0x3e},
	{3840, 0x3f},
};

static void s32_i2c_disable(struct s32_i2c_bus *bus)
{
	uint8_t reg;

	reg = mmio_read_8(bus->base + IBCR);

	// if module is enabled:
	if ((reg & IBCR_MDIS_DIS) == 0) {
		reg |= IBCR_MDIS_DIS;
		mmio_write_8(bus->base + IBCR, reg);
		mmio_write_8(bus->base + IBSR,
				IBSR_IBIF_CLEAR | IBSR_IBAL_CLEAR);
	}
}

static void s32_i2c_enable(struct s32_i2c_bus *bus)
{
	uint8_t reg;

	reg = mmio_read_8(bus->base + IBCR);

	// if module is disabled:
	if (reg & IBCR_MDIS_DIS) {
		reg &= ~IBCR_MDIS_DIS;
		mmio_write_8(bus->base + IBCR, reg);
		udelay(50);
		/* Clear interrupt flag */
		mmio_write_8(bus->base + IBSR,
				IBSR_IBIF_CLEAR | IBSR_IBAL_CLEAR);
	}
}

/*
 * Configure bus speed
 */
static int s32_i2c_set_bus_speed(struct s32_i2c_bus *bus, int speed)
{
	int i;

	if (!bus || !bus->base)
		return -EINVAL;

	for (i = 0; ARRAY_SIZE(s32_clk_div[0]) - 1; i++)
		if ((I2C_CLK_FREQ / s32_clk_div[i][0]) <= speed)
			break;

	/* Write divider value */
	mmio_write_8(bus->base + IBFD, s32_clk_div[i][1]);

	/* Module reset */
	s32_i2c_disable(bus);
	return 0;
}

/*
 * Wait until the bus enters a specified state or timeout occurs.
 */
static uint8_t s32_i2c_wait(struct s32_i2c_bus *bus, unsigned int state)
{
	uint8_t ibsr;
	uint32_t wait_cnt = 1000;

	if (state == I2C_IDLE)
		wait_cnt = 50*1000;

	while (wait_cnt--) {
		ibsr = mmio_read_8(bus->base + IBSR);

		switch(state) {
		case I2C_IDLE:
			if (!(ibsr & IBSR_IBB))
				return 0;
			break;
		case I2C_BUSY:
			if (ibsr & IBSR_IBB)
				return 0;
			break;
		case I2C_TRANSMISSION_COMPLETE:
			if (ibsr & IBSR_IBIF) {
				/* Clear interrupt flag */
				mmio_write_8(bus->base + IBSR,
					     IBSR_IBIF_CLEAR);
				return 0;
			}
		}

		udelay(1);
	}

	INFO("%s: timeout state=%x\n", __func__, state);
	return -ETIMEDOUT;
}

static uint8_t s32_i2c_write_byte(struct s32_i2c_bus *bus, uint8_t byte)
{
	uint8_t ibsr;
	int ret;

	if (!bus || !bus->base)
		return -EINVAL;

	/* Write data */
	mmio_write_8(bus->base + IBDR, byte);

	/* Wait for transfer complete */
	ret = s32_i2c_wait(bus, I2C_TRANSMISSION_COMPLETE);
	if (ret < 0)
		return ret;

	/* Examine IBSR[RXAK] for an acknowledgment from the slave. */
	ibsr = mmio_read_8(bus->base + IBSR);
	return ibsr & IBSR_RXAK ? -EIO : 0;
}

static uint8_t s32_i2c_chip_setup(struct s32_i2c_bus *bus,
				   uint8_t chip, int mode)
{
	/* The master transmits the seven-bit slave address.
	 * The master transmits the R/W bit.
	 */
	return s32_i2c_write_byte(bus, (chip << 1) | mode);
}

static uint8_t s32_i2c_address_setup(struct s32_i2c_bus *bus,
				      uint32_t addr, int addr_len)
{
	uint8_t reg;
	int ret;

	while (addr_len--) {
		/* Write data to I2C Bus Data I/O Register (IBDR) */
		reg = (addr >> (addr_len * 8)) & 0xff;
		ret = s32_i2c_write_byte(bus, reg);
		if (ret < 0)
			return ret;
	}

	return 0;
}

/*
 * Stop sequence
 */
static uint8_t s32_i2c_stop(struct s32_i2c_bus *bus)
{
	uint8_t ibcr;
	int ret;

	if (!bus || !bus->base)
		return -EINVAL;

	/* Clear IBCR */
	ibcr = mmio_read_8(bus->base + IBCR) & ~IBCR_MSSL;
	mmio_write_8(bus->base + IBCR, ibcr);

	/* Wait for idle state */
	ret = s32_i2c_wait(bus, I2C_IDLE);
	if (ret == -ETIMEDOUT)
		s32_i2c_disable(bus);
	return ret;
}

/*
 * Prepare the transfer by sending: start signal, chip and write
 * register address
 */
static uint8_t s32_i2c_try_start(struct s32_i2c_bus *bus,
		uint8_t chip, uint32_t addr, int addr_len)
{
	uint8_t reg, ret;

	if (!bus || !bus->base)
		return -EINVAL;

	/* Clear the MDIS field to enable the I2C interface system */
	s32_i2c_disable(bus);
	s32_i2c_enable(bus);

	reg = mmio_read_8(bus->base + IBAD);
	if (reg == (chip << 1))
		mmio_write_8(bus->base + IBAD, reg ^ 2);

	/* Wait in loop for IBB flag to clear. */
	ret = s32_i2c_wait(bus, I2C_IDLE);
	if (ret < 0)
		return ret;

	/* Set as master */
	reg = mmio_read_8(bus->base + IBCR) | IBCR_MSSL;
	mmio_write_8(bus->base + IBCR, reg);

	ret = s32_i2c_wait(bus, I2C_BUSY);
	if (ret < 0)
		return ret;

	/* Set transmission and noack */
	reg |= IBCR_TX | IBCR_NOACK;
	mmio_write_8(bus->base + IBCR, reg);

	/* Send chip and address */
	ret = s32_i2c_chip_setup(bus, chip, I2C_WRITE);
	if (ret < 0)
		return ret;

	return s32_i2c_address_setup(bus, addr, addr_len);

	return 0;
}

/*
 * Start sequence
 */
static uint8_t s32_i2c_start(struct s32_i2c_bus *bus, uint8_t chip,
		uint32_t addr, int addr_len)
{
	int counter = 0;
	uint8_t ret = 0;

	if (!bus || !bus->base)
		return -EINVAL;

	do {
		if (counter++ > 0)
			udelay(100);

		ret = s32_i2c_try_start(bus, chip, addr, addr_len);
		if (ret >= 0)
			return 0;

		s32_i2c_stop(bus);
	} while ((ret == -EAGAIN) && (counter < I2C_MAX_RETRY_CNT));

	INFO("%s: failed\n", __func__);
	return ret;
}

static uint8_t s32_i2c_read_buffer(struct s32_i2c_bus *bus, unsigned char chip,
		unsigned char *buf, int len)
{
	int i;
	uint8_t reg, ret;

	if (!bus || !bus->base || !buf)
		return -EINVAL;

	if (!len)
		return 0;

	/* Perform a dummy read of IBDR to initiate the receive operation */
	mmio_read_8(bus->base + IBDR);

	/* Read data */
	for (i = 0; i < len; i++) {
		/* Wait for transfer complete. */
		ret = s32_i2c_wait(bus, I2C_TRANSMISSION_COMPLETE);
		if (ret < 0)
			return ret;

		if (i == (len - 2)) {
			/* Disable ACK */
			reg = mmio_read_8(bus->base + IBCR) | IBCR_NOACK;
			mmio_write_8(bus->base + IBCR, reg);
		} else if (i == (len - 1)) {
			/* Generate STOP condition */
			reg = mmio_read_8(bus->base + IBCR) & ~IBCR_MSSL;
			mmio_write_8(bus->base + IBCR, reg);
		}

		/* Read data */
		buf[i] = mmio_read_8(bus->base + IBDR);
	}

	return 0;
}

/*
 * I2C read
 * @bus:	I2C bus
 * @chip:	chip
 * @addr:	address
 * @addr_len:	data address length. This can be 1 or 2 bytes long.
 *		Some day it might be 3 bytes long.
 * @buffer:	buffer where data will be returned
 * @len:	number of objects
 */
uint8_t s32_i2c_read(struct s32_i2c_bus *bus, uint8_t chip,
		unsigned int addr, int addr_len, uint8_t *buffer,
		int len)
{
	uint8_t reg, ret = 0;

	if (!bus || !bus->base || !buffer) {
		ERROR("%s: Invalid parameter\n", __func__);
		return -EINVAL;
	}
	if (addr_len > 3 || addr_len <= 0) {
		ERROR("%s: Invalid parameter addr_len\n", __func__);
		return -EINVAL;
	}

	ret = s32_i2c_start(bus, chip, addr, addr_len);
	if (ret < 0)
		return ret;

	/* Generate repeat start condition */
	reg = mmio_read_8(bus->base + IBCR) | IBCR_RSTA;
	mmio_write_8(bus->base + IBCR, reg);

	/* Setup in read mode. */
	ret = s32_i2c_chip_setup(bus, chip, I2C_READ);
	if (ret < 0) {
		s32_i2c_stop(bus);
		return ret;
	}

	/* Select Receive mode */
	reg = mmio_read_8(bus->base + IBCR) & ~IBCR_TX;

	/* No ack necessary if only one byte is sent */
	if (len == 1)
		reg |= IBCR_NOACK;
	else
		reg &= ~IBCR_NOACK;

	mmio_write_8(bus->base + IBCR, reg);

	ret = s32_i2c_read_buffer(bus, chip, buffer, len);

	s32_i2c_stop(bus);
	return ret;
}

/*
 * I2C write
 * @bus:	I2C bus
 * @chip:	chip
 * @addr:	address
 * @addr_len:	data address length. This can be 1 or 2 bytes long.
 *		Some day it might be 3 bytes long.
 * @buffer:	buffer where data will be returned
 * @len:	number of objects
 */
uint8_t s32_i2c_write(struct s32_i2c_bus *bus, uint8_t chip,
		unsigned int addr, int addr_len, uint8_t *buffer,
		int len)
{
	uint8_t ret = 0;
	int i;

	if (!bus || !bus->base || !buffer) {
		ERROR("%s: Invalid parameter\n", __func__);
		return -EINVAL;
	}
	if (addr_len > 3 || addr_len <= 0) {
		ERROR("%s: Invalid parameter addr_len\n", __func__);
		return -EINVAL;
	}

	ret = s32_i2c_start(bus, chip, addr, addr_len);
	if (ret < 0)
		return ret;

	/* Start the transfer */
	for (i = 0; i < len; i++) {
		ret = s32_i2c_write_byte(bus, buffer[i]);
		if (ret < 0)
			break;
	}

	s32_i2c_stop(bus);
	return ret;
}

/*
 * Init I2C Bus
 */
int s32_i2c_init(struct s32_i2c_bus *bus)
{
	if (!bus) {
		ERROR("%s: Invalid parameter\n", __func__);
		return -EINVAL;
	}

	/*
	 * Take care that pin muxing is setup correctly:
	 */
	i2c_config_pinctrl();

	return s32_i2c_set_bus_speed(bus, bus->speed);
}

/*
 * @brief  Get I2C setup information from the device tree
 * @param  fdt: Pointer to the device tree
 * @param  node: I2C node offset
 * @param  bus: Ref to the initialization i2c_bus
 */
void s32_i2c_get_setup_from_fdt(void *fdt, int node,
				 struct s32_i2c_bus *bus)
{
	const fdt32_t *cuint;
	int ret;

	ret = fdt_get_reg_props_by_index(fdt, node, 0, &bus->base, NULL);
	if (ret) {
		ERROR("Invalid I2C base address\n");
		return;
	}

	cuint = fdt_getprop(fdt, node, "clock-frequency", NULL);
	bus->speed = cuint == NULL ? S32_DEFAULT_SPEED : fdt32_to_cpu(*cuint);

	/*
	 * Initialize controller:
	 */
	s32_i2c_init(bus);
}

