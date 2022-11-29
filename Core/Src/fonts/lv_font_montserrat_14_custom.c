/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font Montserrat-Medium.ttf -r 0x41-0x5A,0x61-0x7A,0x30-0x39,0x20,0x25,0x3f,0x5f,0x3a,0x5b,0x5d,0x2b,0x2d,0x2e,0xB0 --font fa-v6-solid-900.ttf -r 61926,61832,61829,61918,63231,61523,61459,61441 --format lvgl -o out/lv_font_montserrat_14_custom.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

#ifndef LV_FONT_MONTSERRAT_14_CUSTOM
    #define LV_FONT_MONTSERRAT_14_CUSTOM 1
#endif

#if LV_FONT_MONTSERRAT_14_CUSTOM

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0025 "%" */
    0x70, 0x91, 0x22, 0x24, 0x45, 0x7, 0x5c, 0xc,
    0x42, 0x88, 0x91, 0x12, 0x24, 0x38,

    /* U+002B "+" */
    0x10, 0x4f, 0xc4, 0x10, 0x40,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+0030 "0" */
    0x3c, 0x42, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc3,
    0x42, 0x3c,

    /* U+0031 "1" */
    0xe4, 0x92, 0x49, 0x24,

    /* U+0032 "2" */
    0x79, 0x18, 0x10, 0x20, 0xc3, 0x4, 0x10, 0x41,
    0xfc,

    /* U+0033 "3" */
    0xfc, 0x8, 0x20, 0xc3, 0xc1, 0xc0, 0x81, 0x87,
    0xf0,

    /* U+0034 "4" */
    0x4, 0x6, 0x6, 0x6, 0x6, 0x22, 0x13, 0xfe,
    0x4, 0x2, 0x1, 0x0,

    /* U+0035 "5" */
    0x7e, 0x81, 0x2, 0x7, 0xc0, 0xc0, 0x81, 0xc6,
    0xf8,

    /* U+0036 "6" */
    0x3e, 0x83, 0x4, 0xb, 0xd8, 0xe0, 0xc1, 0x46,
    0x78,

    /* U+0037 "7" */
    0xff, 0x82, 0x86, 0x4, 0xc, 0x8, 0x18, 0x10,
    0x30, 0x20,

    /* U+0038 "8" */
    0x3c, 0x42, 0x42, 0x42, 0x3c, 0xc3, 0x81, 0x81,
    0xc3, 0x3c,

    /* U+0039 "9" */
    0x79, 0x8a, 0xc, 0x1c, 0x6f, 0x40, 0x83, 0x5,
    0xf0,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003F "?" */
    0x7d, 0x8c, 0x8, 0x10, 0xc3, 0x4, 0x0, 0x10,
    0x20,

    /* U+0041 "A" */
    0xc, 0x3, 0x1, 0xa0, 0x48, 0x31, 0x8, 0x43,
    0xf9, 0x2, 0x40, 0xf0, 0x10,

    /* U+0042 "B" */
    0xfe, 0x83, 0x81, 0x83, 0xfe, 0x83, 0x81, 0x81,
    0x83, 0xfe,

    /* U+0043 "C" */
    0x1e, 0x30, 0x90, 0x10, 0x8, 0x4, 0x2, 0x0,
    0x80, 0x61, 0xf, 0x0,

    /* U+0044 "D" */
    0xfc, 0x41, 0xa0, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x2, 0x83, 0x7e, 0x0,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0xf, 0xd0, 0x20, 0x40, 0x81,
    0xfc,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x0,

    /* U+0047 "G" */
    0x1f, 0x30, 0xd0, 0x10, 0x8, 0x4, 0x6, 0x2,
    0x81, 0x60, 0x8f, 0x80,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81,
    0x81, 0x81,

    /* U+0049 "I" */
    0xff, 0xc0,

    /* U+004A "J" */
    0x7c, 0x10, 0x41, 0x4, 0x10, 0x41, 0x45, 0xe0,

    /* U+004B "K" */
    0x82, 0x86, 0x8c, 0x98, 0xb0, 0xf8, 0xc8, 0x8c,
    0x86, 0x83,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0x80, 0x70, 0x3c, 0xf, 0x87, 0xb3, 0x64, 0x99,
    0xe6, 0x31, 0x8c, 0x60, 0x10,

    /* U+004E "N" */
    0x81, 0xc1, 0xe1, 0xb1, 0x99, 0x99, 0x8d, 0x87,
    0x83, 0x81,

    /* U+004F "O" */
    0x1e, 0x18, 0x64, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x5, 0x2, 0x61, 0x87, 0x80,

    /* U+0050 "P" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x82, 0xfc, 0x80,
    0x80, 0x80,

    /* U+0051 "Q" */
    0x1e, 0xc, 0x31, 0x2, 0x40, 0x28, 0x5, 0x0,
    0xa0, 0x12, 0x4, 0x61, 0x87, 0xe0, 0x19, 0x1,
    0xe0,

    /* U+0052 "R" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x83, 0xfe, 0x86,
    0x82, 0x81,

    /* U+0053 "S" */
    0x7d, 0x82, 0x4, 0x7, 0x7, 0x81, 0x81, 0x86,
    0xf8,

    /* U+0054 "T" */
    0xff, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
    0x8, 0x8,

    /* U+0055 "U" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x42, 0x3c,

    /* U+0056 "V" */
    0xc0, 0xd0, 0x26, 0x19, 0x84, 0x21, 0xc, 0xc1,
    0x20, 0x78, 0xc, 0x3, 0x0,

    /* U+0057 "W" */
    0x41, 0x82, 0x83, 0xd, 0x8e, 0x19, 0x16, 0x22,
    0x24, 0xc6, 0xc9, 0x85, 0x1a, 0xa, 0x1c, 0x1c,
    0x38, 0x10, 0x60,

    /* U+0058 "X" */
    0x41, 0xb1, 0x8c, 0x83, 0x80, 0xc0, 0xe0, 0x58,
    0x64, 0x61, 0x20, 0xc0,

    /* U+0059 "Y" */
    0xc1, 0xa0, 0x88, 0x86, 0x41, 0x40, 0xe0, 0x20,
    0x10, 0x8, 0x4, 0x0,

    /* U+005A "Z" */
    0xff, 0x2, 0x6, 0xc, 0x18, 0x10, 0x30, 0x60,
    0x40, 0xff,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0xc0,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x93, 0xc0,

    /* U+005F "_" */
    0xfe,

    /* U+0061 "a" */
    0x7a, 0x10, 0x5f, 0x86, 0x18, 0xdf,

    /* U+0062 "b" */
    0x80, 0x80, 0x80, 0xbc, 0xc2, 0x81, 0x81, 0x81,
    0x81, 0xc2, 0xbc,

    /* U+0063 "c" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x11, 0x9e,

    /* U+0064 "d" */
    0x1, 0x1, 0x1, 0x3d, 0x43, 0x81, 0x81, 0x81,
    0x81, 0x43, 0x3d,

    /* U+0065 "e" */
    0x38, 0x8a, 0xf, 0xf8, 0x18, 0x11, 0x1e,

    /* U+0066 "f" */
    0x39, 0x4, 0x3e, 0x41, 0x4, 0x10, 0x41, 0x4,
    0x0,

    /* U+0067 "g" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,
    0x1, 0x42, 0x7c,

    /* U+0068 "h" */
    0x81, 0x2, 0x5, 0xec, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0x8,

    /* U+0069 "i" */
    0xdf, 0xe0,

    /* U+006A "j" */
    0x11, 0x1, 0x11, 0x11, 0x11, 0x11, 0x1e,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x29, 0x96, 0x3c, 0x68, 0x99,
    0x1a, 0x18,

    /* U+006C "l" */
    0xff, 0xe0,

    /* U+006D "m" */
    0xbc, 0xf6, 0x38, 0xe0, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x8, 0x30, 0x41,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1,

    /* U+006F "o" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+0070 "p" */
    0xbc, 0xc2, 0x81, 0x81, 0x81, 0x81, 0xc2, 0xbc,
    0x80, 0x80, 0x80,

    /* U+0071 "q" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,
    0x1, 0x1, 0x1,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88,

    /* U+0073 "s" */
    0x7e, 0x8, 0x3c, 0x3c, 0x18, 0x7e,

    /* U+0074 "t" */
    0x41, 0xf, 0x90, 0x41, 0x4, 0x10, 0x40, 0xf0,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x71, 0xbd,

    /* U+0076 "v" */
    0xc3, 0x42, 0x42, 0x64, 0x24, 0x3c, 0x18, 0x18,

    /* U+0077 "w" */
    0xc2, 0x12, 0x30, 0x91, 0x4c, 0xca, 0x42, 0x92,
    0x14, 0x70, 0xe3, 0x2, 0x18,

    /* U+0078 "x" */
    0x42, 0x64, 0x3c, 0x18, 0x18, 0x2c, 0x64, 0x42,

    /* U+0079 "y" */
    0xc3, 0x42, 0x42, 0x64, 0x24, 0x3c, 0x18, 0x18,
    0x10, 0x10, 0xe0,

    /* U+007A "z" */
    0xfc, 0x31, 0x84, 0x21, 0x8c, 0x3f,

    /* U+00B0 "°" */
    0x74, 0x63, 0x17, 0x0,

    /* U+F001 "" */
    0x0, 0x6, 0x0, 0x7c, 0xf, 0xf8, 0x7f, 0xf0,
    0xff, 0xe1, 0xf0, 0xc3, 0x1, 0x86, 0x3, 0xc,
    0x1e, 0x18, 0x7d, 0xf0, 0xfb, 0xe1, 0xf7, 0xc0,
    0xf, 0x0, 0x0,

    /* U+F013 "" */
    0x7, 0x0, 0xf0, 0x4f, 0x2f, 0xff, 0xff, 0xff,
    0x9f, 0x70, 0xe7, 0xe, 0xf9, 0xff, 0xff, 0xff,
    0xf4, 0xf2, 0xf, 0x0, 0x60,

    /* U+F053 "" */
    0x6, 0x1c, 0x71, 0xc7, 0x1c, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x30,

    /* U+F185 "" */
    0x18, 0xc0, 0xfe, 0x7, 0xf1, 0xf1, 0xff, 0x77,
    0xb7, 0xd9, 0xbe, 0xcd, 0xf6, 0xf7, 0x7f, 0xc7,
    0xc7, 0xf0, 0x3f, 0x81, 0x8c, 0x0,

    /* U+F188 "" */
    0x7, 0x80, 0x1e, 0x0, 0xfc, 0x18, 0x6, 0x3f,
    0xf0, 0x7f, 0x81, 0xfe, 0x3f, 0xff, 0xff, 0xfc,
    0x7f, 0x81, 0xfe, 0xf, 0xfc, 0x7f, 0xf9, 0x80,
    0x60,

    /* U+F1DE "" */
    0xe, 0x3, 0xef, 0xff, 0xbf, 0xc3, 0x80, 0x0,
    0xe0, 0x3, 0x8f, 0xfb, 0xff, 0xef, 0x0, 0xe0,
    0x70, 0xf, 0x7f, 0xfd, 0xff, 0x1c, 0x0,

    /* U+F1E6 "" */
    0x31, 0x86, 0x30, 0xc6, 0x0, 0xf, 0xff, 0xff,
    0xdf, 0xf3, 0xfe, 0x7f, 0xc7, 0xf0, 0x7c, 0x2,
    0x0, 0x40, 0x8, 0x0,

    /* U+F6FF "" */
    0x3, 0xf0, 0x1, 0x86, 0x0, 0x61, 0x80, 0x1f,
    0xe0, 0x3, 0xf0, 0x0, 0x30, 0xf, 0xff, 0xff,
    0xff, 0xff, 0x8, 0x4, 0x1f, 0xcf, 0xe6, 0x33,
    0x19, 0x8c, 0xc6, 0x7f, 0x3f, 0x9f, 0xcf, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 60, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 189, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 130, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 20, .adv_w = 86, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 21, .adv_w = 51, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 149, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 83, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 150, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 51, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 164, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 170, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 162, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 185, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 150, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 142, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 182, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 69, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 161, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 133, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 214, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 182, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 188, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 162, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 188, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 302, .adv_w = 163, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 131, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 177, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 159, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 252, .box_w = 15, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 145, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 147, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 407, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 413, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 419, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 420, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 455, .adv_w = 137, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 79, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 155, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 482, .adv_w = 153, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 62, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 64, .box_w = 4, .box_h = 14, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 501, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 62, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 237, .box_w = 13, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 142, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 552, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 563, .adv_w = 92, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 567, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 573, .adv_w = 93, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 581, .adv_w = 152, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 125, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 201, .box_w = 13, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 124, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 125, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 628, .adv_w = 117, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 94, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 638, .adv_w = 224, .box_w = 15, .box_h = 14, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 665, .adv_w = 224, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 686, .adv_w = 168, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 697, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 719, .adv_w = 224, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 744, .adv_w = 224, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 767, .adv_w = 168, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 787, .adv_w = 280, .box_w = 18, .box_h = 14, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 2, 0, 3, 4, 0,
    5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 0, 0, 0, 0, 16,
    0, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 0, 44, 0, 45
};

