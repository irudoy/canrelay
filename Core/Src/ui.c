#include "ui.h"
#include "settings.h"
#include "hw.h"
#include "comm.h"
#include "../../lvgl/lvgl.h"

#include <math.h>

extern int16_t HW_encoderDiff;
extern lv_indev_state_t HW_encoderBtnState;
extern canrelay_settings_t CRS_Settings;
extern uint8_t COMM_CANRxData[8];

static uint16_t prevCurrentDataRaw;
static lv_obj_t * currentValueLabel;
static lv_obj_t * page_settings;
static lv_indev_drv_t indev_drv;
static lv_indev_t * indev_encoder;

static void UI_RenderHomeScreen();
static void UI_RenderMenu();
static void UI_RenderDebugScreen();
static void UI_RenderDemoScreen();

static void encoderReadCallback(lv_indev_drv_t * drv, lv_indev_data_t * data) {
  LV_UNUSED(drv);
  data->enc_diff = HW_encoderDiff;
  data->state = HW_encoderBtnState;
  HW_encoderDiff = 0;
}

static void encoderFeedbackCallback(lv_indev_drv_t * drv, uint8_t event_code) {
  LV_UNUSED(drv);
  lv_event_code_t e = (lv_event_code_t) event_code;
  if (e == LV_EVENT_LONG_PRESSED || e == LV_EVENT_SHORT_CLICKED || e == LV_EVENT_FOCUSED) {
    HW_Buzz();
  }
}

static void showMenuHandler(lv_event_t * e) {
  LV_UNUSED(e);
  lv_indev_wait_release(indev_encoder);
  UI_RenderMenu();
}

static void UI_RenderDebugScreen() {
  lv_obj_clean(lv_scr_act());

  lv_obj_t * dummy = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(dummy, showMenuHandler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_flag(dummy, LV_OBJ_FLAG_HIDDEN);

  lv_obj_t * label1 = lv_label_create(lv_scr_act());
  lv_label_set_text(label1, "LCD_BR_DC: ?");
  lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, -15);

  lv_obj_t * label2 = lv_label_create(lv_scr_act());
  lv_label_set_text(label2, "ENC_VAL: ?");
  lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label2, LV_ALIGN_CENTER, 0, 15);
}

static void anim_x_cb(void * var, int32_t v) {
  lv_obj_set_x(var, (int16_t) v);
}

static void anim_size_cb(void * var, int32_t v) {
  lv_obj_set_size(var, (int16_t) v, (int16_t) v);
}

static void UI_RenderDemoScreen() {
  lv_obj_clean(lv_scr_act());

  lv_obj_t * dummy = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(dummy, showMenuHandler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_flag(dummy, LV_OBJ_FLAG_HIDDEN);

  lv_obj_t * obj = lv_obj_create(lv_scr_act());
  lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_CYAN), 0);
  lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);

  lv_obj_align(obj, LV_ALIGN_LEFT_MID, 5, 0);

  lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_set_var(&a, obj);
  lv_anim_set_values(&a, 10, 50);
  lv_anim_set_time(&a, 1000);
  lv_anim_set_playback_delay(&a, 100);
  lv_anim_set_playback_time(&a, 300);
  lv_anim_set_repeat_delay(&a, 100);
  lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
  lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);

  lv_anim_set_exec_cb(&a, anim_size_cb);
  lv_anim_start(&a);
  lv_anim_set_exec_cb(&a, anim_x_cb);
  lv_anim_set_values(&a, 100, 5);
  lv_anim_start(&a);
}

static lv_obj_t * createMenuItem(lv_obj_t * parent, const char * text, const char * icon) {
  lv_obj_t * obj = lv_menu_cont_create(parent);

  lv_obj_t * label = NULL;
  lv_obj_t * img = NULL;

  img = lv_img_create(obj);
  lv_img_set_src(img, icon);

  label = lv_label_create(obj);
  lv_label_set_text(label, text);
  lv_obj_set_flex_grow(label, 1);
  // lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);

  lv_group_add_obj(lv_group_get_default(), obj);

  return obj;
}

static void relaySwitchHandler(lv_event_t * e) {
  LV_UNUSED(e);
  HW_RelayToggle();
}

static void buzzerSwitchHandler(lv_event_t * e) {
  LV_UNUSED(e);
  CRS_Settings.buzzerEnabled = !CRS_Settings.buzzerEnabled;
}

static void brightnessSliderHandler(lv_event_t * e) {
  lv_obj_t * slider = lv_event_get_target(e);
  HW_LCDSetBrightness((uint8_t)lv_slider_get_value(slider));

  lv_obj_t * label = lv_obj_get_child(lv_obj_get_parent(slider), 1);
  lv_label_set_text_fmt(label, "%d%%", (uint8_t)lv_slider_get_value(slider));
}

