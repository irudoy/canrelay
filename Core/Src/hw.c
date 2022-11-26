#include "hw.h"
#include "msg.h"
#include "stm32f2xx_hal.h"
#include "../../lvgl/lvgl.h"

int32_t lcdBrPWMDC = 0;
int32_t encoderPrevCount = 0;
int32_t buzzerPWMPulseCount = 0;

static void encoderInteractCallback(void * s, lv_msg_t * m);
static void encoderPrevCallback(void * s, lv_msg_t * m);
static void encoderNextCallback(void * s, lv_msg_t * m);
static void encoderPressCallback(void * s, lv_msg_t * m);
static void encoderLongPressCallback(void * s, lv_msg_t * m);

void HW_Init() {
  HAL_TIM_PWM_Start(&HW_LCD_LED_PWM_TIM, HW_LCD_LED_PWM_TIM_CHANNEL);
  HAL_TIM_Encoder_Start(&HW_ENCODER_TIM, HW_ENCODER_TIM_CHANNEL);

  HW_RelayToggle();
  HAL_Delay(500);
  HW_RelayToggle();
  HAL_Delay(500);
  HW_RelayToggle();

  lv_msg_subsribe(MSG_INPUT_PREV, encoderInteractCallback, NULL);
  lv_msg_subsribe(MSG_INPUT_NEXT, encoderInteractCallback, NULL);
  lv_msg_subsribe(MSG_INPUT_PRESS, encoderInteractCallback, NULL);
  lv_msg_subsribe(MSG_INPUT_LONG_PRESS, encoderInteractCallback, NULL);

  lv_msg_subsribe(MSG_INPUT_PREV, encoderPrevCallback, NULL);
  lv_msg_subsribe(MSG_INPUT_NEXT, encoderNextCallback, NULL);
  lv_msg_subsribe(MSG_INPUT_PRESS, encoderPressCallback, NULL);
  lv_msg_subsribe(MSG_INPUT_LONG_PRESS, encoderLongPressCallback, NULL);

  // dirty timer status reset, fixes strange first-long-press issue
  HW_ENCODER_COUNT_TIM_INSTANCE->SR = 0;
}

static void encoderInteractCallback(void * s, lv_msg_t * m) {
  LV_UNUSED(s);
  LV_UNUSED(m);
  HW_Buzz();
}

static void encoderPrevCallback(void * s, lv_msg_t * m) {
  LV_UNUSED(s);
  LV_UNUSED(m);
  HW_LCDBrightnessDecrease();
}

static void encoderNextCallback(void * s, lv_msg_t * m) {
  LV_UNUSED(s);
  LV_UNUSED(m);
  HW_LCDBrightnessIncrease();
}

static void encoderPressCallback(void * s, lv_msg_t * m) {
  LV_UNUSED(s);
  LV_UNUSED(m);
  lcdBrPWMDC = 61166;
  HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 = lcdBrPWMDC;
}

static void encoderLongPressCallback(void * s, lv_msg_t * m) {
  LV_UNUSED(s);
  LV_UNUSED(m);
  HW_RelayToggle();
}

void HW_Tick() {
  if (HW_ENCODER_TIM_INSTANCE->CNT != encoderPrevCount && HW_ENCODER_TIM_INSTANCE->CNT % 4 == 0) {
    if (encoderPrevCount == 0 && HW_ENCODER_TIM_INSTANCE->CNT == 65532) {
      lv_msg_send(MSG_INPUT_PREV, NULL);
    } else if (encoderPrevCount == 65532 && HW_ENCODER_TIM_INSTANCE->CNT == 0) {
      lv_msg_send(MSG_INPUT_NEXT, NULL);
    } else if (HW_ENCODER_TIM_INSTANCE->CNT > encoderPrevCount) {
      lv_msg_send(MSG_INPUT_NEXT, NULL);
    } else {
      lv_msg_send(MSG_INPUT_PREV, NULL);
    }
    encoderPrevCount = HW_ENCODER_TIM_INSTANCE->CNT;
    lv_msg_send(MSG_DEBUG_ENC_VAL, &encoderPrevCount);
  }
}

void HW_Buzz() {
  HAL_TIM_PWM_Start_IT(&HW_BUZZER_TIM, HW_BUZZER_TIM_CHANNEL);
}

void HW_RelayToggle() {
  HAL_GPIO_TogglePin(HW_RELAY_PORT, HW_RELAY_PIN);
}

void HW_LCDBrightnessIncrease() {
  lcdBrPWMDC -= 4369;
  if (lcdBrPWMDC < 4369) {
    lcdBrPWMDC = 0;
  }
  HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 = lcdBrPWMDC;

  lv_msg_send(MSG_DEBUG_LCD_BR_PWM, &lcdBrPWMDC);
}

void HW_LCDBrightnessDecrease() {
  lcdBrPWMDC += 4369;
  if (lcdBrPWMDC >= 61166) {
    lcdBrPWMDC = 61166;
  }
  HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 = lcdBrPWMDC;

  lv_msg_send(MSG_DEBUG_LCD_BR_PWM, &lcdBrPWMDC);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == HW_BUZZER_TIM_INSTANCE && htim->Channel == HW_BUZZER_TIM_ACTIVE_CHANNEL) {
    buzzerPWMPulseCount++;
    if (buzzerPWMPulseCount >= 300) {
      HAL_TIM_PWM_Stop_IT(&HW_BUZZER_TIM, HW_BUZZER_TIM_CHANNEL);
      buzzerPWMPulseCount = 0;
    }
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  if (GPIO_Pin == HW_ENCODER_BTN_PIN) {
    if ((HW_ENCODER_BTN_PORT->IDR & HW_ENCODER_BTN_PIN) != (uint32_t)GPIO_PIN_RESET) {
      if (HW_ENCODER_COUNT_TIM_INSTANCE->CNT > 0) {
        lv_msg_send(MSG_INPUT_PRESS, NULL);
      }
      __HAL_TIM_DISABLE_IT(&HW_ENCODER_COUNT_TIM, TIM_IT_UPDATE);
      __HAL_TIM_DISABLE(&HW_ENCODER_COUNT_TIM);
      HW_ENCODER_COUNT_TIM_INSTANCE->CNT = 0;
    } else { // LO
      __HAL_TIM_ENABLE_IT(&HW_ENCODER_COUNT_TIM, TIM_IT_UPDATE);
      __HAL_TIM_ENABLE(&HW_ENCODER_COUNT_TIM);
    }
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == HW_ENCODER_COUNT_TIM_INSTANCE) {
    lv_msg_send(MSG_INPUT_LONG_PRESS, NULL);
    __HAL_TIM_DISABLE_IT(&HW_ENCODER_COUNT_TIM, TIM_IT_UPDATE);
    __HAL_TIM_DISABLE(&HW_ENCODER_COUNT_TIM);
    HW_ENCODER_COUNT_TIM_INSTANCE->CNT = 0;
  }
}