static const uint16_t unicode_list_2[] = {
    0x0, 0xef51, 0xef63, 0xefa3, 0xf0d5, 0xf0d8, 0xf12e, 0xf136,
    0xf64f
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {
        .range_start = 32, .range_length = 64, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 64, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 47,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 63056, .glyph_id_start = 73,
        .unicode_list = unicode_list_2, .glyph_id_ofs_list = NULL, .list_length = 9, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] = {
    0, 0, 1, 2, 2, 3, 4, 0,
    5, 6, 7, 8, 9, 10, 11, 4,
    12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 21, 22, 23, 24, 21, 21,
    17, 25, 26, 27, 28, 29, 22, 30,
    30, 31, 32, 33, 34, 35, 36, 37,
    38, 39, 40, 41, 42, 43, 37, 43,
    43, 44, 40, 37, 37, 38, 38, 45,
    46, 47, 48, 43, 49, 49, 50, 49,
    51, 52, 0, 0, 0, 0, 0, 0,
    0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] = {
    0, 0, 1, 2, 2, 3, 4, 5,
    6, 7, 8, 9, 4, 10, 11, 12,
    13, 14, 15, 16, 17, 16, 16, 16,
    17, 16, 16, 18, 16, 16, 16, 16,
    17, 16, 17, 16, 19, 20, 21, 22,
    22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 31, 31, 0, 31, 30, 32,
    33, 30, 30, 34, 34, 31, 34, 31,
    34, 35, 36, 37, 38, 38, 39, 38,
    40, 41, 0, 0, 0, 0, 0, 0,
    0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] = {
    -27, 4, 7, 0, -4, 2, 2, 7,
        4, -4, 4, 0, 0, -13, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        -6, -8, 1, -2, 2, -4, -3, -4,
        2, 0, -2, 0, 0, 0, -9, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, -14, -2, 0, -3, -3, 2,
        2, -2, 0, -3, 2, 0, 0, -12,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 2, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, -14, 0, 2, -3, 0, -1,
        -1, -2, 0, 0, -2, 0, 0, 0,
        -4, -2, 0, 0, -5, 0, -4, 0,
        -6, -7, -7, -4, 0, 0, -4, 0,
        0, 0, 0, -2, 0, 0, 2, 0,
        2, -2, 0, 1, 2, -2, 2, -1,
        0, 0, 0, -4, 0, -1, 0, 0,
        0, 0, 1, 0, 0, 3, 0, -2,
        0, -3, 0, -4, 0, 0, 0, 7,
        0, 0, -2, 0, 0, 0, 0, 0,
        -1, 1, -2, -2, 0, -2, 0, 0,
        0, 0, -1, -1, 0, -2, -3, 0,
        0, 0, 0, 1, 0, 0, 0, 0,
        -2, 0, -2, -2, -2, 0, 0, 0,
        0, 0, 0, 0, 0, -1, 0, 0,
        0, 0, -2, -3, 0, -3, -7, 2,
        4, 0, -6, -1, -3, 0, -1, -11,
        2, -2, 2, -12, 0, 0, 2, 1,
        -2, -12, 0, -12, -2, -19, -2, 0,
        0, 4, 6, 0, 3, 0, 0, 0,
        0, 0, 0, -4, -3, 0, -7, -2,
        0, 0, 0, 0, -1, -1, 0, -1,
        -3, 0, 0, 0, 0, 0, 0, 0,
        -2, 0, -2, 0, -2, -3, -2, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -2, -2, 0, -3,
        -4, 1, 2, 0, 0, 0, 0, 0,
        0, -2, 0, 0, 0, 0, 2, 0,
        0, 0, 0, -2, 0, -2, -2, -3,
        0, 0, 0, 0, 0, 0, 2, 0,
        -2, 0, 0, 0, 0, -2, -3, 0,
        -4, 1, -11, -12, -4, 2, 0, -2,
        -15, -4, 0, -4, 0, -4, 3, -14,
        0, -4, -6, -2, 0, 0, 1, -1,
        2, -2, 0, 0, -7, -9, 0, -11,
        -5, -5, -5, -7, -3, -6, 0, -4,
        -6, 1, -2, 0, 2, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -2,
        -1, 0, 0, -1, 0, -2, 0, -4,
        -5, -5, -1, 0, 0, 0, 0, 0,
        0, 0, -2, 0, 0, 0, 0, 1,
        -1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 2, 0, 0, 0,
        -2, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, -11, 0,
        0, 0, -3, -11, 0, 0, -2, 2,
        0, -6, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -4, 0, -4,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 2, 0, -4, 7,
        -2, -9, 0, 2, -3, 0, -11, -1,
        -3, 2, -16, 3, 0, -2, 3, 0,
        -8, -3, -8, -7, -9, 0, 0, 0,
        13, 0, 0, -1, 0, 0, 0, -1,
        -1, -2, -6, -7, 0, -21, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -2, 0, -1, -2, -3, 0, 0,
        0, -2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        -1, 3, -5, 2, -2, -1, -6, -2,
        0, -3, -2, -2, 0, -4, 0, -3,
        0, -1, -2, -1, -2, -4, -3, 0,
        0, 0, 2, -2, 0, -5, 0, 0,
        0, -4, 0, -4, 0, -4, -4, 2,
        0, 2, -4, 0, -2, -2, -3, 0,
        0, 0, 0, 0, 0, -7, -2, 0,
        0, -3, 0, -2, 0, -5, -6, -7,
        -2, 0, 0, -7, 0, 0, 0, 0,
        18, 0, 0, 1, 0, 0, -3, 0,
        2, 0, -4, 2, -3, 0, -2, -3,
        -7, -2, -2, -2, -1, -2, -3, 0,
        0, -1, 0, 0, 0, 0, -2, -2,
        -2, 0, 0, 0, 3, -2, 0, -2,
        0, 0, 0, -2, -3, -2, -2, -3,
        -2, 0, 0, 0, -2, -3, 3, 0,
        0, -11, -4, 2, -4, 2, 0, -2,
        -7, 0, -2, -3, -1, 1, 0, 0,
        -4, 0, 0, 0, 2, -4, -4, 0,
        -4, -2, -3, -2, -2, 0, -4, 1,
        -4, -4, 7, 0, 0, 2, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -2,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -3, 0, 0, 0, 0,
        -3, 0, 0, -2, -2, 0, 0, 0,
        -2, 0, 0, 0, 0, -1, 0, 0,
        0, 0, 0, -2, 0, 0, 0, -7,
        0, -5, 4, 0, -2, -11, 0, 0,
        -5, -2, 0, -9, -6, 0, -6, 0,
        -3, -10, -2, -9, -9, -11, 0, -6,
        2, 15, -3, 0, -5, -2, -1, -2,
        -4, -6, -4, -8, -9, -5, -2, 0,
        -2, 7, -5, -8, 0, 1, -7, 0,
        -11, -2, -2, 4, -21, 1, 0, -3,
        0, -2, -15, -3, -12, -2, -16, 0,
        0, 0, 13, 1, 0, -2, 0, 0,
        0, 0, -1, -2, -9, -2, 0, -15,
        0, -1, -6, 0, 0, -1, -3, -7,
        -2, 0, -2, 0, 0, 0, -10, -2,
        0, -7, 0, -7, -2, -4, -6, -2,
        -4, 0, -2, -7, -3, 0, -3, -4,
        -2, -4, 0, 1, 0, -2, -7, 0,
        4, 0, 2, -4, 0, -2, -2, -3,
        0, 0, 0, 0, 0, 0, -7, -2,
        0, 0, -3, 0, -2, 0, -5, -6,
        -7, -2, 0, 2, 9, 0, 0, 0,
        0, 18, 0, 0, 1, 0, 0, -3,
        0, 2, 0, 0, 0, 0, 0, 0,
        -2, -4, 0, 0, 0, 0, 0, -1,
        0, 0, 0, -2, 0, -2, 0, 0,
        -4, -2, 0, 0, 0, 4, -1, 0,
        0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 3, 0, 4, 4, 0, -2,
        0, -2, 2, 0, -2, 0, -2, -1,
        -4, 0, 0, 0, 0, 0, -2, 0,
        0, -3, -3, 0, 0, 0, -4, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        -2, -2, 0, -3, 0, -7, -7, -4,
        9, 4, 2, -19, -2, 4, -2, 0,
        -2, 2, -8, 0, -2, -2, -2, 2,
        -3, -2, -7, -2, 0, 0, 4, 0,
        -6, 0, -12, -3, 6, -3, -9, 1,
        -3, -7, -7, -2, 9, 0, -5, -8,
        -6, 7, 0, 1, -16, -2, 2, -4,
        -2, -5, 0, -8, -3, -5, -3, -3,
        -2, 0, 0, -5, -5, -2, 0, 5,
        -2, -12, 0, -12, -3, 0, -8, -13,
        -1, -7, -4, -7, -6, 6, 0, -4,
        0, -7, 2, 0, 0, -12, 0, -2,
        -5, -4, -2, -7, -7, -5, -6, 0,
        -3, -7, -2, -5, -4, -7, -2, 0,
        1, 11, -4, 0, -7, -2, 0, -2,
        -4, -5, -6, -6, -9, -3, -4, 0,
        -7, -8, -7, 7, -2, 1, -21, -4,
        4, -5, -4, -8, 0, -9, -3, -7,
        -2, -3, -2, -2, -5, -7, -1, 0,
        0, 6, -2, -15, 0, -13, -5, 5,
        -9, -15, -4, -8, -9, -11, -7, 4,
        0, -3, 4, -4, 4, 0, 0, -7,
        -1, 0, -1, 0, 1, 1, 0, 0,
        -2, 0, 0, 0, 0, 0, -2, 0,
        0, 0, 2, 7, 0, 0, -3, 0,
        0, 0, 0, -2, -2, -3, 0, 0,
        0, 0, -2, 0, 0, 4, 1, 1,
        -3, 0, 4, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 6, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -4, 0, 0,
        -4, -2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -6, 0, 2, -4, -2,
        7, 6, -6, 2, 0, 0, 2, 2,
        -3, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 6, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -6, 0, 0, 0,
        -5, -1, 0, 0, 0, -5, 0, -3,
        0, -11, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, -2, 0, 0, -4, -6, 2, -3,
        0, -6, -2, -5, 0, 0, -6, 0,
        -2, 0, -11, -2, 0, 0, 0, 0,
        -18, -4, -9, -2, -8, 0, 0, 0,
        -6, -1, 0, 0, 0, 0, 0, 0,
        0, 0, -3, -4, -2, -4, 0, -2,
        4, -2, -5, -2, -4, -4, 0, -3,
        -1, -2, 2, -6, 0, 0, -1, 0,
        0, -20, -2, -3, 0, -5, 0, -2,
        -2, 0, 0, -2, -2, 0, 0, 0,
        0, 2, 0, -2, -4, -2, 4, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 3, 0, 0, 0, 0, 0,
        -2, 2, 0, 0, -6, -2, -4, 0,
        0, -6, 0, -2, 0, -11, 0, 0,
        0, 0, 0, -22, 0, -4, -8, -11,
        0, 0, 0, -2, -3, 0, 0, 0,
        0, 0, 0, 0, 0, -2, -3, -1,
        -3, 4, -2, -2, 3, 11, 4, 5,
        -6, 3, 9, 3, 6, 5, 6, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 11, -4, -2, 0, -2,
        18, 10, 18, 0, 0, 0, 2, 0,
        0, 8, 0, 0, 0, 0, -2, 0,
        0, 0, 0, 0, 0, 0, 0, 3,
        0, 0, 0, 0, -4, -19, -3, -2,
        -9, -11, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -5, 2, -2, 2,
        4, 2, -7, 0, 0, -2, 2, 0,
        2, 0, 0, 0, 0, 0, -6, 0,
        -2, -2, -4, 0, -2, 0, 14, -2,
        0, -5, -2, 0, -2, -4, 0, -2,
        -6, -4, -3, 0, 0, 0, 0, 0,
        -2, 0, 0, 0, 0, 0, 0, 0,
        0, 3, 0, 0, 0, 0, -4, -19,
        -3, -2, -9, -11, 0, 0, 0, 0,
        0, 0, 0, 0, 11, 0, 0, 0,
        0, 0, 0, 0, 0, 0, -2, -2,
        1, -1, 1, -2, -6, 0, 5, 0,
        2, 1, 2, -9, -3, -5, 0, -4,
        -9, -4, -6, -9, -9, 0, -4, -3,
        -3, -2, -2, -3, -2, 0, -2, -1,
        3, 0, 3, -2, 0, 7, 0, 0,
        0, 0, -2, -2, -2, 0, 0, -6,
        0, -1, 0, -4, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -2, -2, 0, -3, 0,
        -2, 2, -4, -4, -2, 0, -6, -2,
        -5, -2, -3, 0, -4, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 7, 0, 0, -4, 0, 0,
        0, 0, -3, 0, -2, 0, 0, -1,
        0, -3, -7, 2, 2, 2, 0, -6,
        2, 3, 2, 7, 2, 7, -6, 0,
        -2, 0, -2, -9, 0, 0, -7, -6,
        0, 0, 0, -3, -4, 0, -3, 0,
        -3, 0, -2, 3, 0, -2, -7, -2,
        8, 0, -5, 0, -2, 2, 0, 0,
        -7, 0, -2, -1, 0, -2, 2, 0,
        0, -2, 0, -2, -9, -3, -5, 0,
        -7, 0, 0, 0, 8, -2, 0, -4,
        0, 1, 0, -2, 0, -2, -7, 0,
        -2, 2, 0, -3, 1, 0, -3, -2,
        0, -3, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 5, 0, 0,
        -2, 0, 0, 0, 0, 0, 0, -2,
        -2, 0, 0, 5, 0, -14, 1, 10,
        7, 4, -9, 2, 9, 0, 8, 0,
        4, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0
    };


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes = {
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 52,
    .right_class_cnt     = 41,
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
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 1,
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
const lv_font_t lv_font_montserrat_14_custom = {
#else
lv_font_t lv_font_montserrat_14_custom = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_FONT_MONTSERRAT_14_CUSTOM*/

