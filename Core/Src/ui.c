#include "ui.h"
#include "hw.h"
#include "msg.h"
#include "../../lvgl/lvgl.h"

extern int16_t HW_encoderDiff;
extern lv_indev_state_t HW_encoderBtnState;
extern uint8_t HW_buzzerEnabled;

static void UI_RenderHomeScreen();
static void UI_RenderMenu();
static void UI_RenderDebugScreen();
static void UI_RenderDemoScreen();

static void encoderReadCallback(lv_indev_drv_t * drv, lv_indev_data_t * data) {
  data->enc_diff = HW_encoderDiff;
  data->state = HW_encoderBtnState;
  HW_encoderDiff = 0;
}

static void encoderFeedbackCallback(lv_indev_drv_t * drv, lv_event_code_t event_code) {
  if (HW_buzzerEnabled && (event_code == LV_EVENT_LONG_PRESSED
    || event_code == LV_EVENT_SHORT_CLICKED
    || event_code == LV_EVENT_FOCUSED)) {
    HW_Buzz();
  }
}

static lv_indev_drv_t indev_drv;
static lv_indev_t * indev_encoder;

// static void update_label_value_event_cb(lv_event_t * e) {
//     lv_obj_t * label = lv_event_get_target(e);
//     lv_msg_t * m = lv_event_get_msg(e);

//     const char * fmt = lv_msg_get_user_data(m);
//     const int32_t * v = lv_msg_get_payload(m);

//     lv_label_set_text_fmt(label, fmt, *v);
// }

static void showMenuHandler(lv_event_t * e) {
  LV_UNUSED(e);
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
  // lv_obj_add_event_cb(label1, update_label_value_event_cb, LV_EVENT_MSG_RECEIVED, NULL);
  // lv_msg_subsribe_obj(MSG_DEBUG_LCD_BR_PWM, label1, "LCD_BR_DC: %d");

  lv_obj_t * label2 = lv_label_create(lv_scr_act());
  lv_label_set_text(label2, "ENC_VAL: ?");
  lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label2, LV_ALIGN_CENTER, 0, 15);
  // lv_obj_add_event_cb(label2, update_label_value_event_cb, LV_EVENT_MSG_RECEIVED, NULL);
  // lv_msg_subsribe_obj(MSG_DEBUG_ENC_VAL, label2, "ENC_VAL: %d");
}

static void anim_x_cb(void * var, int32_t v) {
  lv_obj_set_x(var, v);
}

