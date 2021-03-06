/*******************************************************************************
 * Size: 32 px
 * Bpp: 4
 * Opts: --no-compress --format lvgl --font C:\Users\YAO\Desktop\simkai.ttf -o C:\Users\YAO\Desktop\my_font_32.c --bpp 4 --size 32 --symbols 小区停车管理系统V1.0
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MY_FONT_32
#define MY_FONT_32 1
#endif

#if MY_FONT_32

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002E "." */
    0x6, 0x60, 0x8f, 0xf9, 0xbf, 0xfb, 0x3e, 0xe4,

    /* U+0030 "0" */
    0x0, 0x0, 0x6c, 0xff, 0xb4, 0x0, 0x0, 0x0,
    0xc, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0xbf,
    0xfd, 0x77, 0xdf, 0xf6, 0x0, 0x6, 0xff, 0xb0,
    0x0, 0xc, 0xfe, 0x10, 0xe, 0xfe, 0x10, 0x0,
    0x3, 0xff, 0x70, 0x4f, 0xf8, 0x0, 0x0, 0x0,
    0xcf, 0xc0, 0x8f, 0xf3, 0x0, 0x0, 0x0, 0x8f,
    0xf0, 0xaf, 0xf0, 0x0, 0x0, 0x0, 0x5f, 0xf1,
    0xcf, 0xd0, 0x0, 0x0, 0x0, 0x4f, 0xf3, 0xdf,
    0xb0, 0x0, 0x0, 0x0, 0x3f, 0xf5, 0xef, 0xb0,
    0x0, 0x0, 0x0, 0x2f, 0xf5, 0xef, 0xa0, 0x0,
    0x0, 0x0, 0x2f, 0xf5, 0xef, 0xa0, 0x0, 0x0,
    0x0, 0x2f, 0xf4, 0xdf, 0xc0, 0x0, 0x0, 0x0,
    0x3f, 0xf4, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0x5f,
    0xf2, 0x8f, 0xf1, 0x0, 0x0, 0x0, 0x8f, 0xf0,
    0x3f, 0xf6, 0x0, 0x0, 0x0, 0xcf, 0xc0, 0xe,
    0xfd, 0x0, 0x0, 0x2, 0xff, 0x80, 0x7, 0xff,
    0x80, 0x0, 0xc, 0xff, 0x20, 0x0, 0xdf, 0xfb,
    0x55, 0xdf, 0xf9, 0x0, 0x0, 0x2d, 0xff, 0xff,
    0xff, 0xb0, 0x0, 0x0, 0x0, 0x8e, 0xff, 0xe7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x22, 0x0, 0x0,
    0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x6, 0xf8, 0x0, 0x0, 0x3f, 0xf8,
    0x0, 0x3, 0xff, 0xf8, 0x0, 0x5f, 0xff, 0xf8,
    0x9, 0xff, 0x9f, 0xf8, 0x2f, 0xf6, 0xf, 0xf8,
    0x2c, 0x20, 0xf, 0xf8, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xf, 0xf8,

    /* U+0056 "V" */
    0x9f, 0xf6, 0x0, 0x0, 0x0, 0x0, 0xef, 0xf1,
    0x4f, 0xfa, 0x0, 0x0, 0x0, 0x2, 0xff, 0xc0,
    0xf, 0xfe, 0x0, 0x0, 0x0, 0x7, 0xff, 0x80,
    0xb, 0xff, 0x30, 0x0, 0x0, 0xb, 0xff, 0x30,
    0x6, 0xff, 0x80, 0x0, 0x0, 0xf, 0xfe, 0x0,
    0x1, 0xff, 0xc0, 0x0, 0x0, 0x4f, 0xf9, 0x0,
    0x0, 0xdf, 0xf1, 0x0, 0x0, 0x9f, 0xf5, 0x0,
    0x0, 0x8f, 0xf5, 0x0, 0x0, 0xdf, 0xf0, 0x0,
    0x0, 0x3f, 0xf9, 0x0, 0x1, 0xff, 0xb0, 0x0,
    0x0, 0xe, 0xfe, 0x0, 0x6, 0xff, 0x60, 0x0,
    0x0, 0xa, 0xff, 0x20, 0xa, 0xff, 0x10, 0x0,
    0x0, 0x5, 0xff, 0x70, 0xf, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xb0, 0x3f, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xf0, 0x8f, 0xf3, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xf4, 0xcf, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xfb, 0xff, 0xa0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0xff, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x8, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xfb, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xf7, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xf2, 0x0, 0x0, 0x0,

    /* U+505C "停" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x92, 0x0, 0x0, 0x0, 0x8f,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xff, 0x60, 0x0, 0x0, 0x6, 0xf9,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5, 0xff, 0x40, 0x0, 0x0, 0x0, 0x12, 0x3,
    0x78, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xfa, 0x0, 0x0, 0x0, 0x3, 0x7a, 0xef, 0xfe,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1,
    0x0, 0x4a, 0xce, 0xff, 0xc9, 0x64, 0x10, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0x70, 0x0,
    0x7, 0xa7, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x37, 0xcf, 0xb5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9, 0xf5, 0x0, 0x0, 0x0, 0xcc,
    0xa9, 0x74, 0x4f, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xe0, 0x0, 0x0, 0x0, 0x5f, 0x30,
    0x0, 0x2f, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xcd, 0xea, 0x0, 0x0, 0x0, 0xe, 0x60, 0x26,
    0xaf, 0x70, 0x0, 0x0, 0x0, 0x0, 0x6, 0xe2,
    0x9f, 0x0, 0x0, 0x0, 0x7, 0xc9, 0x86, 0x54,
    0x10, 0x24, 0x0, 0x0, 0x0, 0x2f, 0x40, 0x7f,
    0x0, 0x0, 0x0, 0x0, 0x20, 0x0, 0x15, 0x9e,
    0xff, 0xe5, 0x0, 0x1, 0xd4, 0x0, 0x7d, 0x0,
    0x3, 0x40, 0x2, 0x47, 0xae, 0xeb, 0x97, 0x5f,
    0xff, 0x70, 0xa, 0x30, 0x0, 0x8d, 0x0, 0xa,
    0xda, 0xa9, 0x75, 0x30, 0x0, 0x0, 0x2f, 0xfc,
    0x70, 0x21, 0x0, 0x0, 0x9c, 0x0, 0x3f, 0x50,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x97, 0x10, 0x0,
    0x0, 0x0, 0x0, 0xac, 0x0, 0xbf, 0x10, 0x0,
    0x0, 0x3, 0x7b, 0xc7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xbc, 0x0, 0xb8, 0x15, 0x67, 0x9c,
    0xff, 0xec, 0xa8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbc, 0x0, 0x0, 0xa, 0xfd, 0xa8, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xdc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xeb,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xfb, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xeb, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4, 0xfa, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xeb, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf7, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x62, 0x0, 0x0, 0x0, 0x2c, 0xdf,
    0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0,

    /* U+533A "区" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x26,
    0x9c, 0xc8, 0x0, 0x0, 0x3, 0x20, 0x0, 0x1,
    0x25, 0x79, 0xcf, 0xff, 0xff, 0xfd, 0x30, 0x0,
    0x9, 0xff, 0xee, 0xff, 0xff, 0xed, 0xba, 0x87,
    0x53, 0x0, 0x0, 0x0, 0x4, 0xfd, 0x43, 0x32,
    0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfd,
    0x30, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0x70, 0x0, 0x0, 0x0, 0x0, 0xeb, 0x0, 0x27,
    0x10, 0x0, 0x4, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xeb, 0x0, 0x5, 0xe7, 0x0, 0x9, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xeb, 0x0, 0x0,
    0x5f, 0xd3, 0xe, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xea, 0x0, 0x0, 0x4, 0xff, 0xaf, 0x90,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xea, 0x0, 0x0,
    0x0, 0x5f, 0xff, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xfa, 0x0, 0x0, 0x0, 0xc, 0xff, 0x90,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf9, 0x0, 0x0,
    0x0, 0x5f, 0xef, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf9, 0x0, 0x0, 0x1, 0xee, 0x26, 0xff,
    0x90, 0x0, 0x0, 0x0, 0x0, 0xf9, 0x0, 0x0,
    0xc, 0xf3, 0x0, 0x8f, 0xf6, 0x0, 0x0, 0x0,
    0x1, 0xf8, 0x0, 0x0, 0xae, 0x30, 0x0, 0xa,
    0xfe, 0x0, 0x0, 0x0, 0x1, 0xf8, 0x0, 0xa,
    0xc1, 0x0, 0x0, 0x0, 0xcf, 0x30, 0x0, 0x0,
    0x3, 0xf7, 0x1, 0xa6, 0x0, 0x0, 0x0, 0x0,
    0x1a, 0x10, 0x0, 0x0, 0x5, 0xf6, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8, 0xf6, 0x0, 0x0, 0x0, 0x1, 0x25, 0x79,
    0xac, 0xdd, 0xb7, 0x10, 0xd, 0xf8, 0x56, 0x89,
    0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1,
    0xf, 0xff, 0xff, 0xec, 0xb9, 0x87, 0x65, 0x43,
    0x33, 0x33, 0x45, 0x40, 0x9, 0xd7, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+5C0F "小" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1a, 0x60, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa, 0xfe, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xff, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xdf,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xce, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10,
    0x0, 0x0, 0x0, 0xbe, 0x0, 0x0, 0xa, 0x92,
    0x0, 0x0, 0x0, 0x0, 0xa1, 0x0, 0x0, 0x0,
    0xae, 0x0, 0x0, 0x2, 0xff, 0x91, 0x0, 0x0,
    0x2, 0xf2, 0x0, 0x0, 0x0, 0xae, 0x0, 0x0,
    0x0, 0x6f, 0xfd, 0x0, 0x0, 0xa, 0xf2, 0x0,
    0x0, 0x0, 0xae, 0x0, 0x0, 0x0, 0xa, 0xff,
    0xa0, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0x0, 0xaf,
    0x0, 0x0, 0x0, 0x1, 0xef, 0xf2, 0x0, 0xcf,
    0xb0, 0x0, 0x0, 0x0, 0xaf, 0x0, 0x0, 0x0,
    0x0, 0x5f, 0xf5, 0x6, 0xff, 0x50, 0x0, 0x0,
    0x0, 0xaf, 0x10, 0x0, 0x0, 0x0, 0xb, 0xf3,
    0xb, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xaf, 0x20,
    0x0, 0x0, 0x0, 0x1, 0x80, 0x8, 0xf3, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xdf, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x42, 0x1, 0xff, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xee, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xfb, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x90, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+7406 "理" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6d, 0xe9, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x58,
    0xcf, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x56, 0x16, 0xa9, 0xad, 0xff, 0xf6, 0x30,
    0x5, 0xff, 0xf9, 0x0, 0x0, 0x0, 0x15, 0xaf,
    0xff, 0x72, 0xff, 0x63, 0x14, 0xf9, 0x0, 0x1,
    0xff, 0xd0, 0x0, 0x0, 0x7, 0xff, 0xfc, 0x72,
    0x0, 0xcf, 0x10, 0x2, 0xfb, 0x0, 0x2, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x0, 0xad, 0x20, 0x0,
    0x8f, 0x30, 0x2, 0xf9, 0x33, 0x4, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x8f, 0x70, 0x0, 0x4f,
    0x40, 0x6, 0xff, 0xff, 0x27, 0xf9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0x40, 0x0, 0x1f, 0x65,
    0xef, 0xfd, 0x71, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0x30, 0x0, 0xe, 0x90, 0x2,
    0xf7, 0x0, 0xe, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6f, 0x7a, 0x90, 0xb, 0xb0, 0x2, 0xf6,
    0x0, 0x2f, 0x70, 0x0, 0x0, 0x0, 0x0, 0x27,
    0xdf, 0xfd, 0x50, 0x8, 0xd0, 0x2, 0xf9, 0x79,
    0xce, 0x10, 0x0, 0x0, 0x0, 0x7, 0xee, 0xdf,
    0x50, 0x0, 0x4, 0xf9, 0xce, 0xfd, 0x97, 0xc6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x10,
    0x0, 0x0, 0xe4, 0x22, 0xf5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x0, 0x0,
    0x0, 0x10, 0x2, 0xf5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xf4, 0x0, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0x0, 0x65, 0x0, 0x0,
    0x16, 0xfb, 0xdf, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0x9e, 0x60, 0x1, 0xce, 0xff,
    0xff, 0xda, 0x71, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4, 0xdf, 0xb1, 0x0, 0x0, 0x26, 0x66, 0xf3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xcf,
    0xe5, 0x0, 0x0, 0x0, 0x0, 0x2, 0xf3, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x9, 0xef, 0xfa, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xef, 0x60, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2, 0xf3, 0x35, 0x79, 0xbd,
    0xff, 0x90, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0,
    0x14, 0x69, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0xb, 0xdf, 0xff,
    0xfe, 0xc9, 0x75, 0x42, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0x89, 0x52, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+7BA1 "管" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x54, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0x60, 0x0, 0x0, 0x0, 0xbf, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xfc, 0x0, 0x0, 0x0, 0xee, 0x56, 0x9c, 0xd6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0xf7, 0x8c,
    0xf7, 0x5, 0xf8, 0xab, 0xb9, 0x61, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4f, 0xaa, 0xba, 0x82, 0xd,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xdb, 0x0, 0x0, 0x0, 0x7a, 0x5, 0x84,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xc0,
    0xcd, 0x30, 0x0, 0x60, 0x1, 0xdf, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1a, 0x0, 0x2e, 0xa4,
    0xa5, 0x0, 0x0, 0x1a, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x10, 0x0, 0x2, 0x40, 0xdf, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1c, 0x90, 0x0, 0x0,
    0x26, 0xaa, 0x20, 0x0, 0x0, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x44, 0x69, 0xcf, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x6d, 0x23, 0x45, 0x68, 0xab,
    0xcc, 0xa8, 0x64, 0x21, 0x0, 0xaf, 0xff, 0x80,
    0x0, 0xcf, 0xb9, 0x86, 0x53, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xa6, 0x20, 0x5, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x0,
    0x5, 0x81, 0x0, 0x0, 0xc, 0xf6, 0x0, 0x0,
    0x35, 0x22, 0x46, 0x9e, 0xfe, 0x60, 0x0, 0x0,
    0x0, 0x0, 0xa, 0xe0, 0x0, 0x0, 0x5f, 0xe9,
    0x75, 0x32, 0xaf, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x20, 0x0, 0x0, 0x1f, 0xa0, 0x0, 0x0,
    0x8f, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xa0, 0x0, 0x0, 0xc9, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xd9, 0xbc, 0xef, 0xec, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xb4,
    0x32, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0x80, 0x24, 0x7b, 0xff, 0xa1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xff, 0xdb, 0x97, 0x8f, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5f, 0x60, 0x0, 0x0,
    0x1f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0x50, 0x0, 0x3, 0x7f, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0xaa, 0xce, 0xff, 0xfd, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0x74,
    0x32, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5d, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+7CFB "系" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x71, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6e, 0xfe, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0x9e, 0xff, 0xfe, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x59, 0xef, 0xea,
    0x74, 0x10, 0x0, 0x0, 0x0, 0x2, 0x6a, 0xdf,
    0xfc, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6, 0x76, 0x42, 0x4, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2e, 0xf7,
    0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xec, 0x20, 0x0, 0xd, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3e, 0x90, 0x0, 0x0, 0xaf,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x7, 0xf5, 0x0,
    0x0, 0xa, 0xfe, 0x50, 0x0, 0x0, 0x0, 0x3,
    0xef, 0xfb, 0xbb, 0xbb, 0xdf, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xff, 0xc9, 0x64, 0x4d, 0xe4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x40, 0x0,
    0x5, 0xe9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xae, 0x40, 0x0, 0x2f, 0x91,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x90, 0x0,
    0x0, 0x9, 0xfe, 0x20, 0x0, 0x0, 0x4, 0x9f,
    0xfa, 0x68, 0x9b, 0xce, 0xda, 0xbf, 0xb0, 0x0,
    0x0, 0x6f, 0xff, 0xff, 0xfd, 0xe6, 0x30, 0x0,
    0xc, 0xc0, 0x0, 0x0, 0x6f, 0xc8, 0x52, 0x0,
    0xfc, 0x0, 0x0, 0x1, 0x30, 0x0, 0x0, 0x1,
    0x0, 0x0, 0x0, 0xcf, 0x20, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x80, 0x0,
    0x0, 0x9f, 0x0, 0x8, 0xb7, 0x20, 0x0, 0x0,
    0x1d, 0x90, 0x0, 0x0, 0x9f, 0x0, 0x1, 0xdf,
    0xf9, 0x0, 0x1, 0xcf, 0x40, 0x0, 0x0, 0x9f,
    0x10, 0x0, 0x1d, 0xff, 0x70, 0xb, 0xfd, 0x0,
    0x0, 0x0, 0x9f, 0x10, 0x0, 0x1, 0xcf, 0xd0,
    0xf, 0xf3, 0x0, 0x0, 0x0, 0xaf, 0x20, 0x0,
    0x0, 0x9, 0xa0, 0x6, 0x30, 0x0, 0x5, 0x54,
    0xef, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xcf, 0xff, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+7EDF "统" */
    0x0, 0x0, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x37, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xcd, 0x30, 0x0, 0x0, 0x0, 0x1e,
    0xfe, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xdf, 0x90, 0x0, 0x0, 0x0, 0x1, 0xcf,
    0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x41,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0xd0, 0x4,
    0x40, 0x0, 0x0, 0x2, 0x6a, 0xef, 0xfb, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0x30, 0xc, 0xf9,
    0x6, 0x9c, 0xff, 0xfe, 0xa6, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xe8, 0x0, 0x2f, 0xf6, 0x7,
    0xbb, 0xdf, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1c, 0xb0, 0x0, 0xbf, 0x30, 0x0, 0x0,
    0xaf, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xef, 0x55, 0x69, 0xf4, 0x0, 0x0, 0x0, 0xfb,
    0x4, 0x60, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff,
    0xfa, 0x7f, 0x60, 0x0, 0x0, 0x7, 0xe1, 0x2,
    0xfe, 0x40, 0x0, 0x0, 0x0, 0x1, 0x95, 0x0,
    0x9a, 0x0, 0x0, 0x0, 0x2f, 0x50, 0x0, 0x8f,
    0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xd0,
    0x0, 0x0, 0x4, 0xef, 0xbb, 0xdd, 0x99, 0xf7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x33, 0x7a,
    0x40, 0x5f, 0xff, 0xb5, 0xa9, 0x0, 0x62, 0x0,
    0x0, 0x0, 0x0, 0x5, 0xff, 0xff, 0x70, 0x0,
    0x4f, 0x7c, 0xf2, 0x6f, 0x60, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xc, 0xff, 0x81, 0x0, 0x0, 0x0,
    0xd, 0xf3, 0x5f, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xc2, 0x0, 0x0, 0x10, 0x0, 0x5f,
    0x80, 0x6f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3a, 0x70, 0x1, 0xed, 0x0,
    0x7d, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0,
    0x0, 0x3b, 0xd3, 0x0, 0xc, 0xf2, 0x0, 0x7b,
    0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x5c,
    0xf9, 0x0, 0x0, 0xaf, 0x40, 0x0, 0x7b, 0x0,
    0x0, 0x0, 0xb, 0x10, 0x4, 0xae, 0xfe, 0x40,
    0x0, 0xa, 0xf4, 0x0, 0x0, 0x7c, 0x0, 0x0,
    0x0, 0xf, 0x40, 0x3, 0xef, 0xa0, 0x0, 0x1,
    0xcc, 0x20, 0x0, 0x0, 0x5f, 0x30, 0x0, 0x0,
    0x9f, 0xa0, 0x0, 0x13, 0x0, 0x0, 0x3b, 0x50,
    0x0, 0x0, 0x0, 0x1f, 0xfa, 0x77, 0x8c, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xdf, 0xff, 0xff, 0xd8, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2, 0x45, 0x42, 0x0, 0x0,

    /* U+8F66 "车" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xc1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xe2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xe, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6, 0xf9, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xdf, 0x67,
    0x9b, 0xef, 0xff, 0xa0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0x78, 0xac, 0xef, 0xff, 0xff, 0xec, 0xa8,
    0x51, 0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0xcb,
    0x9f, 0xe5, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0xf5, 0x9,
    0x82, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xdb, 0x0, 0x7f, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0x20, 0x4, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0x80, 0x0,
    0x3f, 0x90, 0x13, 0x43, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4f, 0xf3, 0x24, 0x6a, 0xff, 0xff,
    0xff, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xff, 0xff, 0xef, 0xc8, 0x76, 0x54, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xec, 0x85, 0x31,
    0x3, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xf8, 0x0, 0x1, 0x34,
    0x65, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24,
    0x67, 0xaf, 0xed, 0xef, 0xff, 0xff, 0xff, 0x80,
    0x0, 0x89, 0x9a, 0xce, 0xff, 0xff, 0xed, 0xfc,
    0x77, 0x66, 0x66, 0x67, 0x87, 0x0, 0x4, 0xdf,
    0xfd, 0xb8, 0x63, 0x10, 0x3f, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xf5, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 256, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 8, .adv_w = 256, .box_w = 14, .box_h = 23, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 169, .adv_w = 256, .box_w = 8, .box_h = 21, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 253, .adv_w = 256, .box_w = 16, .box_h = 21, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 421, .adv_w = 512, .box_w = 30, .box_h = 29, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 856, .adv_w = 512, .box_w = 24, .box_h = 25, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 1156, .adv_w = 512, .box_w = 26, .box_h = 26, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 1494, .adv_w = 512, .box_w = 30, .box_h = 25, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1869, .adv_w = 512, .box_w = 28, .box_h = 31, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 2303, .adv_w = 512, .box_w = 22, .box_h = 30, .ofs_x = 5, .ofs_y = -4},
    {.bitmap_index = 2633, .adv_w = 512, .box_w = 30, .box_h = 25, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 3008, .adv_w = 512, .box_w = 27, .box_h = 30, .ofs_x = 3, .ofs_y = -4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x2, 0x3, 0x28, 0x502e, 0x530c, 0x5be1, 0x73d8,
    0x7b73, 0x7ccd, 0x7eb1, 0x8f38
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 46, .range_length = 36665, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 12, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t my_font_32 = {
#else
lv_font_t my_font_32 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 31,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MY_FONT_32*/

