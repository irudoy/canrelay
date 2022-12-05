#ifndef INC_UI_H_
#define INC_UI_H_

#define UI_COLOR_RED 0xfb3f62
#define UI_COLOR_YELLOW 0xfde218
#define UI_COLOR_BLUE 0x0a6eff
#define UI_COLOR_GRAY 0x6a6b70

// https://fontawesome.com/v6/icons/?o=r&m=free&s=solid
// https://onlinestringtools.com/convert-string-to-ascii Hexadecimal ASCII
#define LV_CUSTOM_SYMBOL_PLUG "\xEF\x87\xA6" /*61926, 0xF1E6*/
#define LV_CUSTOM_SYMBOL_BUG "\xEF\x86\x88" /*61832, 0xF188*/
#define LV_CUSTOM_SYMBOL_BRIGHTNESS "\xEF\x86\x85" /*61829, 0xF185*/
#define LV_CUSTOM_SYMBOL_SLIDERS "\xEF\x87\x9E" /*61918, 0xF1DE*/
#define LV_CUSTOM_SYMBOL_NETWORK_WIRED "\xEF\x9B\xBF" /*63231, 0xF6FF*/

void UI_Init();

#endif /* INC_UI_H_ */
