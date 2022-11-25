#include "lcd_lvgl.h"
#include "../../lv_conf.h"
#include "../../lvgl/lvgl.h"
#include "st7735.h"

// display driver struct
static lv_disp_drv_t disp_drv;

static lv_color_t disp_buf1[DISP_HOR_RES * 10];
static lv_color_t disp_buf2[DISP_HOR_RES * 10];

static volatile uint32_t t_saved = 0;

void monitor_cb(lv_disp_drv_t * d, uint32_t t, uint32_t p) {
  t_saved = t;
}

static void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p);

void Display_init() {
  static lv_disp_draw_buf_t buf;
  lv_disp_draw_buf_init(&buf, disp_buf1, disp_buf2, DISP_HOR_RES * 10);
  lv_disp_drv_init(&disp_drv);

  ST7735_Init();
  ST7735_FillScreen(ST7735_BLACK);

  disp_drv.draw_buf = &buf;
  disp_drv.flush_cb = tft_flush;
  disp_drv.monitor_cb = monitor_cb;
  disp_drv.hor_res = DISP_HOR_RES;
  disp_drv.ver_res = DISP_VER_RES;
  lv_disp_drv_register(&disp_drv);
}

/**
 * Flush a color buffer
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
static void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p)
{
  // The most simple case (but also the slowest) to put all pixels to the screen one-by-one
  int32_t x, y;
  for (y = area->y1; y <= area->y2; y++) {
    for (x = area->x1; x <= area->x2; x++) {
      ST7735_DrawPixel(x, y, color_p->full);
      color_p++;
    }
  }

  /* IMPORTANT!!!
   * Inform the graphics library that you are ready with the flushing*/
  lv_disp_flush_ready(drv);
}