static void debugBtnClickHandler(lv_event_t * e) {
  LV_UNUSED(e);
  UI_RenderDebugScreen();
}

static void demoBtnClickHandler(lv_event_t * e) {
  LV_UNUSED(e);
  UI_RenderDemoScreen();
}

static void menuBackBtnHandler(lv_event_t * e) {
  lv_obj_t * obj = lv_event_get_target(e);
  lv_obj_t * menu = lv_event_get_user_data(e);
  lv_obj_t * currPage = lv_menu_get_cur_main_page(menu);

  if (currPage == page_settings) {
    CRS_persistSettings();
  }

  if (lv_menu_back_btn_is_root(menu, obj)) {
    UI_RenderHomeScreen();
  }
}

static void targetValueSpinboxChangeHandler(lv_event_t * e) {
  lv_obj_t * spinbox = lv_event_get_target(e);
  CRS_Settings.targetValue = (int16_t) lv_spinbox_get_value(spinbox);
}

static void UI_RenderMenu() {
  lv_obj_clean(lv_scr_act());

  lv_obj_t * menu = lv_menu_create(lv_scr_act());
  lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
  lv_obj_center(menu);

  lv_menu_set_mode_header(menu, LV_MENU_HEADER_TOP_UNFIXED);

  lv_menu_set_mode_root_back_btn(menu, LV_MENU_ROOT_BACK_BTN_ENABLED);
  lv_obj_t * back_btn = lv_menu_get_main_header_back_btn(menu);
  lv_obj_t * back_btn_label = lv_label_create(back_btn);
  lv_label_set_text(back_btn_label, "Back");
  lv_obj_add_event_cb(back_btn, menuBackBtnHandler, LV_EVENT_CLICKED, menu);

  lv_obj_t * cont;
  lv_obj_t * section;
  lv_obj_t * label;

  // ROOT->SETTINGS->CONTROLLER->DATA_SOURCE
  lv_obj_t * page_settings_controller_datasource = lv_menu_page_create(menu, "Data Source");
  section = lv_menu_section_create(page_settings_controller_datasource);
  cont = lv_menu_cont_create(section);
  label = lv_label_create(cont);
  lv_label_set_text(label, "TODO");

  // ROOT->SETTINGS->CONTROLLER->TARGET_VALUE
  lv_obj_t * page_settings_controller_target_value = lv_menu_page_create(menu, "Target value");
  section = lv_menu_section_create(page_settings_controller_target_value);
  cont = lv_menu_cont_create(section);
  lv_obj_t * target_value_spinbox = lv_spinbox_create(cont);
  lv_spinbox_set_range(target_value_spinbox, CR_SETTINGS_TARGET_VALUE_MIN, CR_SETTINGS_TARGET_VALUE_MAX);
  lv_spinbox_set_digit_format(target_value_spinbox, 3, 0);
  lv_spinbox_set_value(target_value_spinbox, CRS_Settings.targetValue);
  lv_obj_set_width(target_value_spinbox, 100);
  lv_obj_center(target_value_spinbox);
  lv_obj_add_event_cb(target_value_spinbox, targetValueSpinboxChangeHandler, LV_EVENT_VALUE_CHANGED, NULL);

  // ROOT->SETTINGS->CONTROLLER
  lv_obj_t * page_settings_controller = lv_menu_page_create(menu, "Controller");
  cont = createMenuItem(page_settings_controller, "Target value", LV_SYMBOL_SETTINGS);
  lv_menu_set_load_page_event(menu, cont, page_settings_controller_target_value);
  cont = createMenuItem(page_settings_controller, "Data Source", LV_CUSTOM_SYMBOL_NETWORK_WIRED);
  lv_menu_set_load_page_event(menu, cont, page_settings_controller_datasource);

  // ROOT->SETTINGS->BRIGHTNESS
  lv_obj_t * page_settings_brightness = lv_menu_page_create(menu, "Brightness");
  section = lv_menu_section_create(page_settings_brightness);
  cont = lv_menu_cont_create(section);
  lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_BETWEEN);
  lv_obj_t * brightness_slider = lv_slider_create(cont);
  lv_obj_set_width(brightness_slider, 80);
  lv_slider_set_range(brightness_slider, 0, 100);
  lv_slider_set_value(brightness_slider, CRS_Settings.brightness, LV_ANIM_OFF);
  lv_obj_add_flag(brightness_slider, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
  lv_obj_add_event_cb(brightness_slider, brightnessSliderHandler, LV_EVENT_VALUE_CHANGED, NULL);
  label = lv_label_create(cont);
  lv_label_set_text_fmt(label, "%d%%", (uint8_t)lv_slider_get_value(brightness_slider));

  // ROOT->SETTINGS->SOUND
  lv_obj_t * page_settings_sound = lv_menu_page_create(menu, "Sound");
  section = lv_menu_section_create(page_settings_sound);
  cont = lv_menu_cont_create(section);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Buzzer");
  lv_obj_set_flex_grow(label, 1);
  lv_obj_t * buzzer_sw = lv_switch_create(cont);
  lv_obj_add_state(buzzer_sw, CRS_Settings.buzzerEnabled ? LV_STATE_CHECKED : 0);
  lv_obj_add_event_cb(buzzer_sw, buzzerSwitchHandler, LV_EVENT_VALUE_CHANGED, NULL);

  // ROOT->RELAY
  lv_obj_t * page_relay = lv_menu_page_create(menu, "Relay");
  section = lv_menu_section_create(page_relay);
  cont = lv_menu_cont_create(section);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Relay switch");
  lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_obj_set_flex_grow(label, 1);
  lv_obj_t * relay_sw = lv_switch_create(cont);
  lv_obj_add_state(relay_sw, HW_GetRelayState() ? LV_STATE_CHECKED : 0);
  lv_obj_add_event_cb(relay_sw, relaySwitchHandler, LV_EVENT_VALUE_CHANGED, NULL);

  // ROOT->SETTINGS
  page_settings = lv_menu_page_create(menu, "Settings");
  cont = createMenuItem(page_settings, "Controller", LV_CUSTOM_SYMBOL_SLIDERS);
  lv_menu_set_load_page_event(menu, cont, page_settings_controller);
  cont = createMenuItem(page_settings, "Brightness", LV_CUSTOM_SYMBOL_BRIGHTNESS);
  lv_menu_set_load_page_event(menu, cont, page_settings_brightness);
  cont = createMenuItem(page_settings, "Sound", LV_SYMBOL_AUDIO);
  lv_menu_set_load_page_event(menu, cont, page_settings_sound);

  // ROOT->DEBUG
  lv_obj_t * page_debug = lv_menu_page_create(menu, "Debug");

  cont = lv_menu_cont_create(page_debug);
  lv_obj_t * debug_btn = lv_btn_create(cont);
  lv_obj_add_event_cb(debug_btn, debugBtnClickHandler, LV_EVENT_CLICKED, NULL);
  label = lv_label_create(debug_btn);
  lv_label_set_text(label, "Debug screen");

  cont = lv_menu_cont_create(page_debug);
  lv_obj_t * demo_btn = lv_btn_create(cont);
  lv_obj_add_event_cb(demo_btn, demoBtnClickHandler, LV_EVENT_CLICKED, NULL);
  label = lv_label_create(demo_btn);
  lv_label_set_text(label, "Demo screen");


  // ROOT
  lv_obj_t * page_root = lv_menu_page_create(menu, NULL);
  cont = createMenuItem(page_root, "Relay", LV_CUSTOM_SYMBOL_PLUG);
  lv_menu_set_load_page_event(menu, cont, page_relay);
  cont = createMenuItem(page_root, "Settings", LV_SYMBOL_SETTINGS);
  lv_menu_set_load_page_event(menu, cont, page_settings);
  cont = createMenuItem(page_root, "Debug", LV_CUSTOM_SYMBOL_BUG);
  lv_menu_set_load_page_event(menu, cont, page_debug);

  lv_menu_set_page(menu, page_root);
}

