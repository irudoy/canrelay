#include "hw.h"
#include "ui.h"
#include "stm32f2xx_hal.h"
#include "../../lvgl/lvgl.h"

int32_t lcdBrPWMDC = 0;
int32_t encoderPrevCount = 0;
int32_t buzzerPWMPulseCount = 0;

void HW_Init() {
  HAL_TIM_PWM_Start(&HW_LCD_LED_PWM_TIM, HW_LCD_LED_PWM_TIM_CHANNEL);
  HAL_TIM_Encoder_Start(&HW_ENCODER_TIM, HW_ENCODER_TIM_CHANNEL);

  HW_RelayToggle();
  HAL_Delay(500);
  HW_RelayToggle();
  HAL_Delay(500);
  HW_RelayToggle();
}

void HW_Tick() {
  if (HW_ENCODER_TIM_INSTANCE->CNT != encoderPrevCount && HW_ENCODER_TIM_INSTANCE->CNT % 4 == 0) {
    uint32_t timValue = HW_ENCODER_TIM_INSTANCE->CNT;
    if (timValue > encoderPrevCount) {
      lcdBrPWMDC -= 2000;
      if (lcdBrPWMDC < 0) {
        lcdBrPWMDC = 0;
      }
    } else {
      lcdBrPWMDC += 2000;
      if (lcdBrPWMDC > 65535) {
        lcdBrPWMDC = 65535;
      }
    }

    HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 = lcdBrPWMDC;
    HW_BUZZER_TIM_INSTANCE->CCR1 = lcdBrPWMDC; // buzzer
    encoderPrevCount = timValue;

    lv_msg_send(MSG_TIMER_CHANGED, &timValue);
    HW_Buzz();
  }
}

void HW_Buzz() {
  HAL_TIM_PWM_Start_IT(&HW_BUZZER_TIM, HW_BUZZER_TIM_CHANNEL);
}

void HW_RelayToggle() {
  HAL_GPIO_TogglePin(HW_RELAY_PORT, HW_RELAY_PIN);
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
    HW_Buzz();
    HW_RelayToggle();
  }
}
