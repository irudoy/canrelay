#!/usr/bin/env python3

import os
from pathlib import Path

# https://unicode-table.com/

def char_to_hex(s):
  return "0x" + s.encode().hex()

range_AZ = "0x41-0x5A"
range_az = "0x61-0x7A"
range_09 = "0x30-0x39"

chars_14 = [
  range_AZ,
  range_az,
  range_09,
  char_to_hex(" "),
  char_to_hex("%"),
  char_to_hex("?"),
  char_to_hex("_"),
  char_to_hex(":"),
  char_to_hex("["),
  char_to_hex("]"),
  "0xB0", # °
]

chars_36 = [
  range_09,
  char_to_hex(" "),
]

icons_14 = [
  "61926", # LV_CUSTOM_SYMBOL_PLUG
  "61832", # LV_CUSTOM_SYMBOL_BUG
  "61829", # LV_CUSTOM_SYMBOL_BRIGHTNESS

  "61523", # LV_SYMBOL_LEFT
  "61459", # LV_SYMBOL_SETTINGS
  "61441", # LV_SYMBOL_AUDIO
]

common_settings = "--bpp 1 --compressed"

os.chdir(Path(__file__).resolve().parent)
os.system('rm out/lv_font_*')

print("\nGenerating 14 px")
cmd = "./built_in_font_gen.py --size 14 -o out/lv_font_montserrat_14_custom.c {} --range {} --icons {}".format(common_settings, ",".join(chars_14), ",".join(icons_14))
os.system(cmd)

print("\nGenerating 36 px")
cmd = "./built_in_font_gen.py --size 36 -o out/lv_font_montserrat_36_custom.c {} --range {}".format(common_settings, ",".join(chars_36))
os.system(cmd)

os.system('gsed -i \'s|#include "lvgl/lvgl.h"|#include "../../lvgl/lvgl.h"|\' out/lv_font_*.c')
os.system('astyle --ignore-exclude-errors --options=./code-format.cfg "out/lv_font_*.c"')
os.system('cp out/lv_font_*.c ../../Core/src/fonts')
