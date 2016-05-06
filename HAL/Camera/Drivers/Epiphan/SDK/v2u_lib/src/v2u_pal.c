/****************************************************************************
 *
 * $Id: v2u_pal.c 8243 2009-12-11 12:59:11Z monich $
 *
 * Copyright (C) 2003-2009 Epiphan Systems Inc. All rights reserved.
 *
 * RGB palettes and masks
 *
 ****************************************************************************/

#include "v2u_save.h"

/* rgb121 */
const BmpPalEntry v2u_palette_4bpp[16] = {
    {0x00,0x00,0x00,0},{0x00,0x00,0xff,0},
    {0x00,0x55,0x00,0},{0x00,0x55,0xff,0},
    {0x00,0xaa,0x00,0},{0x00,0xaa,0xff,0},
    {0x00,0xff,0x00,0},{0x00,0xff,0xff,0},
    {0xff,0x00,0x00,0},{0xff,0x00,0xff,0},
    {0xff,0x55,0x00,0},{0xff,0x55,0xff,0},
    {0xff,0xaa,0x00,0},{0xff,0xaa,0xff,0},
    {0xff,0xff,0x00,0},{0xff,0xff,0xff,0},
};

/* rgb233 */
const BmpPalEntry v2u_palette_8bpp[256] = {
    {0x00,0x00,0x00,0},{0x24,0x00,0x00,0},{0x49,0x00,0x00,0},{0x6D,0x00,0x00,0},
    {0x92,0x00,0x00,0},{0xB6,0x00,0x00,0},{0xDB,0x00,0x00,0},{0xFF,0x00,0x00,0},
    {0x00,0x24,0x00,0},{0x24,0x24,0x00,0},{0x49,0x24,0x00,0},{0x6D,0x24,0x00,0},
    {0x92,0x24,0x00,0},{0xB6,0x24,0x00,0},{0xDB,0x24,0x00,0},{0xFF,0x24,0x00,0},
    {0x00,0x49,0x00,0},{0x24,0x49,0x00,0},{0x49,0x49,0x00,0},{0x6D,0x49,0x00,0},
    {0x92,0x49,0x00,0},{0xB6,0x49,0x00,0},{0xDB,0x49,0x00,0},{0xFF,0x49,0x00,0},
    {0x00,0x6D,0x00,0},{0x24,0x6D,0x00,0},{0x49,0x6D,0x00,0},{0x6D,0x6D,0x00,0},
    {0x92,0x6D,0x00,0},{0xB6,0x6D,0x00,0},{0xDB,0x6D,0x00,0},{0xFF,0x6D,0x00,0},
    {0x00,0x92,0x00,0},{0x24,0x92,0x00,0},{0x49,0x92,0x00,0},{0x6D,0x92,0x00,0},
    {0x92,0x92,0x00,0},{0xB6,0x92,0x00,0},{0xDB,0x92,0x00,0},{0xFF,0x92,0x00,0},
    {0x00,0xB6,0x00,0},{0x24,0xB6,0x00,0},{0x49,0xB6,0x00,0},{0x6D,0xB6,0x00,0},
    {0x92,0xB6,0x00,0},{0xB6,0xB6,0x00,0},{0xDB,0xB6,0x00,0},{0xFF,0xB6,0x00,0},
    {0x00,0xDB,0x00,0},{0x24,0xDB,0x00,0},{0x49,0xDB,0x00,0},{0x6D,0xDB,0x00,0},
    {0x92,0xDB,0x00,0},{0xB6,0xDB,0x00,0},{0xDB,0xDB,0x00,0},{0xFF,0xDB,0x00,0},
    {0x00,0xFF,0x00,0},{0x24,0xFF,0x00,0},{0x49,0xFF,0x00,0},{0x6D,0xFF,0x00,0},
    {0x92,0xFF,0x00,0},{0xB6,0xFF,0x00,0},{0xDB,0xFF,0x00,0},{0xFF,0xFF,0x00,0},
    {0x00,0x00,0x55,0},{0x24,0x00,0x55,0},{0x49,0x00,0x55,0},{0x6D,0x00,0x55,0},
    {0x92,0x00,0x55,0},{0xB6,0x00,0x55,0},{0xDB,0x00,0x55,0},{0xFF,0x00,0x55,0},
    {0x00,0x24,0x55,0},{0x24,0x24,0x55,0},{0x49,0x24,0x55,0},{0x6D,0x24,0x55,0},
    {0x92,0x24,0x55,0},{0xB6,0x24,0x55,0},{0xDB,0x24,0x55,0},{0xFF,0x24,0x55,0},
    {0x00,0x49,0x55,0},{0x24,0x49,0x55,0},{0x49,0x49,0x55,0},{0x6D,0x49,0x55,0},
    {0x92,0x49,0x55,0},{0xB6,0x49,0x55,0},{0xDB,0x49,0x55,0},{0xFF,0x49,0x55,0},
    {0x00,0x6D,0x55,0},{0x24,0x6D,0x55,0},{0x49,0x6D,0x55,0},{0x6D,0x6D,0x55,0},
    {0x92,0x6D,0x55,0},{0xB6,0x6D,0x55,0},{0xDB,0x6D,0x55,0},{0xFF,0x6D,0x55,0},
    {0x00,0x92,0x55,0},{0x24,0x92,0x55,0},{0x49,0x92,0x55,0},{0x6D,0x92,0x55,0},
    {0x92,0x92,0x55,0},{0xB6,0x92,0x55,0},{0xDB,0x92,0x55,0},{0xFF,0x92,0x55,0},
    {0x00,0xB6,0x55,0},{0x24,0xB6,0x55,0},{0x49,0xB6,0x55,0},{0x6D,0xB6,0x55,0},
    {0x92,0xB6,0x55,0},{0xB6,0xB6,0x55,0},{0xDB,0xB6,0x55,0},{0xFF,0xB6,0x55,0},
    {0x00,0xDB,0x55,0},{0x24,0xDB,0x55,0},{0x49,0xDB,0x55,0},{0x6D,0xDB,0x55,0},
    {0x92,0xDB,0x55,0},{0xB6,0xDB,0x55,0},{0xDB,0xDB,0x55,0},{0xFF,0xDB,0x55,0},
    {0x00,0xFF,0x55,0},{0x24,0xFF,0x55,0},{0x49,0xFF,0x55,0},{0x6D,0xFF,0x55,0},
    {0x92,0xFF,0x55,0},{0xB6,0xFF,0x55,0},{0xDB,0xFF,0x55,0},{0xFF,0xFF,0x55,0},
    {0x00,0x00,0xAA,0},{0x24,0x00,0xAA,0},{0x49,0x00,0xAA,0},{0x6D,0x00,0xAA,0},
    {0x92,0x00,0xAA,0},{0xB6,0x00,0xAA,0},{0xDB,0x00,0xAA,0},{0xFF,0x00,0xAA,0},
    {0x00,0x24,0xAA,0},{0x24,0x24,0xAA,0},{0x49,0x24,0xAA,0},{0x6D,0x24,0xAA,0},
    {0x92,0x24,0xAA,0},{0xB6,0x24,0xAA,0},{0xDB,0x24,0xAA,0},{0xFF,0x24,0xAA,0},
    {0x00,0x49,0xAA,0},{0x24,0x49,0xAA,0},{0x49,0x49,0xAA,0},{0x6D,0x49,0xAA,0},
    {0x92,0x49,0xAA,0},{0xB6,0x49,0xAA,0},{0xDB,0x49,0xAA,0},{0xFF,0x49,0xAA,0},
    {0x00,0x6D,0xAA,0},{0x24,0x6D,0xAA,0},{0x49,0x6D,0xAA,0},{0x6D,0x6D,0xAA,0},
    {0x92,0x6D,0xAA,0},{0xB6,0x6D,0xAA,0},{0xDB,0x6D,0xAA,0},{0xFF,0x6D,0xAA,0},
    {0x00,0x92,0xAA,0},{0x24,0x92,0xAA,0},{0x49,0x92,0xAA,0},{0x6D,0x92,0xAA,0},
    {0x92,0x92,0xAA,0},{0xB6,0x92,0xAA,0},{0xDB,0x92,0xAA,0},{0xFF,0x92,0xAA,0},
    {0x00,0xB6,0xAA,0},{0x24,0xB6,0xAA,0},{0x49,0xB6,0xAA,0},{0x6D,0xB6,0xAA,0},
    {0x92,0xB6,0xAA,0},{0xB6,0xB6,0xAA,0},{0xDB,0xB6,0xAA,0},{0xFF,0xB6,0xAA,0},
    {0x00,0xDB,0xAA,0},{0x24,0xDB,0xAA,0},{0x49,0xDB,0xAA,0},{0x6D,0xDB,0xAA,0},
    {0x92,0xDB,0xAA,0},{0xB6,0xDB,0xAA,0},{0xDB,0xDB,0xAA,0},{0xFF,0xDB,0xAA,0},
    {0x00,0xFF,0xAA,0},{0x24,0xFF,0xAA,0},{0x49,0xFF,0xAA,0},{0x6D,0xFF,0xAA,0},
    {0x92,0xFF,0xAA,0},{0xB6,0xFF,0xAA,0},{0xDB,0xFF,0xAA,0},{0xFF,0xFF,0xAA,0},
    {0x00,0x00,0xFF,0},{0x24,0x00,0xFF,0},{0x49,0x00,0xFF,0},{0x6D,0x00,0xFF,0},
    {0x92,0x00,0xFF,0},{0xB6,0x00,0xFF,0},{0xDB,0x00,0xFF,0},{0xFF,0x00,0xFF,0},
    {0x00,0x24,0xFF,0},{0x24,0x24,0xFF,0},{0x49,0x24,0xFF,0},{0x6D,0x24,0xFF,0},
    {0x92,0x24,0xFF,0},{0xB6,0x24,0xFF,0},{0xDB,0x24,0xFF,0},{0xFF,0x24,0xFF,0},
    {0x00,0x49,0xFF,0},{0x24,0x49,0xFF,0},{0x49,0x49,0xFF,0},{0x6D,0x49,0xFF,0},
    {0x92,0x49,0xFF,0},{0xB6,0x49,0xFF,0},{0xDB,0x49,0xFF,0},{0xFF,0x49,0xFF,0},
    {0x00,0x6D,0xFF,0},{0x24,0x6D,0xFF,0},{0x49,0x6D,0xFF,0},{0x6D,0x6D,0xFF,0},
    {0x92,0x6D,0xFF,0},{0xB6,0x6D,0xFF,0},{0xDB,0x6D,0xFF,0},{0xFF,0x6D,0xFF,0},
    {0x00,0x92,0xFF,0},{0x24,0x92,0xFF,0},{0x49,0x92,0xFF,0},{0x6D,0x92,0xFF,0},
    {0x92,0x92,0xFF,0},{0xB6,0x92,0xFF,0},{0xDB,0x92,0xFF,0},{0xFF,0x92,0xFF,0},
    {0x00,0xB6,0xFF,0},{0x24,0xB6,0xFF,0},{0x49,0xB6,0xFF,0},{0x6D,0xB6,0xFF,0},
    {0x92,0xB6,0xFF,0},{0xB6,0xB6,0xFF,0},{0xDB,0xB6,0xFF,0},{0xFF,0xB6,0xFF,0},
    {0x00,0xDB,0xFF,0},{0x24,0xDB,0xFF,0},{0x49,0xDB,0xFF,0},{0x6D,0xDB,0xFF,0},
    {0x92,0xDB,0xFF,0},{0xB6,0xDB,0xFF,0},{0xDB,0xDB,0xFF,0},{0xFF,0xDB,0xFF,0},
    {0x00,0xFF,0xFF,0},{0x24,0xFF,0xFF,0},{0x49,0xFF,0xFF,0},{0x6D,0xFF,0xFF,0},
    {0x92,0xFF,0xFF,0},{0xB6,0xFF,0xFF,0},{0xDB,0xFF,0xFF,0},{0xFF,0xFF,0xFF,0}
};