static void anim_size_cb(void * var, int32_t v) {
  lv_obj_set_size(var, v, v);
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

static lv_obj_t * createMenuItem(lv_obj_t * parent, const char * text) {
  lv_obj_t * obj = lv_menu_cont_create(parent);
  lv_obj_t * label = lv_label_create(obj);

  // lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
  // lv_obj_set_flex_grow(label, 1);
  lv_label_set_text(label, text);

  // lv_obj_set_height(obj, 20);
  lv_group_add_obj(lv_group_get_default(), obj);

  return obj;
}

static void relaySwitchHandler(lv_event_t * e) {
  LV_UNUSED(e);
  HW_RelayToggle();
}

static void buzzerSwitchHandler(lv_event_t * e) {
  LV_UNUSED(e);
  HW_buzzerEnabled = !HW_buzzerEnabled;
}

static void brightnessSliderHandler(lv_event_t * e) {
  lv_obj_t * slider = lv_event_get_target(e);
  HW_LCDSetBrightness((uint8_t)lv_slider_get_value(slider));

  lv_obj_t * label = lv_obj_get_child(lv_obj_get_parent(slider), 1);
  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", (uint8_t)lv_slider_get_value(slider));
  lv_label_set_text(label, buf);
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

  if (lv_menu_back_btn_is_root(menu, obj)) {
    UI_RenderHomeScreen();
  }
}

static void UI_RenderMenu() {
  lv_obj_clean(lv_scr_act());

  lv_obj_t * menu = lv_menu_create(lv_scr_act());
  lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
  lv_obj_center(menu);

  lv_menu_set_mode_root_back_btn(menu, LV_MENU_ROOT_BACK_BTN_ENABLED);
  lv_obj_t * back_btn = lv_menu_get_main_header_back_btn(menu);
  lv_obj_t * back_btn_label = lv_label_create(back_btn);
  lv_label_set_text(back_btn_label, "Back");
  lv_obj_add_event_cb(back_btn, menuBackBtnHandler, LV_EVENT_CLICKED, menu);

  lv_obj_t * cont;
  lv_obj_t * section;
  lv_obj_t * label;

  // ROOT->SETTINGS->BRIGHTNESS
  lv_obj_t * page_settings_brightness = lv_menu_page_create(menu, "Brightness");
  section = lv_menu_section_create(page_settings_brightness);
  cont = lv_menu_cont_create(section);
  lv_obj_set_flex_align(cont, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_BETWEEN);
  lv_obj_t * brightness_slider = lv_slider_create(cont);
  lv_obj_set_width(brightness_slider, 80);
  lv_slider_set_range(brightness_slider, 0, 100);
  lv_slider_set_value(brightness_slider, HW_LCDGetBrightness(), LV_ANIM_OFF);
  lv_obj_add_flag(brightness_slider, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
  lv_obj_add_event_cb(brightness_slider, brightnessSliderHandler, LV_EVENT_VALUE_CHANGED, NULL);
  label = lv_label_create(cont);
  char buf[8];
  lv_snprintf(buf, sizeof(buf), "%d%%", (uint8_t)lv_slider_get_value(brightness_slider));
  lv_label_set_text(label, buf);

  // ROOT->SETTINGS->SOUND
  lv_obj_t * page_settings_sound = lv_menu_page_create(menu, "Sound");
  section = lv_menu_section_create(page_settings_sound);
  cont = lv_menu_cont_create(section);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Buzzer");
  lv_obj_set_flex_grow(label, 1);
  lv_obj_t * buzzer_sw = lv_switch_create(cont);
  lv_obj_add_state(buzzer_sw, HW_buzzerEnabled ? LV_STATE_CHECKED : 0);
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
  lv_obj_t * page_settings = lv_menu_page_create(menu, "Settings");
  cont = createMenuItem(page_settings, "Brightness");
  lv_menu_set_load_page_event(menu, cont, page_settings_brightness);
  cont = createMenuItem(page_settings, "Sound");
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
  cont = createMenuItem(page_root, "Relay");
  lv_menu_set_load_page_event(menu, cont, page_relay);
  cont = createMenuItem(page_root, "Settings");
  lv_menu_set_load_page_event(menu, cont, page_settings);
  cont = createMenuItem(page_root, "Debug");
  lv_menu_set_load_page_event(menu, cont, page_debug);

  lv_menu_set_page(menu, page_root);
}

static void UI_RenderHomeScreen() {
  lv_obj_clean(lv_scr_act());

  lv_obj_t * dummy = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(dummy, showMenuHandler, LV_EVENT_CLICKED, NULL);
  lv_obj_add_flag(dummy, LV_OBJ_FLAG_HIDDEN);

  lv_obj_t * relayLed  = lv_led_create(lv_scr_act());
  lv_obj_align(relayLed, LV_ALIGN_CENTER, 50, 0);
  if (HW_GetRelayState()) {
    lv_led_on(relayLed);
  } else {
    lv_led_off(relayLed);
  }

  lv_obj_t * current_value_label = lv_label_create(lv_scr_act());
  lv_label_set_text(current_value_label, "66");
  lv_obj_align(current_value_label, LV_ALIGN_CENTER, -20, 0);
  lv_obj_set_style_text_font(current_value_label, &lv_font_montserrat_48_custom, 0);
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
