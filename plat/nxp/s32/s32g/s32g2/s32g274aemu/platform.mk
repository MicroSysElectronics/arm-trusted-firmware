#
# Copyright 2022 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#

S32CC_EMU = 1

include plat/nxp/s32/s32g/s32g2/s32g2.mk

S32_BOARD_PATH		:= ${PLAT_SOC_PATH}/s32g274aemu

PLAT_INCLUDES		+= -I${S32_BOARD_PATH}/include \

DTB_FILE_NAME		?= s32g274a-emu.dtb
