#!/usr/bin/env python3

import argparse
from argparse import RawTextHelpFormatter
import os
import sys

parser = argparse.ArgumentParser(description="""Create fonts for LVGL including the built-in symbols. lv_font_conv needs to be installed. See https://github.com/lvgl/lv_font_conv
Example: python built_in_font_gen.py --size 16 -o lv_font_roboto_16.c --bpp 4 -r 0x20-0x7F""", formatter_class=RawTextHelpFormatter)
parser.add_argument('-s', '--size',
					type=int,
					metavar = 'px',
					nargs='?',
					help='Size of the font in px')
parser.add_argument('--bpp',
					type=int,
					metavar = '1,2,4',
					nargs='?',
					help='Bit per pixel')
parser.add_argument('-r', '--range',
					nargs='+',
					metavar = 'start-end',
					default=['0x20-0x7F,0xB0,0x2022'],
					help='Ranges and/or characters to include. Default is 0x20-7F (ASCII). E.g. -r 0x20-0x7F, 0x200, 324')
parser.add_argument('--symbols',
					nargs='+',
					metavar = 'sym',
					default=[''],
					help=u'Symbols to include. E.g. -s ÁÉŐ'.encode('utf-8'))
parser.add_argument('--icons',
					nargs='+',
					metavar = 'syms',
					default=[''],
					help=u'Icons to include'.encode('utf-8'))
parser.add_argument('--font',
					metavar = 'file',
					nargs='?',
					default='Montserrat-Medium.ttf',
					help='A TTF or WOFF file')
parser.add_argument('-o', '--output',
					nargs='?',
					metavar='file',
					help='Output file name. E.g. my_font_20.c')
parser.add_argument('--compressed', action='store_true',
					help='Compress the bitmaps')
parser.add_argument('--subpx', action='store_true',
					help='3 times wider letters for sub pixel rendering')

args = parser.parse_args()

if args.compressed == False:
	compr = "--no-compress --no-prefilter"
else:
	compr = ""

if len(args.symbols[0]) != 0:
	args.symbols[0] = "--symbols " +  args.symbols[0]

subpx = ""
if args.subpx: subpx = "--lcd"

icons_cmd = ""
if len(args.icons[0]) != 0:
  if args.icons[0] == "all":
    icons_cmd = "--font FontAwesome5-Solid+Brands+Regular.woff -r 61441,61448,61451,61452,61452,61453,61457,61459,61461,61465,61468,61473,61478,61479,61480,61502,61507,61512,61515,61516,61517,61521,61522,61523,61524,61543,61544,61550,61552,61553,61556,61559,61560,61561,61563,61587,61589,61636,61637,61639,61641,61664,61671,61674,61683,61724,61732,61787,61931,62016,62017,62018,62019,62020,62087,62099,62212,62189,62810,63426,63650"
  else:
    icons_cmd = "--font FontAwesome5-Solid+Brands+Regular.woff -r {}".format(args.icons[0])

cmd = "npx lv_font_conv {} {} --bpp {} --size {} --font {} -r {} {} {} --format lvgl -o {}".format(subpx, compr, args.bpp, args.size, args.font, args.range[0], args.symbols[0], icons_cmd, args.output)

os.system(cmd)

"""

usage: lv_font_conv [-h] [-v] --size PIXELS [-o <path>] --bpp {1,2,3,4,8} [--lcd | --lcd-v] [--use-color-info] --format {dump,bin,lvgl} --font <path> [-r RANGE]
                    [--symbols SYMBOLS] [--autohint-off] [--autohint-strong] [--force-fast-kern-format] [--no-compress] [--no-prefilter] [--no-kerning]
                    [--lv-include <path>] [--full-info]

optional arguments:
  -h, --help            show this help message and exit
  -v, --version         show program's version number and exit
  --size PIXELS         Output font size, pixels.
  -o <path>, --output <path>
                        Output path.
  --bpp {1,2,3,4,8}     Bits per pixel, for antialiasing.
  --lcd                 Enable subpixel rendering (horizontal pixel layout).
  --lcd-v               Enable subpixel rendering (vertical pixel layout).
  --use-color-info      Try to use glyph color info from font to create grayscale icons. Since gray tones are emulated via transparency, result will be good on contrast
                        background only.
  --format {dump,bin,lvgl}
                        Output format.
  --font <path>         Source font path. Can be used multiple times to merge glyphs from different fonts.
  -r RANGE, --range RANGE
                        Range of glyphs to copy. Can be used multiple times, belongs to previously declared "--font". Examples:
                        -r 0x1F450
                        -r 0x20-0x7F
                        -r 32-127
                        -r 32-127,0x1F450
                        -r '0x1F450=>0xF005'
                        -r '0x1F450-0x1F470=>0xF005'
  --symbols SYMBOLS     List of characters to copy, belongs to previously declared "--font". Examples:
                        --symbols ,.0123456789
                        --symbols abcdefghigklmnopqrstuvwxyz
  --autohint-off        Disable autohinting for previously declared "--font"
  --autohint-strong     Use more strong autohinting for previously declared "--font" (will break kerning)
  --force-fast-kern-format
                        Always use kern classes instead of pairs (might be larger but faster).
  --no-compress         Disable built-in RLE compression.
  --no-prefilter        Disable bitmap lines filter (XOR), used to improve compression ratio.
  --no-kerning          Drop kerning info to reduce size (not recommended).
  --lv-include <path>   Set alternate "lvgl.h" path (for --format lvgl).
  --full-info           Don't shorten "font_info.json" (include pixels data).

  """
