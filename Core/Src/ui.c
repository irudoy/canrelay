#include "ui.h"
#include "msg.h"
#include "../../lvgl/lvgl.h"

// static void set_value(void * bar, int32_t v);
// static void event_cb(lv_event_t * e);

static void label_event_cb(lv_event_t * e);

void UI_Init() {
  lv_obj_t * label1 = lv_label_create(lv_scr_act());
  lv_label_set_text(label1, "LCD_BR_DC: ?");
  lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, -15);
  lv_obj_add_event_cb(label1, label_event_cb, LV_EVENT_MSG_RECEIVED, NULL);
  lv_msg_subsribe_obj(MSG_DEBUG_LCD_BR_PWM, label1, "LCD_BR_DC: %d");

  lv_obj_t * label2 = lv_label_create(lv_scr_act());
  lv_label_set_text(label2, "ENC_VAL: ?");
  lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(label2, LV_ALIGN_CENTER, 0, 15);
  lv_obj_add_event_cb(label2, label_event_cb, LV_EVENT_MSG_RECEIVED, NULL);
  lv_msg_subsribe_obj(MSG_DEBUG_ENC_VAL, label2, "ENC_VAL: %d");

  ///

  // lv_obj_t * bar = lv_bar_create(lv_scr_act());
  // lv_obj_add_event_cb(bar, event_cb, LV_EVENT_DRAW_PART_END, NULL);
  // lv_obj_set_size(bar, 150, 20);
  // lv_obj_center(bar);

  // lv_anim_t a;
  // lv_anim_init(&a);
  // lv_anim_set_var(&a, bar);
  // lv_anim_set_values(&a, 0, 100);
  // lv_anim_set_exec_cb(&a, set_value);
  // lv_anim_set_time(&a, 2000);
  // lv_anim_set_playback_time(&a, 2000);
  // lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
  // lv_anim_start(&a);

  // example
  //  lv_obj_t * obj = lv_obj_create(lv_scr_act());
  //  lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_CYAN), 0);
  //  lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);
  //
  //  lv_obj_align(obj, LV_ALIGN_LEFT_MID, 5, 0);
  //
  //  lv_anim_t a;
  //  lv_anim_init(&a);
  //  lv_anim_set_var(&a, obj);
  //  lv_anim_set_values(&a, 10, 50);
  //  lv_anim_set_time(&a, 1000);
  //  lv_anim_set_playback_delay(&a, 100);
  //  lv_anim_set_playback_time(&a, 300);
  //  lv_anim_set_repeat_delay(&a, 100);
  //  lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
  //  lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
  //
  //  lv_anim_set_exec_cb(&a, anim_size_cb);
  //  lv_anim_start(&a);
  //  lv_anim_set_exec_cb(&a, anim_x_cb);
  //  lv_anim_set_values(&a, 100, 5);
  //  lv_anim_start(&a);
  // example

  // lv_example_menu_3();
}

static void label_event_cb(lv_event_t * e) {
    lv_obj_t * label = lv_event_get_target(e);
    lv_msg_t * m = lv_event_get_msg(e);

    const char * fmt = lv_msg_get_user_data(m);
    const int32_t * v = lv_msg_get_payload(m);

    lv_label_set_text_fmt(label, fmt, *v);
}

// static void set_value(void * bar, int32_t v) {
//   lv_bar_set_value(bar, v, LV_ANIM_OFF);
// }

// static void event_cb(lv_event_t * e) {
//   lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
//   if(dsc->part != LV_PART_INDICATOR) return;

//   lv_obj_t * obj = lv_event_get_target(e);

//   lv_draw_label_dsc_t label_dsc;
//   lv_draw_label_dsc_init(&label_dsc);
//   label_dsc.font = LV_FONT_DEFAULT;

//   char buf[8];
//   lv_snprintf(buf, sizeof(buf), "%d", (int)lv_bar_get_value(obj));

//   lv_point_t txt_size;
//   lv_txt_get_size(&txt_size, buf, label_dsc.font, label_dsc.letter_space, label_dsc.line_space, LV_COORD_MAX,
//                   label_dsc.flag);

//   lv_area_t txt_area;
//   /*If the indicator is long enough put the text inside on the right*/
//   if(lv_area_get_width(dsc->draw_area) > txt_size.x + 20) {
//       txt_area.x2 = dsc->draw_area->x2 - 5;
//       txt_area.x1 = txt_area.x2 - txt_size.x + 1;
//       label_dsc.color = lv_color_white();
//   }
//   /*If the indicator is still short put the text out of it on the right*/
//   else {
//       txt_area.x1 = dsc->draw_area->x2 + 5;
//       txt_area.x2 = txt_area.x1 + txt_size.x - 1;
//       label_dsc.color = lv_color_black();
//   }

//   txt_area.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - txt_size.y) / 2;
//   txt_area.y2 = txt_area.y1 + txt_size.y - 1;

//   lv_draw_label(dsc->draw_ctx, &label_dsc, &txt_area, buf, NULL);
// }
