/*
 * Copyright 2022 NXP
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ddr/ddr_init.h>

uint16_t dmem_1d_cfg[] = {
	0x0000,
	0x0000,
	0x0000,
	0x0c80,
	0x0002,
	0x0000,
	0x0018,
	0x0000,
	0x131f,
	0x00ff,
	0x0000,
	0x0003,
	0x0001,
	0x0100,
	0x0000,
	0x0100,
	0x0000,
	0x0000,
	0x0310,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x2d54,
	0x0033,
	0x4d66,
	0x4f08,
	0x0000,
	0x0004,
	0x2d54,
	0x0033,
	0x4d66,
	0x4f08,
	0x0000,
	0x0004,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x1000,
	0x0003,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x5400,
	0x332d,
	0x6600,
	0x084d,
	0x004f,
	0x0400,
	0x5400,
	0x332d,
	0x6600,
	0x084d,
	0x004f,
	0x0400,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x00ff,
	0x0000,
	0x0000,
	0x014a,
	0x0181,
	0x0118,
	0x0118,
	0x016f,
	0x016f,
	0x0159,
	0x0181,
	0x0120,
	0x0120,
	0x0000,
	0x0000,
	0x701c,
	0x61a8,
	0x35ac,
	0x35ac,
	0x125c,
	0x125c,
	0xc738,
	0xb0f4,
	0x6590,
	0x6590,
	0x0000,
	0x0000,
	0x3a44,
	0x0075,
	0x0000,
	0x0000,
	0x2820,
	0x140f,
	0x1f02,
	0x01f0,
	0x0000,
	0xb400,
	0x01ff,
	0x0100,
	0xb400,
	0x01f0,
	0x0000,
	0xb400,
	0x01f4,
	0x0000,
	0xb900,
	0x01f0,
	0x0000,
	0xba00,
	0x01f0,
	0x0000,
	0xbb00,
	0x01f0,
	0x0000,
	0x0100,
	0x01f0,
	0x0000,
	0x1300,
	0x01f0,
	0x0000,
	0xf900,
	0x04f0,
	0x0000,
	0xfa02,
	0x04f0,
	0x0000,
	0xfb00,
	0x04f0,
	0x0000,
	0x6004,
	0x07f0,
	0x0800,
	0x6500,
	0x07f0,
	0x0000,
	0x6200,
	0x01ff,
	0x0000,
	0x0200,
	0x01f0,
	0x2000,
	0x1f02,
	0x01f0,
	0x0000,
	0xb400,
	0x01ff,
	0x0100,
	0xb400,
	0x01f0,
	0x0000,
	0xb400,
	0x01f4,
	0x0000,
	0xb900,
	0x01f0,
	0x0000,
	0xba00,
	0x01f0,
	0x0000,
	0xbb00,
	0x01f0,
	0x0000,
	0x0100,
	0x01f0,
	0x0000,
	0x1100,
	0x01f0,
	0x0100,
	0x1200,
	0x01f0,
	0x0000,
	0x18f0,
	0x01f0,
	0x0100,
	0x1300,
	0x01f0,
	0x0000,
	0xf900,
	0x04f0,
	0x0000,
	0xfa02,
	0x04f0,
	0x0000,
	0xfb00,
	0x04f0,
	0x0000,
	0x6204,
	0x01ff,
	0x0000,
	0x6200,
	0x01f0,
	0x0f00,
	0x6200,
	0x01f4,
	0xf000,
	0x0200,
	0x01f0,
	0x0400,
	0x1f02,
	0x01f0,
	0x0000,
	0x3b00,
	0x02f0,
	0x0100,
	0xb200,
	0x01ff,
	0x0000,
	0xb200,
	0x01f0,
	0x0100,
	0xb400,
	0x01ff,
	0x0100,
	0xb400,
	0x01f0,
	0x0000,
	0xb900,
	0x01f0,
	0x0000,
	0xba00,
	0x01f0,
	0x0000,
	0xbb00,
	0x01f0,
	0x0000,
	0x0100,
	0x01f0,
	0x0000,
	0x6000,
	0x07f0,
	0x0100,
	0x6500,
	0x07f0,
	0xff00,
	0x2601,
	0x07ff,
	0x0000,
	0x2700,
	0x07ff,
	0x0000,
	0x1300,
	0x01f0,
	0x0200,
	0x3200,
	0x01ff,
	0x0000,
	0x6208,
	0x01ff,
	0x0000,
	0x6200,
	0x01f0,
	0x0100,
	0x6200,
	0x01f4,
	0x0100,
	0x0200,
	0x01f0,
	0x0800,
	0x1f02,
	0x01f0,
	0x0000,
	0xb200,
	0x01ff,
	0x0000,
	0xb200,
	0x01f0,
	0x0100,
	0xb200,
	0x01f4,
	0x0100,
	0xb400,
	0x01ff,
	0x0100,
	0xb400,
	0x01f0,
	0x0000,
	0xb400,
	0x01f4,
	0x0000,
	0xb900,
	0x01f0,
	0x0000,
	0xba00,
	0x01f0,
	0x0000,
	0xbb00,
	0x01f0,
	0x0000,
	0x1100,
	0x01f0,
	0x0100,
	0x1201,
	0x01f0,
	0x0100,
	0x1300,
	0x01f0,
	0x0200,
	0x1800,
	0x01f0,
	0x0100,
	0x6000,
	0x07f0,
	0x0100,
	0x6500,
	0x07f0,
	0xff00,
	0x2601,
	0x07ff,
	0xff00,
	0x27ff,
	0x07ff,
	0xff00,
	0x62ff,
	0x01ff,
	0x0000,
	0x6200,
	0x01f0,
	0x0100,
	0x6200,
	0x01f4,
	0x1000,
	0x3200,
	0x01ff,
	0x0000,
	0x0208,
	0x01f0,
	0x1000,
	0x0002,
	0x0000,
	0x020d,
	0x0301,
	0x0c0b,
	0x160e,
	0x1004,
	0x1811,
	0x0c06,
	0x1610,
	0x201c,
	0x2824,
	0x0c06,
	0x1812,
	0x241e,
	0x2c28,
	0x0a06,
	0x140e,
	0x1c18,
	0x2420,
	0x0a06,
	0x1610,
	0x201a,
	0x2824,
	0x006e,
	0x0002,
	0x0001,
	0x00fd,
	0x0004,
	0x000f,
	0x0060,
	0x0007,
	0x0000,
	0x00e8,
	0x0004,
	0x00ff,
	0x00fc,
	0x0004,
	0x0404,
	0x003a,
	0x0002,
	0x0002,
	0x0011,
	0x0007,
	0x0000,
	0x0000,
};

size_t dmem_1d_cfg_size = ARRAY_SIZE(dmem_1d_cfg);

uint16_t dmem_2d_cfg[] = {
	0x0000,
	0x0000,
	0x0000,
	0x0c80,
	0x0002,
	0x0000,
	0x0018,
	0x0000,
	0x0061,
	0x00ff,
	0x0000,
	0x0003,
	0x0001,
	0x0100,
	0x0000,
	0x0100,
	0x2080,
	0x0000,
	0x0310,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x2d54,
	0x0033,
	0x4d66,
	0x4f08,
	0x0000,
	0x0004,
	0x2d54,
	0x0033,
	0x4d66,
	0x4f08,
	0x0000,
	0x0004,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x1000,
	0x0003,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x5400,
	0x332d,
	0x6600,
	0x084d,
	0x004f,
	0x0400,
	0x5400,
	0x332d,
	0x6600,
	0x084d,
	0x004f,
	0x0400,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0xff00,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0100,
	0x0014,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x014a,
	0x0181,
	0x0118,
	0x0118,
	0x016f,
	0x016f,
	0x0159,
	0x0181,
	0x0120,
	0x0120,
	0x0000,
	0x0000,
	0x701c,
	0x61a8,
	0x35ac,
	0x35ac,
	0x125c,
	0x125c,
	0xc738,
	0xb0f4,
	0x6590,
	0x6590,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x3a44,
	0x0075,
	0x0000,
	0x321e,
	0x0100,
	0x0000,
	0xffff,
	0x01e0,
	0x00f0,
	0x00a0,
	0x0078,
	0x0060,
	0x0050,
	0x0043,
	0x003c,
	0x0035,
	0x0030,
	0x002c,
	0x0028,
	0x0025,
	0x0022,
	0x0020,
	0x001e,
	0x001c,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0100,
	0x0302,
	0x0706,
	0x0b0a,
	0x0f0e,
	0x1b1a,
	0x1f1e,
	0x3b3a,
	0x3f3e,
	0x0000,
	0x2820,
	0x140f,
	0x1f02,
	0x01f0,
	0x0000,
	0xb400,
	0x01ff,
	0x0100,
	0xb400,
	0x01f0,
	0x0000,
	0xb400,
	0x01f4,
	0x0000,
	0xb900,
	0x01f0,
	0x0000,
	0xba00,
	0x01f0,
	0x0000,
	0xbb00,
	0x01f0,
	0x0000,
	0x0100,
	0x01f0,
	0x0000,
	0x1300,
	0x01f0,
	0x0000,
	0xf900,
	0x04f0,
	0x0000,
	0xfa02,
	0x04f0,
	0x0000,
	0xfb00,
	0x04f0,
	0x0000,
	0x6004,
	0x07f0,
	0x0800,
	0x6500,
	0x07f0,
	0x0000,
	0x6200,
	0x01ff,
	0x0000,
	0x0200,
	0x01f0,
	0x2000,
	0x0002,
	0x0000,
	0x020d,
	0x0301,
	0x0c0b,
	0x160e,
	0x1004,
	0x1811,
	0x0c06,
	0x1610,
	0x201c,
	0x2824,
	0x0c06,
	0x1812,
	0x241e,
	0x2c28,
	0x0a06,
	0x140e,
	0x1c18,
	0x2420,
	0x0a06,
	0x1610,
	0x201a,
	0x2824,
	0x006e,
	0x0002,
	0x0001,
	0x00fd,
	0x0004,
	0x000f,
	0x0060,
	0x0007,
	0x0000,
	0x00e8,
	0x0004,
	0x00ff,
	0x00fc,
	0x0004,
	0x0404,
	0x003a,
	0x0002,
	0x0002,
	0x0011,
	0x0007,
	0x0000,
	0x0000,
};

size_t dmem_2d_cfg_size = ARRAY_SIZE(dmem_2d_cfg);
