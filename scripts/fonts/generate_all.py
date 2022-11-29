#!/usr/bin/env python3

"""
https://unicode-table.com/

0x41-0x5A A-Z
0x61-0x7A a-z
0x30-0x39 0-9
0x20 space
0x25 %
0x3F ?
0x5F _
0x3A :

"""


import os
from pathlib import Path

common_settings = "--bpp 1 --compressed"

os.chdir(Path(__file__).resolve().parent)
os.system('rm out/lv_font_*')

print("\nGenerating 14 px")
cmd = "./built_in_font_gen.py --size 14 -o out/lv_font_montserrat_14_custom.c {} --range 0x41-0x5A,0x61-0x7A,0x30-0x39,0x20,0x25,0x3F,0x5F,0x3A --icons 61523".format(common_settings)
os.system(cmd)

print("\nGenerating 48 px")
cmd = "./built_in_font_gen.py --size 48 -o out/lv_font_montserrat_48_custom.c {} --range 0x30-0x39,0x20".format(common_settings)
os.system(cmd)

os.system('gsed -i \'s|#include "lvgl/lvgl.h"|#include "../../lvgl/lvgl.h"|\' out/lv_font_*.c')
os.system('astyle --ignore-exclude-errors --options=./code-format.cfg "out/lv_font_*.c"')
os.system('cp out/lv_font_*.c ../../Core/src/fonts')
