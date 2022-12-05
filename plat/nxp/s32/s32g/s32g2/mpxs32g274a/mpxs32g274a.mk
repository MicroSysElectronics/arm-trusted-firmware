# Copyright (C) 2021-2022 MicroSys Electronics GmbH
# Author: Kay Potthoff <kay.potthoff@microsys.de>

PLAT_BL_COMMON_SOURCES +=      ${PLAT_SOC_PATH}/s32g2_vr5510.c

CFLAGS += -DCONFIG_TARGET_MPXS32G274A