const BmpPalEntry v2u_palette_y8[256] = {
    {0x00,0x00,0x00,0},{0x01,0x01,0x01,0},{0x02,0x02,0x02,0},{0x03,0x03,0x03,0},
    {0x04,0x04,0x04,0},{0x05,0x05,0x05,0},{0x06,0x06,0x06,0},{0x07,0x07,0x07,0},
    {0x08,0x08,0x08,0},{0x09,0x09,0x09,0},{0x0a,0x0a,0x0a,0},{0x0b,0x0b,0x0b,0},
    {0x0c,0x0c,0x0c,0},{0x0d,0x0d,0x0d,0},{0x0e,0x0e,0x0e,0},{0x0f,0x0f,0x0f,0},
    {0x10,0x10,0x10,0},{0x11,0x11,0x11,0},{0x12,0x12,0x12,0},{0x13,0x13,0x13,0},
    {0x14,0x14,0x14,0},{0x15,0x15,0x15,0},{0x16,0x16,0x16,0},{0x17,0x17,0x17,0},
    {0x18,0x18,0x18,0},{0x19,0x19,0x19,0},{0x1a,0x1a,0x1a,0},{0x1b,0x1b,0x1b,0},
    {0x1c,0x1c,0x1c,0},{0x1d,0x1d,0x1d,0},{0x1e,0x1e,0x1e,0},{0x1f,0x1f,0x1f,0},
    {0x20,0x20,0x20,0},{0x21,0x21,0x21,0},{0x22,0x22,0x22,0},{0x23,0x23,0x23,0},
    {0x24,0x24,0x24,0},{0x25,0x25,0x25,0},{0x26,0x26,0x26,0},{0x27,0x27,0x27,0},
    {0x28,0x28,0x28,0},{0x29,0x29,0x29,0},{0x2a,0x2a,0x2a,0},{0x2b,0x2b,0x2b,0},
    {0x2c,0x2c,0x2c,0},{0x2d,0x2d,0x2d,0},{0x2e,0x2e,0x2e,0},{0x2f,0x2f,0x2f,0},
    {0x30,0x30,0x30,0},{0x31,0x31,0x31,0},{0x32,0x32,0x32,0},{0x33,0x33,0x33,0},
    {0x34,0x34,0x34,0},{0x35,0x35,0x35,0},{0x36,0x36,0x36,0},{0x37,0x37,0x37,0},
    {0x38,0x38,0x38,0},{0x39,0x39,0x39,0},{0x3a,0x3a,0x3a,0},{0x3b,0x3b,0x3b,0},
    {0x3c,0x3c,0x3c,0},{0x3d,0x3d,0x3d,0},{0x3e,0x3e,0x3e,0},{0x3f,0x3f,0x3f,0},
    {0x40,0x40,0x40,0},{0x41,0x41,0x41,0},{0x42,0x42,0x42,0},{0x43,0x43,0x43,0},
    {0x44,0x44,0x44,0},{0x45,0x45,0x45,0},{0x46,0x46,0x46,0},{0x47,0x47,0x47,0},
    {0x48,0x48,0x48,0},{0x49,0x49,0x49,0},{0x4a,0x4a,0x4a,0},{0x4b,0x4b,0x4b,0},
    {0x4c,0x4c,0x4c,0},{0x4d,0x4d,0x4d,0},{0x4e,0x4e,0x4e,0},{0x4f,0x4f,0x4f,0},
    {0x50,0x50,0x50,0},{0x51,0x51,0x51,0},{0x52,0x52,0x52,0},{0x53,0x53,0x53,0},
    {0x54,0x54,0x54,0},{0x55,0x55,0x55,0},{0x56,0x56,0x56,0},{0x57,0x57,0x57,0},
    {0x58,0x58,0x58,0},{0x59,0x59,0x59,0},{0x5a,0x5a,0x5a,0},{0x5b,0x5b,0x5b,0},
    {0x5c,0x5c,0x5c,0},{0x5d,0x5d,0x5d,0},{0x5e,0x5e,0x5e,0},{0x5f,0x5f,0x5f,0},
    {0x60,0x60,0x60,0},{0x61,0x61,0x61,0},{0x62,0x62,0x62,0},{0x63,0x63,0x63,0},
    {0x64,0x64,0x64,0},{0x65,0x65,0x65,0},{0x66,0x66,0x66,0},{0x67,0x67,0x67,0},
    {0x68,0x68,0x68,0},{0x69,0x69,0x69,0},{0x6a,0x6a,0x6a,0},{0x6b,0x6b,0x6b,0},
    {0x6c,0x6c,0x6c,0},{0x6d,0x6d,0x6d,0},{0x6e,0x6e,0x6e,0},{0x6f,0x6f,0x6f,0},
    {0x70,0x70,0x70,0},{0x71,0x71,0x71,0},{0x72,0x72,0x72,0},{0x73,0x73,0x73,0},
    {0x74,0x74,0x74,0},{0x75,0x75,0x75,0},{0x76,0x76,0x76,0},{0x77,0x77,0x77,0},
    {0x78,0x78,0x78,0},{0x79,0x79,0x79,0},{0x7a,0x7a,0x7a,0},{0x7b,0x7b,0x7b,0},
    {0x7c,0x7c,0x7c,0},{0x7d,0x7d,0x7d,0},{0x7e,0x7e,0x7e,0},{0x7f,0x7f,0x7f,0},
    {0x80,0x80,0x80,0},{0x81,0x81,0x81,0},{0x82,0x82,0x82,0},{0x83,0x83,0x83,0},
    {0x84,0x84,0x84,0},{0x85,0x85,0x85,0},{0x86,0x86,0x86,0},{0x87,0x87,0x87,0},
    {0x88,0x88,0x88,0},{0x89,0x89,0x89,0},{0x8a,0x8a,0x8a,0},{0x8b,0x8b,0x8b,0},
    {0x8c,0x8c,0x8c,0},{0x8d,0x8d,0x8d,0},{0x8e,0x8e,0x8e,0},{0x8f,0x8f,0x8f,0},
    {0x90,0x90,0x90,0},{0x91,0x91,0x91,0},{0x92,0x92,0x92,0},{0x93,0x93,0x93,0},
    {0x94,0x94,0x94,0},{0x95,0x95,0x95,0},{0x96,0x96,0x96,0},{0x97,0x97,0x97,0},
    {0x98,0x98,0x98,0},{0x99,0x99,0x99,0},{0x9a,0x9a,0x9a,0},{0x9b,0x9b,0x9b,0},
    {0x9c,0x9c,0x9c,0},{0x9d,0x9d,0x9d,0},{0x9e,0x9e,0x9e,0},{0x9f,0x9f,0x9f,0},
    {0xa0,0xa0,0xa0,0},{0xa1,0xa1,0xa1,0},{0xa2,0xa2,0xa2,0},{0xa3,0xa3,0xa3,0},
    {0xa4,0xa4,0xa4,0},{0xa5,0xa5,0xa5,0},{0xa6,0xa6,0xa6,0},{0xa7,0xa7,0xa7,0},
    {0xa8,0xa8,0xa8,0},{0xa9,0xa9,0xa9,0},{0xaa,0xaa,0xaa,0},{0xab,0xab,0xab,0},
    {0xac,0xac,0xac,0},{0xad,0xad,0xad,0},{0xae,0xae,0xae,0},{0xaf,0xaf,0xaf,0},
    {0xb0,0xb0,0xb0,0},{0xb1,0xb1,0xb1,0},{0xb2,0xb2,0xb2,0},{0xb3,0xb3,0xb3,0},
    {0xb4,0xb4,0xb4,0},{0xb5,0xb5,0xb5,0},{0xb6,0xb6,0xb6,0},{0xb7,0xb7,0xb7,0},
    {0xb8,0xb8,0xb8,0},{0xb9,0xb9,0xb9,0},{0xba,0xba,0xba,0},{0xbb,0xbb,0xbb,0},
    {0xbc,0xbc,0xbc,0},{0xbd,0xbd,0xbd,0},{0xbe,0xbe,0xbe,0},{0xbf,0xbf,0xbf,0},
    {0xc0,0xc0,0xc0,0},{0xc1,0xc1,0xc1,0},{0xc2,0xc2,0xc2,0},{0xc3,0xc3,0xc3,0},
    {0xc4,0xc4,0xc4,0},{0xc5,0xc5,0xc5,0},{0xc6,0xc6,0xc6,0},{0xc7,0xc7,0xc7,0},
    {0xc8,0xc8,0xc8,0},{0xc9,0xc9,0xc9,0},{0xca,0xca,0xca,0},{0xcb,0xcb,0xcb,0},
    {0xcc,0xcc,0xcc,0},{0xcd,0xcd,0xcd,0},{0xce,0xce,0xce,0},{0xcf,0xcf,0xcf,0},
    {0xd0,0xd0,0xd0,0},{0xd1,0xd1,0xd1,0},{0xd2,0xd2,0xd2,0},{0xd3,0xd3,0xd3,0},
    {0xd4,0xd4,0xd4,0},{0xd5,0xd5,0xd5,0},{0xd6,0xd6,0xd6,0},{0xd7,0xd7,0xd7,0},
    {0xd8,0xd8,0xd8,0},{0xd9,0xd9,0xd9,0},{0xda,0xda,0xda,0},{0xdb,0xdb,0xdb,0},
    {0xdc,0xdc,0xdc,0},{0xdd,0xdd,0xdd,0},{0xde,0xde,0xde,0},{0xdf,0xdf,0xdf,0},
    {0xe0,0xe0,0xe0,0},{0xe1,0xe1,0xe1,0},{0xe2,0xe2,0xe2,0},{0xe3,0xe3,0xe3,0},
    {0xe4,0xe4,0xe4,0},{0xe5,0xe5,0xe5,0},{0xe6,0xe6,0xe6,0},{0xe7,0xe7,0xe7,0},
    {0xe8,0xe8,0xe8,0},{0xe9,0xe9,0xe9,0},{0xea,0xea,0xea,0},{0xeb,0xeb,0xeb,0},
    {0xec,0xec,0xec,0},{0xed,0xed,0xed,0},{0xee,0xee,0xee,0},{0xef,0xef,0xef,0},
    {0xf0,0xf0,0xf0,0},{0xf1,0xf1,0xf1,0},{0xf2,0xf2,0xf2,0},{0xf3,0xf3,0xf3,0},
    {0xf4,0xf4,0xf4,0},{0xf5,0xf5,0xf5,0},{0xf6,0xf6,0xf6,0},{0xf7,0xf7,0xf7,0},
    {0xf8,0xf8,0xf8,0},{0xf9,0xf9,0xf9,0},{0xfa,0xfa,0xfa,0},{0xfb,0xfb,0xfb,0},
    {0xfc,0xfc,0xfc,0},{0xfd,0xfd,0xfd,0},{0xfe,0xfe,0xfe,0},{0xff,0xff,0xff,0}
};

const V2U_UINT32 v2u_mask_bgr16[3] = {0x001F, 0x07E0, 0xF800};
const V2U_UINT32 v2u_mask_rgb16[3] = {0xF800, 0x07E0, 0x001F};