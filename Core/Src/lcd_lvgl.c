#include "lcd_lvgl.h"
#include "../../lv_conf.h"
#include "../../lvgl/lvgl.h"
#include "st7735.h"

static lv_disp_drv_t disp_drv;

static lv_color_t disp_buf1[DISP_HOR_RES * 10];
static lv_color_t disp_buf2[DISP_HOR_RES * 10];

uint16_t display_fb[DISP_HOR_RES * 1];

static void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p);

void LCD_Init() {
  static lv_disp_draw_buf_t buf;
  lv_disp_draw_buf_init(&buf, disp_buf1, disp_buf2, DISP_HOR_RES * 10);
  lv_disp_drv_init(&disp_drv);

  ST7735_Init();

  disp_drv.draw_buf = &buf;
  disp_drv.flush_cb = tft_flush;
  disp_drv.hor_res = DISP_HOR_RES;
  disp_drv.ver_res = DISP_VER_RES;
  lv_disp_drv_register(&disp_drv);
}

void LCD_Tick() {
  lv_task_handler();
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
  if (area->x2 < 0) return;
  if (area->y2 < 0) return;
  if (area->x1 > DISP_HOR_RES - 1) return;
  if (area->y1 > DISP_VER_RES - 1) return;

  uint8_t x, y;
  uint8_t i = 0;

  for (y = area->y1; y <= area->y2; y++) {
    for (x = area->x1; x <= area->x2; x++) {
      // ST7735_DrawPixel(x, y, color_p->full);
      display_fb[i] = color_p->full;
      color_p++;
      i++;
    }
    i = 0;
    ST7735_DrawImage(area->x1, y, area->x2, y, display_fb);
  }

  /* IMPORTANT!!!
   * Inform the graphics library that you are ready with the flushing*/
  lv_disp_flush_ready(drv);
}
