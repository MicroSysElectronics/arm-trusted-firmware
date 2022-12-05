# Copyright (C) 2022 MicroSys Electronics GmbH
# Author: Kay Potthoff <kay.potthoff@microsys.de>

# First set DTB_FILE_NAME, before including platform:
DTB_FILE_NAME = s32g274asbc3.dtb

include plat/nxp/s32/s32g/s32g2/s32g2.mk

PLAT_MODULE_PATH = ${PLAT_SOC_PATH}/mpxs32g274a

include ${PLAT_MODULE_PATH}/mpxs32g274a.mk

S32_BOARD_PATH		:= ${PLAT_SOC_PATH}/s32g274asbc3

PLAT_INCLUDES          += -I${S32_BOARD_PATH}/include

CFLAGS += -DCONFIG_TARGET_S32G274ASBC3
