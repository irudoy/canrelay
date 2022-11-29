/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font Montserrat-Medium.ttf -r 0x41-0x5A,0x61-0x7A,0x30-0x39,0x20,0x25,0x3F,0x5F,0x3A --font FontAwesome5-Solid+Brands+Regular.woff -r 61523 --format lvgl -o out/lv_font_montserrat_14_custom.c
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

    /* U+F053 "" */
    0x6, 0x1c, 0x71, 0xc7, 0x1c, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x30
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 60, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 189, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 149, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 83, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 150, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 51, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 164, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 170, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 162, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 185, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 150, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 142, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 182, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 69, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 161, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 133, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 214, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 182, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 188, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 162, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 188, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 295, .adv_w = 163, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 131, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 177, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 159, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 252, .box_w = 15, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 145, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 147, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 401, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 407, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 137, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 79, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 155, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 463, .adv_w = 153, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 62, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 64, .box_w = 4, .box_h = 14, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 482, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 62, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 237, .box_w = 13, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 142, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 533, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 544, .adv_w = 92, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 93, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 152, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 125, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 201, .box_w = 13, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 124, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 125, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 609, .adv_w = 117, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 140, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x5, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x1a, 0x1f
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {
        .range_start = 32, .range_length = 32, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 14, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 15,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 1, .glyph_id_start = 41,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 42,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 61523, .range_length = 1, .glyph_id_start = 68,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] = {
    0, 0, 1, 2, 0, 3, 4, 5,
    6, 7, 8, 9, 2, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 18, 18,
    19, 20, 21, 18, 18, 15, 22, 23,
    24, 25, 26, 19, 27, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37,
    38, 32, 38, 38, 39, 35, 32, 32,
    33, 33, 40, 41, 42, 43, 38, 44,
    44, 45, 44, 46, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] = {
    0, 0, 1, 2, 3, 4, 5, 6,
    7, 2, 8, 9, 10, 11, 12, 13,
    14, 15, 14, 14, 14, 15, 14, 14,
    16, 14, 14, 14, 14, 15, 14, 15,
    14, 17, 18, 19, 20, 20, 21, 22,
    23, 24, 25, 26, 27, 27, 27, 0,
    27, 26, 28, 29, 26, 26, 30, 30,
    27, 30, 27, 30, 31, 32, 33, 34,
    34, 35, 34, 36, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] = {
    -27, 0, -4, 2, 2, 7, 4, -4,
        4, 0, 0, -13, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, -1, -1,
        -2, 0, 0, -2, 0, 0, 0, -4,
        -2, 0, 0, -5, 0, -4, 0, -6,
        -7, -7, -4, -4, 0, 0, 0, 0,
        -2, 0, 0, 2, 0, 2, -2, 0,
        2, -1, 0, 0, 0, -4, 0, -1,
        0, 0, 0, 0, 1, 0, 0, 3,
        0, -2, 0, -3, 0, -4, 0, 7,
        0, 0, -2, 0, 0, 0, 0, 0,
        -1, 1, -2, -2, -2, 0, 0, -1,
        -1, 0, -2, -3, 0, 0, 0, 0,
        1, 0, 0, 0, 0, -2, 0, -2,
        -2, -2, 0, 0, 0, 0, 0, 0,
        -1, 0, 0, 0, 0, -2, -3, 0,
        -7, 0, -6, -1, -3, 0, -1, -11,
        2, -2, 2, -12, 0, 0, 2, 1,
        -2, -12, 0, -12, -2, -19, -2, 4,
        6, 0, 3, 0, 0, 0, 0, 0,
        0, -4, -3, 0, -2, 0, 0, -1,
        -1, 0, -1, -3, 0, 0, 0, 0,
        0, 0, 0, -2, 0, -2, 0, -2,
        -3, -2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -2, -2, 0,
        -4, 0, 0, 0, 0, 0, 0, -2,
        0, 0, 0, 0, 2, 0, 0, 0,
        0, -2, 0, -2, -2, -3, 0, 0,
        0, 0, 2, 0, -2, 0, 0, 0,
        0, -2, -3, 0, 1, -4, 2, 0,
        -2, -15, -4, 0, -4, 0, -4, 3,
        -14, 0, -4, -6, -2, 0, 0, 1,
        -1, 2, -2, -7, -9, 0, -11, -5,
        -5, -5, -7, -3, -6, 0, -4, -6,
        -2, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -2, -1, 0, 0, -1,
        0, -2, 0, -4, -5, -5, -1, 0,
        0, 0, 0, 0, -2, 0, 0, 0,
        0, 1, -1, 0, 0, 0, 0, 0,
        0, 0, 0, 2, 0, 0, 0, -2,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -3, -11, 0, 0,
        -2, 2, 0, -6, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -4,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -2, -9, 0,
        2, -3, 0, -11, -1, -3, 2, -16,
        3, 0, -2, 3, 0, -8, -3, -8,
        -7, -9, 0, 13, 0, 0, -1, 0,
        0, 0, -1, -1, -2, -6, -7, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -2, 0, -1, -2, -3, 0, -2,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -5, 2, -2,
        -1, -6, -2, 0, -3, -2, -2, 0,
        -4, 0, -3, 0, -1, -2, -1, -2,
        -4, -3, 0, 2, -2, 0, -5, 0,
        0, 0, -4, 0, -4, 0, -4, -4,
        0, 0, -2, -2, -3, 0, 0, 0,
        0, 0, 0, -7, -2, 0, 0, -3,
        0, -2, 0, -5, -6, -7, -2, -7,
        0, 0, 0, 0, 18, 0, 0, 1,
        0, 0, -3, 0, 0, -3, 0, -2,
        -3, -7, -2, -2, -2, -1, -2, -3,
        0, 0, -1, 0, 0, 0, 0, -2,
        -2, -2, 0, 3, -2, 0, -2, 0,
        0, 0, -2, -3, -2, -2, -3, -2,
        0, -3, 3, 0, 0, -11, -4, 2,
        -4, 2, 0, -2, -7, 0, -2, -3,
        -1, 1, 0, 0, -4, 0, 0, -4,
        -4, 0, -4, -2, -3, -2, -2, 0,
        -4, 1, -4, -4, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -2,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -3, 0, 0, 0,
        0, -3, 0, 0, -2, -2, 0, -2,
        0, 0, 0, 0, -1, 0, 0, 0,
        0, 0, -2, 0, 0, -5, 4, 0,
        -2, -11, 0, 0, -5, -2, 0, -9,
        -6, 0, -6, 0, -3, -10, -2, -9,
        -9, -11, 0, 15, -3, 0, -5, -2,
        -1, -2, -4, -6, -4, -8, -9, -5,
        0, -5, -8, 0, 1, -7, 0, -11,
        -2, -2, 4, -21, 1, 0, -3, 0,
        -2, -15, -3, -12, -2, -16, 0, 13,
        1, 0, -2, 0, 0, 0, 0, -1,
        -2, -9, -2, 0, 0, 0, 0, -1,
        -3, -7, -2, 0, -2, 0, 0, 0,
        -10, -2, 0, -7, 0, -7, -2, -4,
        -6, -2, -4, -7, -3, 0, -3, -4,
        -2, -4, 0, 1, 0, -2, -7, 0,
        0, 0, -2, -2, -3, 0, 0, 0,
        0, 0, 0, -7, -2, 0, 0, -3,
        0, -2, 0, -5, -6, -7, -2, 9,
        0, 0, 0, 0, 18, 0, 0, 1,
        0, 0, -3, 0, 0, 0, 0, 0,
        -2, -4, 0, 0, 0, 0, 0, -1,
        0, 0, 0, -2, 0, -2, 0, 0,
        -4, -2, 0, 4, -1, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, -2, 0, -2, 2, 0, -2,
        0, -2, -1, -4, 0, 0, 0, 0,
        0, -2, 0, 0, -3, -3, 0, -4,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -2, -2, 0, 0, -4, 9, 4,
        2, -19, -2, 4, -2, 0, -2, 2,
        -8, 0, -2, -2, -2, 2, -3, -2,
        -7, -2, 0, 0, -6, 0, -12, -3,
        6, -3, -9, 1, -3, -7, -7, -2,
        0, -6, 7, 0, 1, -16, -2, 2,
        -4, -2, -5, 0, -8, -3, -5, -3,
        -3, -2, 0, 0, -5, -5, -2, -2,
        -12, 0, -12, -3, 0, -8, -13, -1,
        -7, -4, -7, -6, 0, -7, 2, 0,
        0, -12, 0, -2, -5, -4, -2, -7,
        -7, -5, -6, 0, -3, -7, -2, -5,
        -4, -7, -2, 11, -4, 0, -7, -2,
        0, -2, -4, -5, -6, -6, -9, -3,
        0, -7, 7, -2, 1, -21, -4, 4,
        -5, -4, -8, 0, -9, -3, -7, -2,
        -3, -2, -2, -5, -7, -1, 0, -2,
        -15, 0, -13, -5, 5, -9, -15, -4,
        -8, -9, -11, -7, 0, -4, 4, 0,
        0, -7, -1, 0, -1, 0, 1, 1,
        0, 0, -2, 0, 0, 0, 0, 0,
        -2, 0, 0, 7, 0, 0, -3, 0,
        0, 0, 0, -2, -2, -3, 0, 0,
        -6, -4, -2, 7, 6, -6, 2, 0,
        0, 2, 2, -3, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -6, 0, -5, -1,
        0, 0, 0, -5, 0, -3, 0, -11,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, -2, 0, 0,
        -6, 0, -6, -2, -5, 0, 0, -6,
        0, -2, 0, -11, -2, 0, 0, 0,
        0, -18, -4, -9, -2, -8, 0, -6,
        -1, 0, 0, 0, 0, 0, 0, 0,
        0, -3, -4, -2, 0, -2, -5, -2,
        -4, -4, 0, -3, -1, -2, 2, -6,
        0, 0, -1, 0, 0, -20, -2, -3,
        0, -5, 0, 0, 0, -2, -2, 0,
        0, 0, 0, 2, 0, -2, -4, -2,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 3,
        0, 0, 0, 0, -2, 0, -6, -2,
        -4, 0, 0, -6, 0, -2, 0, -11,
        0, 0, 0, 0, 0, -22, 0, -4,
        -8, -11, 0, -2, -3, 0, 0, 0,
        0, 0, 0, 0, 0, -2, -3, -1,
        4, 3, 11, 4, 5, -6, 3, 9,
        3, 6, 5, 6, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -4,
        -2, 0, -2, 18, 10, 18, 0, 0,
        0, 2, 0, 0, 0, 0, -2, 0,
        0, 0, 0, 0, 0, 0, 0, 3,
        0, 0, 0, 0, -4, -19, -3, -2,
        -9, -11, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -2, 2, 4, 2, -7, 0, 0,
        -2, 2, 0, 2, 0, 0, 0, 0,
        0, -6, 0, -2, -2, -4, 0, 14,
        -2, 0, -5, -2, 0, -2, -4, 0,
        -2, -6, -4, -3, 0, 0, -2, 0,
        0, 0, 0, 0, 0, 0, 0, 3,
        0, 0, 0, 0, -4, -19, -3, -2,
        -9, -11, 0, 0, 0, 0, 0, 0,
        11, 0, 0, 0, 0, 0, 0, 0,
        0, 1, -1, 1, -2, -6, 0, 5,
        0, 2, 1, 2, -9, -3, -5, 0,
        -4, -9, -4, -6, -9, -9, 0, -3,
        -2, -2, -3, -2, 0, -2, -1, 3,
        0, 3, -2, 0, 0, 0, -2, -2,
        -2, 0, 0, -6, 0, -1, 0, -4,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -2, -2, 0,
        0, -4, -4, -2, 0, -6, -2, -5,
        -2, -3, 0, -4, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 7,
        0, 0, -4, 0, 0, 0, 0, -3,
        0, -2, 0, 0, 0, 2, 2, 2,
        0, -6, 2, 3, 2, 7, 2, 7,
        -6, 0, -2, 0, -2, -9, 0, 0,
        -7, -6, 0, -3, -4, 0, -3, 0,
        -3, 0, -2, 3, 0, -2, -7, -2,
        0, -2, 2, 0, 0, -7, 0, -2,
        -1, 0, -2, 2, 0, 0, -2, 0,
        -2, -9, -3, -5, 0, -7, 0, 8,
        -2, 0, -4, 0, 1, 0, -2, 0,
        -2, -7, 0, -2, 0, 0, -3, -2,
        0, -3, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 5, 0, 0, -2, 0,
        0, 0, 0, 0, 0, -2, -2, 0
    };


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes = {
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 46,
    .right_class_cnt     = 36,
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
    .cmap_num = 5,
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
    .line_height = 14,          /*The maximum line height required by the font*/
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