static void UI_RenderHomeScreen() {
  lv_obj_clean(lv_scr_act());

  lv_obj_t * dummy = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(dummy, showMenuHandler, LV_EVENT_LONG_PRESSED, NULL);
  lv_obj_add_flag(dummy, LV_OBJ_FLAG_HIDDEN);

  lv_obj_t * label;

  label = lv_label_create(lv_scr_act());
  lv_obj_align(label, LV_ALIGN_TOP_MID, -40, 5);
  lv_label_set_text(label, "Current:");

  label = lv_label_create(lv_scr_act());
  lv_obj_align(label, LV_ALIGN_TOP_MID, 40, 5);
  lv_label_set_text(label, "Target:");

  currentValueLabel = lv_label_create(lv_scr_act());
  lv_obj_align(currentValueLabel, LV_ALIGN_CENTER, -40, -1);
  lv_label_set_text(currentValueLabel, "---");
  lv_obj_set_style_text_color(currentValueLabel, lv_color_hex(UI_COLOR_RED), 0);
  lv_obj_set_style_text_font(currentValueLabel, &lv_font_montserrat_36_custom, 0);

  label = lv_label_create(lv_scr_act());
  lv_obj_align(label, LV_ALIGN_CENTER, 40, -1);
  lv_label_set_text_fmt(label, "%d", CRS_Settings.targetValue);
  lv_obj_set_style_text_color(label, lv_color_hex(UI_COLOR_YELLOW), 0);
  lv_obj_set_style_text_font(label, &lv_font_montserrat_36_custom, 0);

  label = lv_label_create(lv_scr_act());
  lv_obj_align(label, LV_ALIGN_BOTTOM_RIGHT, -5, -5);
  lv_label_set_text(label, "[°C]");

  label = lv_label_create(lv_scr_act());
  lv_obj_align(label, LV_ALIGN_BOTTOM_LEFT, 5, -5);
  lv_label_set_text(label, "Relay:");

  lv_obj_t * relay_status_indicator = lv_obj_create(lv_scr_act());
  lv_obj_set_style_radius(relay_status_indicator, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_size(relay_status_indicator, 13, 13);
  lv_obj_align(relay_status_indicator, LV_ALIGN_BOTTOM_LEFT, 55, -6);

  if (HW_GetRelayState()) {
    lv_obj_set_style_bg_color(relay_status_indicator, lv_color_hex(UI_COLOR_BLUE), 0);
  } else {
    lv_obj_set_style_bg_color(relay_status_indicator, lv_color_hex(UI_COLOR_GRAY), 0);
  }
}

void UI_Init() {
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_ENCODER;
  indev_drv.read_cb = encoderReadCallback;
  indev_drv.feedback_cb = encoderFeedbackCallback;
  indev_encoder = lv_indev_drv_register(&indev_drv);

  lv_group_t * group = lv_group_create();
  lv_group_set_default(group);
  lv_indev_set_group(indev_encoder, group);

  UI_RenderHomeScreen();
}

// Vout = R2/(R1+R2)*Vin
// Vin = 4.97V
// R1 = 2200
// R2 = 45300

volatile static int16_t TC1;
volatile static double V1;
volatile static int16_t TC2;
volatile static double V2;
volatile static int16_t TC3;
volatile static double V3;

volatile static double TK1;
volatile static double TK2;
volatile static double TK3;
volatile static double LNV1;
volatile static double LNV2;
volatile static double LNV3;

volatile static double LNV12DIFF;
volatile static double LNV13DIFF;
volatile static double TK12E;
volatile static double TK13E;

volatile static double CoefC;
volatile static double CoefB;
volatile static double CoefA;

#define CONST_VREF (4.97)
#define CONST_SR 2200
#define CONST_R1 44864 // 45303
#define CONST_R2 2480 // 2500
#define CONST_R3 (89.8) // 89

void UI_Tick() {
  TC1 = -40;
  V1 = (double) CONST_R1 / (CONST_SR + CONST_R1) * CONST_VREF * 1000;
  // TC2 = 20;
  // V2 = (double) CONST_R2 / (CONST_SR + CONST_R2) * CONST_VREF * 1000;
  // TC3 = 130;
  // V3 = (double) CONST_R3 / (CONST_SR + CONST_R3) * CONST_VREF * 1000;
  // TC1 = 9;
  // V1 = 2785;
  TC2 = 35;
  V2 = 1750;
  TC3 = 123;
  V3 = 273;

  TK1 = TC1 + 273.15;
  TK2 = TC2 + 273.15;
  TK3 = TC3 + 273.15;

  LNV1 = log(V1);
  LNV2 = log(V2);
  LNV3 = log(V3);

  LNV12DIFF = LNV1 - LNV2;
  LNV13DIFF = LNV1 - LNV3;
  TK12E = (1 / TK1) - (1 / TK2);
  TK13E = (1 / TK1) - (1 / TK3);

  CoefC = (TK12E - LNV12DIFF * TK13E / LNV13DIFF) / ((pow(LNV1, 3) - pow(LNV2, 3)) - LNV12DIFF * (pow(LNV1, 3) - pow(LNV3, 3)) / LNV13DIFF);
  CoefB = (TK12E - CoefC * (pow(LNV1, 3) - pow(LNV2, 3))) / LNV12DIFF;
  CoefA = 1 / TK1 - CoefC * pow(LNV1, 3) - CoefB * LNV1;

  // options:
  // 0) CAN Address
  // 1) size: 1 or 2 bytes
  // 2) byte position N
  // 3) endianness

  uint16_t value = (COMM_CANRxData[0] << 8) | COMM_CANRxData[1];
  if (value != prevCurrentDataRaw) {
    prevCurrentDataRaw = value;

    double tc = 1.0 / (CoefA + CoefB * log(value) + CoefC * pow(log(value), 3)) - 273.15;
    lv_label_set_text_fmt(currentValueLabel, "%d", (int16_t) tc);
    // lv_label_set_text_fmt(currentValueLabel, "%d", (int16_t) value);
  }
}
