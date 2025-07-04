/*******************************************************************************
 * Size: 28 px
 * Bpp: 1
 * Opts: --bpp 1 --size 28 --no-compress --font Sono-Bold.ttf --range 32-126 --font Sono-Medium.ttf --range 32-126 --font Sono-Regular.ttf --range 32-126 --font Sono-SemiBold.ttf --range 32-126 --format lvgl -o sono_28.c
 ******************************************************************************/
#include <lvgl.h>

#ifndef SONO_28
#define SONO_28 1
#endif

#if SONO_28

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x60, 0x6,
    0xff, 0x60,

    /* U+0022 "\"" */
    0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0x42,

    /* U+0023 "#" */
    0x6, 0x18, 0xf, 0x3c, 0xf, 0x3c, 0xe, 0x3c,
    0xe, 0x38, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff,
    0x1e, 0x78, 0x1e, 0x78, 0x1e, 0x78, 0xff, 0xfe,
    0xff, 0xfe, 0xff, 0xfe, 0x1c, 0x70, 0x1c, 0x70,
    0x1c, 0x70, 0x1c, 0x70, 0x18, 0x60,

    /* U+0024 "$" */
    0x3, 0x80, 0xe, 0x0, 0x38, 0x7, 0xfe, 0x3f,
    0xf9, 0xe0, 0xe7, 0x80, 0x1f, 0x80, 0x3f, 0xe0,
    0x7f, 0xe0, 0x7f, 0xc0, 0x1f, 0x0, 0x3d, 0xe1,
    0xf7, 0xff, 0x8f, 0xfc, 0x7, 0xc0, 0xe, 0x0,
    0x38, 0x0,

    /* U+0025 "%" */
    0x78, 0xd, 0xfc, 0x3b, 0x18, 0xe6, 0x31, 0x8c,
    0x67, 0x1f, 0xcc, 0xe, 0x38, 0x0, 0xe0, 0x1,
    0x80, 0x7, 0x0, 0xc, 0x0, 0x38, 0x0, 0xe7,
    0xc1, 0x9f, 0xc7, 0x31, 0x8c, 0x63, 0x30, 0xc6,
    0xe1, 0xfd, 0x80, 0xf0,

    /* U+0026 "&" */
    0x7, 0xc0, 0x1f, 0xc0, 0x7f, 0xc0, 0xe3, 0x81,
    0xc7, 0x3, 0x8e, 0x3, 0xf8, 0x7, 0xe0, 0x1f,
    0x80, 0x7f, 0x19, 0xef, 0x3f, 0x8f, 0xef, 0xf,
    0xde, 0xf, 0xbe, 0x3e, 0x3f, 0xfe, 0x7f, 0xdc,
    0x3f, 0x18,

    /* U+0027 "'" */
    0xff, 0xff, 0xfa,

    /* U+0028 "(" */
    0xe, 0x3c, 0x79, 0xe3, 0xcf, 0x9e, 0x3c, 0x79,
    0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3,
    0xc3, 0xc7, 0x8f, 0x1e, 0x1e, 0x3c, 0x7c, 0x78,
    0x70, 0xe0,

    /* U+0029 ")" */
    0x70, 0x70, 0x78, 0x7c, 0x3c, 0x3c, 0x1e, 0x1e,
    0x1e, 0x1f, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf,
    0xf, 0xf, 0xf, 0x1e, 0x1e, 0x1e, 0x3e, 0x3c,
    0x3c, 0x78, 0x78, 0x70, 0x60,

    /* U+002A "*" */
    0x1c, 0xe, 0x3f, 0x7f, 0xf7, 0xf3, 0xfb, 0xff,
    0xbb, 0x1c, 0xe, 0x0,

    /* U+002B "+" */
    0xe, 0x1, 0xc0, 0x38, 0x7, 0xf, 0xff, 0xff,
    0xff, 0xf8, 0x70, 0xe, 0x1, 0xc0, 0x38, 0x0,

    /* U+002C "," */
    0x7b, 0xff, 0xff, 0xfd, 0xf1, 0x86, 0x31, 0x84,
    0x0,

    /* U+002D "-" */
    0xff, 0xff, 0xff, 0xe0,

    /* U+002E "." */
    0x7b, 0xff, 0xff, 0xfd, 0xe0,

    /* U+002F "/" */
    0x3, 0x81, 0xc0, 0xe0, 0xf0, 0x70, 0x38, 0x3c,
    0x1e, 0xe, 0x7, 0x7, 0x83, 0xc1, 0xc0, 0xe0,
    0xf0, 0x70, 0x38, 0x1c, 0x1e, 0xe, 0x7, 0x7,
    0x83, 0xc1, 0xc0, 0xe0, 0x0, 0x0,

    /* U+0030 "0" */
    0xf, 0xc0, 0x7f, 0x83, 0xff, 0x1f, 0x3e, 0x78,
    0x7b, 0xc0, 0xff, 0x3, 0xfd, 0xcf, 0xf7, 0x3f,
    0xdc, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3d, 0xe1,
    0xe7, 0xcf, 0x8f, 0xfc, 0x1f, 0xe0, 0x3f, 0x0,

    /* U+0031 "1" */
    0x7, 0x0, 0xf0, 0xff, 0xf, 0xf0, 0xef, 0x0,
    0xf0, 0xf, 0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf,
    0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0xf, 0xff,
    0xff, 0xff, 0xff,

    /* U+0032 "2" */
    0x1f, 0x81, 0xff, 0x3f, 0xf9, 0xe3, 0xee, 0xf,
    0x0, 0x78, 0x3, 0xc0, 0x3c, 0x1, 0xe0, 0x1e,
    0x1, 0xe0, 0x1f, 0x1, 0xe0, 0x1e, 0x1, 0xe0,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+0033 "3" */
    0xf, 0xc1, 0xff, 0x9f, 0xfe, 0xe1, 0xf2, 0x7,
    0x80, 0x3c, 0x3, 0xc0, 0xfc, 0xf, 0x80, 0x3f,
    0x0, 0x3c, 0x0, 0xf0, 0x7, 0xb0, 0x3f, 0xc3,
    0xef, 0xfe, 0x3f, 0xe0, 0xfc, 0x0,

    /* U+0034 "4" */
    0xc, 0x0, 0x70, 0x1, 0xce, 0xf, 0x3c, 0x3c,
    0xf0, 0xe3, 0xc7, 0x8f, 0x1c, 0x3c, 0x70, 0xf3,
    0xc3, 0xcf, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0x3,
    0xc0, 0xf, 0x0, 0x3c, 0x0, 0xf0, 0x1, 0x80,

    /* U+0035 "5" */
    0x3f, 0xf8, 0xff, 0xe3, 0xff, 0x9e, 0x0, 0x78,
    0x1, 0xe0, 0x7, 0xbe, 0x1f, 0xfc, 0x7f, 0xf9,
    0xe1, 0xf7, 0x3, 0xc0, 0xf, 0x0, 0x3c, 0x80,
    0xf7, 0x7, 0x9f, 0xfe, 0x7f, 0xf0, 0x7f, 0x0,

    /* U+0036 "6" */
    0x7, 0xe0, 0x7f, 0xc3, 0xff, 0x8f, 0xe, 0x78,
    0x1, 0xe0, 0xf, 0x3e, 0x3d, 0xfe, 0xff, 0xfb,
    0xe1, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3d, 0xc0,
    0xf7, 0x87, 0x8f, 0xfe, 0x3f, 0xf0, 0x3f, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0xff, 0xf0, 0xf, 0x1, 0xe0,
    0x3c, 0x3, 0xc0, 0x78, 0x7, 0x80, 0xf0, 0xf,
    0x0, 0xf0, 0x1e, 0x1, 0xe0, 0x1e, 0x1, 0xe0,
    0x1e, 0x0, 0xc0,

    /* U+0038 "8" */
    0x1f, 0xc1, 0xff, 0xc7, 0xff, 0x3e, 0x3e, 0xf0,
    0x7b, 0xc1, 0xe7, 0x8f, 0x8f, 0xfc, 0x1f, 0xe1,
    0xff, 0xe7, 0x87, 0xbc, 0xf, 0xf0, 0x3f, 0xc0,
    0xff, 0x87, 0xdf, 0xfe, 0x3f, 0xf0, 0x3f, 0x0,

    /* U+0039 "9" */
    0xf, 0xc0, 0xff, 0x87, 0xff, 0x3e, 0x1e, 0xf0,
    0x7b, 0xc0, 0xef, 0x3, 0xbc, 0x1e, 0xf8, 0xf9,
    0xff, 0xe3, 0xff, 0x87, 0xde, 0x0, 0x78, 0x3,
    0xc0, 0x3f, 0xf, 0xf8, 0x7f, 0xc0, 0xf8, 0x0,

    /* U+003A ":" */
    0x77, 0xff, 0xf7, 0x0, 0x0, 0x3, 0xbf, 0xff,
    0xb8,

    /* U+003B ";" */
    0x77, 0xff, 0xf7, 0x0, 0x0, 0x3, 0xbf, 0xff,
    0xbc, 0x46, 0x60, 0x0,

    /* U+003C "<" */
    0x0, 0xe0, 0x3c, 0x1f, 0x8f, 0xe7, 0xf1, 0xf8,
    0x3c, 0x7, 0x80, 0xfc, 0xf, 0xe0, 0x7f, 0x3,
    0xf0, 0x1e, 0x1, 0xc0,

    /* U+003D "=" */
    0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff,

    /* U+003E ">" */
    0xe0, 0x1e, 0x3, 0xf0, 0x3f, 0x81, 0xfc, 0xf,
    0xc0, 0x78, 0xf, 0x7, 0xe3, 0xf9, 0xfc, 0x7e,
    0xf, 0x1, 0xc0, 0x0,

    /* U+003F "?" */
    0xf, 0xc1, 0xff, 0x1f, 0xfc, 0xe1, 0xf6, 0x7,
    0x80, 0x3c, 0x1, 0xe0, 0x1e, 0x1, 0xe0, 0x1e,
    0x1, 0xe0, 0xe, 0x0, 0xf0, 0x3, 0x80, 0x0,
    0x0, 0x0, 0x6, 0x0, 0x78, 0x3, 0xc0, 0xc,
    0x0,

    /* U+0040 "@" */
    0x1, 0xf8, 0x7, 0xfe, 0x7, 0xff, 0x87, 0xc1,
    0xe3, 0x9e, 0x73, 0x9f, 0x9d, 0xcf, 0xcf, 0xce,
    0x67, 0xe6, 0x73, 0xf3, 0x31, 0xf9, 0x98, 0xfc,
    0xcc, 0x6e, 0x7e, 0x77, 0x1f, 0xf3, 0xce, 0x70,
    0xe0, 0x0, 0x7c, 0x0, 0x1f, 0xc0, 0x7, 0xe0,
    0x0, 0xf0, 0x0,

    /* U+0041 "A" */
    0x7, 0xc0, 0xf, 0x80, 0x3f, 0x80, 0x77, 0x0,
    0xee, 0x3, 0xde, 0x7, 0xbc, 0xe, 0x38, 0x3c,
    0x78, 0x78, 0xf0, 0xe0, 0xe3, 0xff, 0xe7, 0xff,
    0xcf, 0xff, 0xbc, 0x7, 0xf8, 0xf, 0xf0, 0x1f,
    0xc0, 0x1c,

    /* U+0042 "B" */
    0x7f, 0xc3, 0xff, 0xcf, 0xff, 0xbc, 0x3e, 0xf0,
    0x7b, 0xc1, 0xef, 0xf, 0xbf, 0xfc, 0xff, 0xc3,
    0xff, 0xcf, 0x7, 0xbc, 0xf, 0xf0, 0x3f, 0xc0,
    0xff, 0x7, 0xff, 0xfe, 0xff, 0xf9, 0xff, 0x80,

    /* U+0043 "C" */
    0x7, 0xe0, 0x3f, 0xf0, 0xff, 0xf3, 0xe1, 0xe7,
    0x81, 0xdf, 0x3, 0xbc, 0x0, 0x78, 0x0, 0xf0,
    0x1, 0xe0, 0x3, 0xc0, 0x7, 0x80, 0xf, 0x81,
    0xcf, 0x3, 0xdf, 0xf, 0x1f, 0xfe, 0x1f, 0xf8,
    0xf, 0xc0,

    /* U+0044 "D" */
    0x7f, 0x83, 0xff, 0x8f, 0xff, 0x3c, 0x3e, 0xf0,
    0x7b, 0xc1, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f,
    0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x7f, 0xc1,
    0xef, 0xf, 0xbf, 0xfc, 0xff, 0xe1, 0xfe, 0x0,

    /* U+0045 "E" */
    0x7f, 0xf7, 0xff, 0xff, 0xfd, 0xe0, 0xf, 0x0,
    0x78, 0x3, 0xc0, 0x1e, 0x0, 0xff, 0xe7, 0xff,
    0x3f, 0xf9, 0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0,
    0x1f, 0xfe, 0xff, 0xfb, 0xff, 0x80,

    /* U+0046 "F" */
    0x7f, 0xff, 0xff, 0xff, 0xff, 0x0, 0xf0, 0xf,
    0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0xfe, 0xff,
    0xef, 0xfe, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0x0,
    0xf0, 0x6, 0x0,

    /* U+0047 "G" */
    0x7, 0xe0, 0x3f, 0xf0, 0xff, 0xf3, 0xe1, 0xe7,
    0x81, 0x9f, 0x0, 0x3c, 0x0, 0x78, 0x0, 0xf0,
    0xfd, 0xe3, 0xff, 0xc3, 0xff, 0x80, 0xff, 0x81,
    0xef, 0x7, 0x9f, 0xf, 0x1f, 0xfc, 0x1f, 0xf0,
    0xf, 0xc0,

    /* U+0048 "H" */
    0x60, 0x1b, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0,
    0x3f, 0xc0, 0xff, 0x3, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f, 0xc0,
    0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3d, 0x80, 0x60,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x1e, 0x0, 0xf0,
    0x7, 0x80, 0x3c, 0x1, 0xe0, 0xf, 0x0, 0x78,
    0x3, 0xc0, 0x1e, 0x0, 0xf0, 0x7, 0x80, 0x3c,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0x0, 0x18, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0,
    0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0, 0x3c,
    0x0, 0xf7, 0x3, 0xdc, 0xf, 0x70, 0x3d, 0xe1,
    0xf7, 0x87, 0x9f, 0xfe, 0x3f, 0xf0, 0x3f, 0x0,

    /* U+004B "K" */
    0x60, 0x3f, 0x83, 0xfc, 0x3f, 0xe3, 0xef, 0x1e,
    0x79, 0xe3, 0xde, 0x1f, 0xe0, 0xfe, 0x7, 0xf8,
    0x3f, 0xc1, 0xef, 0xf, 0x3c, 0x79, 0xf3, 0xc7,
    0xde, 0x1f, 0xf0, 0x7b, 0x1, 0xc0,

    /* U+004C "L" */
    0x60, 0xf, 0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf,
    0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0x0, 0xf0,
    0xf, 0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0xfe,
    0xff, 0xf7, 0xfe,

    /* U+004D "M" */
    0x3c, 0x3c, 0x7c, 0x3c, 0x7e, 0x7e, 0x7e, 0x7e,
    0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0xfe,
    0x77, 0xee, 0x77, 0xee, 0xf7, 0xef, 0xf7, 0xef,
    0xf3, 0xcf, 0xf3, 0xcf, 0xf3, 0xcf, 0xf1, 0x8f,
    0xf0, 0xf, 0x60, 0x6,

    /* U+004E "N" */
    0x70, 0x1b, 0xe0, 0xff, 0xc3, 0xff, 0xf, 0xfe,
    0x3f, 0xf8, 0xff, 0xe3, 0xfd, 0xcf, 0xf7, 0x3f,
    0xce, 0xff, 0x3b, 0xfc, 0x7f, 0xf1, 0xff, 0xc3,
    0xff, 0xf, 0xfc, 0x1f, 0xf0, 0x7d, 0x80, 0xe0,

    /* U+004F "O" */
    0x7, 0xe0, 0x1f, 0xf8, 0x3f, 0xfc, 0x7c, 0x3e,
    0x78, 0x1e, 0xf8, 0x1f, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf8, 0x1f, 0x78, 0x1e, 0x7c, 0x3e, 0x3f, 0xfc,
    0x1f, 0xf8, 0x7, 0xe0,

    /* U+0050 "P" */
    0x7f, 0xc7, 0xff, 0x3f, 0xfd, 0xe1, 0xff, 0x7,
    0xf8, 0x3f, 0xc1, 0xfe, 0xf, 0xf0, 0xff, 0xff,
    0xbf, 0xf9, 0xff, 0x8f, 0x0, 0x78, 0x3, 0xc0,
    0x1e, 0x0, 0xf0, 0x3, 0x0, 0x0,

    /* U+0051 "Q" */
    0x7, 0xe0, 0x1f, 0xf8, 0x3f, 0xfc, 0x7c, 0x3e,
    0x78, 0x1e, 0xf8, 0x1f, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf8, 0x1f, 0x78, 0x1e, 0x7c, 0x3e, 0x3f, 0xfc,
    0x1f, 0xf8, 0x7, 0xe0, 0x0, 0xf0, 0x0, 0x7c,
    0x0, 0x3e, 0x0, 0x1e,

    /* U+0052 "R" */
    0x7f, 0xc7, 0xff, 0xbf, 0xfd, 0xe1, 0xff, 0x7,
    0xf8, 0x3f, 0xc1, 0xfe, 0x1f, 0xff, 0xf7, 0xff,
    0x3f, 0xf1, 0xe3, 0xcf, 0x1e, 0x78, 0x7b, 0xc3,
    0xde, 0xf, 0xf0, 0x7b, 0x1, 0xc0,

    /* U+0053 "S" */
    0x7, 0xe0, 0x3f, 0xf0, 0xff, 0xf3, 0xe1, 0xe7,
    0x81, 0xcf, 0x0, 0x1f, 0x0, 0x1f, 0xc0, 0x1f,
    0xf0, 0xf, 0xf8, 0x3, 0xf0, 0x1, 0xf6, 0x1,
    0xee, 0x3, 0xdf, 0xf, 0xbf, 0xfe, 0x3f, 0xf8,
    0x1f, 0xc0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3c, 0x0,
    0x78, 0x0, 0xf0, 0x1, 0xe0, 0x3, 0xc0, 0x7,
    0x80, 0xf, 0x0, 0x1e, 0x0, 0x3c, 0x0, 0x78,
    0x0, 0xf0, 0x1, 0xe0, 0x3, 0xc0, 0x7, 0x80,
    0x6, 0x0,

    /* U+0055 "U" */
    0x60, 0x1b, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0,
    0x3f, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f,
    0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f, 0xe1,
    0xf7, 0xcf, 0x9f, 0xfe, 0x3f, 0xf0, 0x3f, 0x0,

    /* U+0056 "V" */
    0xe0, 0xf, 0xe0, 0x3f, 0xc0, 0x7f, 0x80, 0xf7,
    0x83, 0xcf, 0x7, 0x9e, 0xf, 0x1c, 0x1c, 0x3c,
    0x78, 0x78, 0xf0, 0x71, 0xc0, 0xf7, 0x81, 0xef,
    0x1, 0xdc, 0x3, 0xb8, 0x7, 0xf0, 0x7, 0xc0,
    0xf, 0x80,

    /* U+0057 "W" */
    0x60, 0x6, 0xf0, 0xf, 0xf3, 0xcf, 0xf3, 0xcf,
    0xf3, 0xcf, 0xf7, 0xef, 0xf7, 0xef, 0xf7, 0xef,
    0x77, 0xef, 0x77, 0xee, 0x7f, 0x7e, 0x7e, 0x7e,
    0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
    0x3c, 0x3e, 0x3c, 0x3c,

    /* U+0058 "X" */
    0xe0, 0x1f, 0xc0, 0xff, 0x7, 0xde, 0x1e, 0x3c,
    0xf0, 0xf3, 0xc1, 0xfe, 0x3, 0xf0, 0xf, 0xc0,
    0x3f, 0x0, 0xfc, 0x7, 0xf8, 0x3f, 0xf0, 0xf3,
    0xc7, 0x87, 0xbe, 0x1f, 0xf0, 0x3f, 0x80, 0x70,

    /* U+0059 "Y" */
    0xe0, 0x1f, 0xc0, 0xff, 0x3, 0xde, 0x1e, 0x78,
    0x78, 0xf3, 0xc3, 0xcf, 0x7, 0xf8, 0xf, 0xc0,
    0x3f, 0x0, 0x78, 0x1, 0xe0, 0x7, 0x80, 0x1e,
    0x0, 0x78, 0x1, 0xe0, 0x7, 0x80, 0xc, 0x0,

    /* U+005A "Z" */
    0xff, 0xef, 0xff, 0xff, 0xf0, 0xf, 0x1, 0xe0,
    0x3c, 0x3, 0xc0, 0x78, 0xf, 0x0, 0xf0, 0x1e,
    0x3, 0xc0, 0x3c, 0x7, 0x80, 0xf0, 0xf, 0xff,
    0xff, 0xf7, 0xff,

    /* U+005B "[" */
    0x7f, 0x7f, 0xff, 0xde, 0xf, 0x7, 0x83, 0xc1,
    0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7, 0x83,
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3f, 0xdf, 0xe7,
    0xf0,

    /* U+005C "\\" */
    0xe0, 0x70, 0x38, 0x1e, 0x7, 0x3, 0x81, 0xe0,
    0xf0, 0x38, 0x1c, 0xf, 0x3, 0x81, 0xc0, 0xe0,
    0x78, 0x1c, 0xe, 0x7, 0x3, 0xc0, 0xe0, 0x70,
    0x38, 0x1e, 0x7, 0x3, 0x80, 0x80,

    /* U+005D "]" */
    0x7f, 0x9f, 0xf7, 0xfc, 0xf, 0x3, 0xc0, 0xf0,
    0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3,
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xf7, 0xff, 0xff, 0x7f, 0x80,

    /* U+005E "^" */
    0xf, 0x1, 0xf8, 0x1f, 0x83, 0xfc, 0x39, 0xc7,
    0x9e, 0x71, 0xef, 0xf, 0xf0, 0xfe, 0x7,

    /* U+005F "_" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+0060 "`" */
    0xe7, 0x9c, 0x60,

    /* U+0061 "a" */
    0x1f, 0xc0, 0xff, 0xe1, 0xff, 0xe1, 0x7, 0xc0,
    0x7, 0x83, 0xef, 0x1f, 0xfe, 0x7f, 0xfc, 0xf8,
    0xf9, 0xe0, 0xf3, 0xc3, 0xe7, 0xff, 0xf7, 0xff,
    0xe3, 0xc7, 0xc0,

    /* U+0062 "b" */
    0x60, 0x3, 0xc0, 0xf, 0x0, 0x3c, 0x0, 0xf0,
    0x3, 0xc0, 0xf, 0x0, 0x3c, 0x0, 0xf3, 0xc3,
    0xff, 0xcf, 0xff, 0xbe, 0x3e, 0xf0, 0x7f, 0xc0,
    0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f, 0xc1, 0xff,
    0x8f, 0xbf, 0xfe, 0xff, 0xf1, 0x9f, 0x0,

    /* U+0063 "c" */
    0xf, 0xc0, 0xff, 0x9f, 0xfc, 0xf8, 0xef, 0x82,
    0x78, 0x3, 0xc0, 0x1e, 0x0, 0xf0, 0x7, 0xc1,
    0x1f, 0x1c, 0xff, 0xe3, 0xff, 0x7, 0xe0,

    /* U+0064 "d" */
    0x0, 0x18, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0,
    0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0xf, 0x3c,
    0xff, 0xf7, 0xff, 0xdf, 0x1f, 0xf8, 0x3f, 0xc0,
    0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f, 0xe0, 0xf7,
    0xc7, 0xdf, 0xff, 0x3f, 0xfc, 0x3c, 0x60,

    /* U+0065 "e" */
    0xf, 0x81, 0xff, 0x1f, 0xfc, 0xf0, 0xef, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7, 0x80,
    0x1e, 0x1e, 0xff, 0xf3, 0xff, 0x7, 0xe0,

    /* U+0066 "f" */
    0x1, 0xf0, 0x1f, 0xe0, 0x7f, 0xc3, 0xe7, 0xf,
    0x1c, 0x3c, 0x20, 0xf0, 0x3, 0xc0, 0xff, 0xfb,
    0xff, 0xef, 0xff, 0x83, 0xc0, 0xf, 0x0, 0x3c,
    0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0, 0x3c, 0x0,
    0xf0, 0x3, 0xc0, 0xf, 0x0, 0x18, 0x0,

    /* U+0067 "g" */
    0xf, 0x18, 0xff, 0xf7, 0xff, 0xde, 0x1f, 0xf8,
    0x3f, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f,
    0xe0, 0xf7, 0xc7, 0xdf, 0xff, 0x3f, 0xfc, 0x3c,
    0xf0, 0x3, 0xc8, 0xf, 0x78, 0x3d, 0xe1, 0xe7,
    0xff, 0x8f, 0xfc, 0xf, 0xc0,

    /* U+0068 "h" */
    0x60, 0x7, 0x80, 0x3c, 0x1, 0xe0, 0xf, 0x0,
    0x78, 0x3, 0xc0, 0x1e, 0x0, 0xf3, 0xc7, 0xff,
    0xbf, 0xfd, 0xf1, 0xff, 0x7, 0xf8, 0x3f, 0xc1,
    0xfe, 0xf, 0xf0, 0x7f, 0x83, 0xfc, 0x1f, 0xe0,
    0xff, 0x7, 0xb0, 0x18,

    /* U+0069 "i" */
    0x7, 0x0, 0x7c, 0x3, 0xe0, 0x1f, 0x0, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x3, 0xfc,
    0x1f, 0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1e,
    0x0, 0xf0, 0x7, 0x80, 0x3c, 0x1, 0xe1, 0xff,
    0xff, 0xff, 0xff, 0xfc,

    /* U+006A "j" */
    0x0, 0x70, 0x7, 0xc0, 0x3e, 0x1, 0xf0, 0x7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf0, 0xff,
    0xc7, 0xfe, 0x0, 0xf0, 0x7, 0x80, 0x3c, 0x1,
    0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1e, 0x0,
    0xf0, 0x7, 0x80, 0x3c, 0x1, 0xee, 0xf, 0xf0,
    0x7b, 0xc7, 0x9f, 0xfc, 0x7f, 0xc0, 0xf8, 0x0,

    /* U+006B "k" */
    0x60, 0x7, 0x80, 0x3c, 0x1, 0xe0, 0xf, 0x0,
    0x78, 0x3, 0xc0, 0x1e, 0x0, 0xf0, 0x77, 0x87,
    0xbc, 0x7d, 0xe7, 0xcf, 0x7c, 0x7f, 0xc3, 0xfe,
    0x1f, 0xf8, 0xf9, 0xe7, 0x8f, 0x3c, 0x3d, 0xe1,
    0xff, 0x7, 0xb0, 0x1c,

    /* U+006C "l" */
    0x7f, 0x7, 0xfc, 0x1f, 0xe0, 0xf, 0x0, 0x78,
    0x3, 0xc0, 0x1e, 0x0, 0xf0, 0x7, 0x80, 0x3c,
    0x1, 0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1e,
    0x0, 0xf0, 0x7, 0x80, 0x3c, 0x1, 0xe1, 0xff,
    0xff, 0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0x67, 0x9d, 0xff, 0xff, 0xff, 0xff, 0xde, 0xff,
    0x3d, 0xfe, 0x7b, 0xfc, 0xf7, 0xf9, 0xef, 0xf3,
    0xdf, 0xe7, 0xbf, 0xcf, 0x7f, 0x9e, 0xff, 0x3d,
    0xec, 0x79, 0x80,

    /* U+006E "n" */
    0x63, 0xe7, 0xbf, 0xbf, 0xfd, 0xf1, 0xff, 0x7,
    0xf8, 0x3f, 0xc1, 0xfe, 0xf, 0xf0, 0x7f, 0x83,
    0xfc, 0x1f, 0xe0, 0xff, 0x7, 0xb0, 0x18,

    /* U+006F "o" */
    0x7, 0xc0, 0x3f, 0xe0, 0xff, 0xe3, 0xe3, 0xef,
    0x83, 0xfe, 0x3, 0xfc, 0x7, 0xf8, 0xf, 0xf0,
    0x1f, 0xf0, 0x7d, 0xf1, 0xf1, 0xff, 0xc1, 0xff,
    0x0, 0xf8, 0x0,

    /* U+0070 "p" */
    0x63, 0xc3, 0xff, 0xcf, 0xff, 0xbe, 0x3e, 0xf0,
    0x7f, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f,
    0xc1, 0xff, 0x8f, 0xbf, 0xfe, 0xff, 0xf3, 0xcf,
    0xf, 0x0, 0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf,
    0x0, 0x3c, 0x0, 0x60, 0x0,

    /* U+0071 "q" */
    0xf, 0x18, 0xff, 0xf7, 0xff, 0xdf, 0x1f, 0xf8,
    0x3f, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f,
    0xe0, 0xf7, 0xc7, 0xdf, 0xff, 0x3f, 0xfc, 0x3c,
    0xf0, 0x3, 0xc0, 0xf, 0x0, 0x3c, 0x0, 0xf0,
    0x3, 0xc0, 0xf, 0x0, 0x18,

    /* U+0072 "r" */
    0x7c, 0x77, 0xff, 0xff, 0xfe, 0x3f, 0x71, 0xf0,
    0xf, 0x0, 0x78, 0x3, 0xc0, 0x1e, 0x0, 0xf0,
    0x7, 0x81, 0xff, 0x8f, 0xfc, 0x7f, 0xe0,

    /* U+0073 "s" */
    0xf, 0xe0, 0xff, 0xe7, 0xff, 0x9e, 0xe, 0x78,
    0x1, 0xf8, 0x3, 0xfe, 0x3, 0xfe, 0x0, 0x7c,
    0x0, 0xf7, 0x83, 0xdf, 0xff, 0x7f, 0xf8, 0x7f,
    0x80,

    /* U+0074 "t" */
    0x6, 0x0, 0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf,
    0x3, 0xff, 0xef, 0xff, 0xbf, 0xfe, 0xf, 0x0,
    0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0, 0x3c,
    0x30, 0xf1, 0xc3, 0xe7, 0xf, 0xfc, 0x1f, 0xe0,
    0x3e, 0x0,

    /* U+0075 "u" */
    0x60, 0x37, 0x83, 0xfc, 0x1f, 0xe0, 0xff, 0x7,
    0xf8, 0x3f, 0xc1, 0xfe, 0xf, 0xf0, 0x7f, 0x83,
    0xfe, 0x3e, 0xff, 0xf7, 0xff, 0x9f, 0x18,

    /* U+0076 "v" */
    0xe0, 0x7f, 0xf, 0xf0, 0xff, 0xf, 0x70, 0xe7,
    0x9e, 0x79, 0xe3, 0x9c, 0x39, 0xc3, 0xfc, 0x1f,
    0x81, 0xf8, 0x1f, 0x80, 0xf0,

    /* U+0077 "w" */
    0x60, 0xd, 0xe0, 0x3f, 0xce, 0x7f, 0x9c, 0xff,
    0x7d, 0xfe, 0xfb, 0xfd, 0xb7, 0xbb, 0x6e, 0x7e,
    0xfc, 0xfd, 0xf9, 0xfb, 0xf3, 0xe3, 0xe7, 0xc7,
    0xc7, 0x7, 0x0,

    /* U+0078 "x" */
    0xe0, 0x7f, 0xf, 0xf8, 0xf7, 0xde, 0x3f, 0xc1,
    0xf8, 0x1f, 0x80, 0xf8, 0x1f, 0xc3, 0xfc, 0x79,
    0xef, 0x9f, 0xf0, 0xfe, 0x7,

    /* U+0079 "y" */
    0x60, 0x3f, 0x83, 0xfc, 0x1f, 0xe0, 0xf7, 0x8f,
    0x3c, 0x79, 0xe3, 0xc7, 0xbc, 0x3d, 0xe1, 0xef,
    0x7, 0xf0, 0x3f, 0x81, 0xfc, 0x7, 0xc0, 0x1e,
    0x0, 0xf0, 0xf, 0x0, 0x78, 0x1f, 0x81, 0xfc,
    0x7, 0x80, 0x0,

    /* U+007A "z" */
    0xff, 0xdf, 0xff, 0xff, 0x81, 0xe0, 0x3c, 0xf,
    0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x1, 0xe0, 0x7f,
    0xff, 0xfe, 0xff, 0xc0,

    /* U+007B "{" */
    0x3, 0xc3, 0xf0, 0xfc, 0x7c, 0x1e, 0x7, 0x81,
    0xe0, 0x78, 0x1e, 0x7, 0x81, 0xe0, 0x78, 0x7e,
    0x3f, 0xf, 0xc1, 0xf8, 0x1e, 0x7, 0x81, 0xe0,
    0x78, 0x1e, 0x7, 0x81, 0xe0, 0x78, 0x1f, 0x3,
    0xf0, 0xfc, 0xf,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x80,

    /* U+007D "}" */
    0x78, 0x3f, 0x87, 0xe0, 0x7c, 0xf, 0x3, 0xc0,
    0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf,
    0x81, 0xf0, 0x7c, 0x3e, 0xf, 0x3, 0xc0, 0xf0,
    0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c, 0x1f, 0x1f,
    0x8f, 0xe1, 0xe0,

    /* U+007E "~" */
    0x71, 0xff, 0x8e
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 277, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 277, .box_w = 4, .box_h = 19, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 277, .box_w = 8, .box_h = 8, .ofs_x = 5, .ofs_y = 11},
    {.bitmap_index = 19, .adv_w = 277, .box_w = 16, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 277, .box_w = 14, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 277, .box_w = 15, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 277, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 277, .box_w = 3, .box_h = 8, .ofs_x = 6, .ofs_y = 11},
    {.bitmap_index = 164, .adv_w = 277, .box_w = 7, .box_h = 29, .ofs_x = 5, .ofs_y = -7},
    {.bitmap_index = 190, .adv_w = 277, .box_w = 8, .box_h = 29, .ofs_x = 4, .ofs_y = -7},
    {.bitmap_index = 219, .adv_w = 277, .box_w = 9, .box_h = 10, .ofs_x = 4, .ofs_y = 13},
    {.bitmap_index = 231, .adv_w = 277, .box_w = 11, .box_h = 11, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 247, .adv_w = 277, .box_w = 6, .box_h = 11, .ofs_x = 4, .ofs_y = -5},
    {.bitmap_index = 256, .adv_w = 277, .box_w = 9, .box_h = 3, .ofs_x = 4, .ofs_y = 7},
    {.bitmap_index = 260, .adv_w = 277, .box_w = 6, .box_h = 6, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 277, .box_w = 9, .box_h = 26, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 295, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 277, .box_w = 12, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 277, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 277, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 277, .box_w = 12, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 277, .box_w = 5, .box_h = 14, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 277, .box_w = 5, .box_h = 18, .ofs_x = 5, .ofs_y = -4},
    {.bitmap_index = 622, .adv_w = 277, .box_w = 11, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 277, .box_w = 11, .box_h = 8, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 653, .adv_w = 277, .box_w = 11, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 277, .box_w = 13, .box_h = 20, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 277, .box_w = 17, .box_h = 20, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 749, .adv_w = 277, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 783, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 277, .box_w = 15, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 849, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 277, .box_w = 13, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 277, .box_w = 12, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 938, .adv_w = 277, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 972, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1004, .adv_w = 277, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1034, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1066, .adv_w = 277, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1096, .adv_w = 277, .box_w = 12, .box_h = 18, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1123, .adv_w = 277, .box_w = 16, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1159, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1191, .adv_w = 277, .box_w = 16, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1227, .adv_w = 277, .box_w = 13, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1257, .adv_w = 277, .box_w = 16, .box_h = 22, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1301, .adv_w = 277, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1331, .adv_w = 277, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1365, .adv_w = 277, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1399, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1431, .adv_w = 277, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1465, .adv_w = 277, .box_w = 16, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1501, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1533, .adv_w = 277, .box_w = 14, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1565, .adv_w = 277, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1592, .adv_w = 277, .box_w = 9, .box_h = 29, .ofs_x = 5, .ofs_y = -7},
    {.bitmap_index = 1625, .adv_w = 277, .box_w = 9, .box_h = 26, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 1655, .adv_w = 277, .box_w = 10, .box_h = 29, .ofs_x = 3, .ofs_y = -7},
    {.bitmap_index = 1692, .adv_w = 277, .box_w = 12, .box_h = 10, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 1707, .adv_w = 277, .box_w = 18, .box_h = 3, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1714, .adv_w = 277, .box_w = 5, .box_h = 4, .ofs_x = 6, .ofs_y = 16},
    {.bitmap_index = 1717, .adv_w = 277, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1744, .adv_w = 277, .box_w = 14, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1783, .adv_w = 277, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1806, .adv_w = 277, .box_w = 14, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1845, .adv_w = 277, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1868, .adv_w = 277, .box_w = 14, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1907, .adv_w = 277, .box_w = 14, .box_h = 21, .ofs_x = 2, .ofs_y = -7},
    {.bitmap_index = 1944, .adv_w = 277, .box_w = 13, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1980, .adv_w = 277, .box_w = 13, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2016, .adv_w = 277, .box_w = 13, .box_h = 29, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 2064, .adv_w = 277, .box_w = 13, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2100, .adv_w = 277, .box_w = 13, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2136, .adv_w = 277, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2163, .adv_w = 277, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2186, .adv_w = 277, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2213, .adv_w = 277, .box_w = 14, .box_h = 21, .ofs_x = 2, .ofs_y = -7},
    {.bitmap_index = 2250, .adv_w = 277, .box_w = 14, .box_h = 21, .ofs_x = 1, .ofs_y = -7},
    {.bitmap_index = 2287, .adv_w = 277, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2310, .adv_w = 277, .box_w = 14, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2335, .adv_w = 277, .box_w = 14, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2369, .adv_w = 277, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2392, .adv_w = 277, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2413, .adv_w = 277, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2440, .adv_w = 277, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2461, .adv_w = 277, .box_w = 13, .box_h = 21, .ofs_x = 2, .ofs_y = -7},
    {.bitmap_index = 2496, .adv_w = 277, .box_w = 11, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2516, .adv_w = 277, .box_w = 10, .box_h = 28, .ofs_x = 4, .ofs_y = -6},
    {.bitmap_index = 2551, .adv_w = 277, .box_w = 3, .box_h = 27, .ofs_x = 6, .ofs_y = -5},
    {.bitmap_index = 2562, .adv_w = 277, .box_w = 10, .box_h = 28, .ofs_x = 3, .ofs_y = -6},
    {.bitmap_index = 2597, .adv_w = 277, .box_w = 8, .box_h = 3, .ofs_x = 5, .ofs_y = 15}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    89, 68,
    89, 69,
    89, 70,
    89, 72,
    89, 80,
    89, 82
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    0, 0, 0, 0, 0, 0
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 6,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t sono_28 = {
#else
lv_font_t sono_28 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 30,          /*The maximum line height required by the font*/
    .base_line = 7,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if SONO_28*/

