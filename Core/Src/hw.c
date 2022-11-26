#include "hw.h"
#include "stm32f2xx_hal.h"

int32_t lcdBrPWMDC = 0;
int32_t encoderPrevCount = 0;

void HW_Init() {
  HAL_TIM_PWM_Start(&HW_LCD_LED_PWM_TIM, HW_LCD_LED_PWM_TIM_CHANNEL);
  HAL_TIM_Encoder_Start(&HW_ENCODER_TIM, HW_ENCODER_TIM_CHANNEL);

  HAL_GPIO_TogglePin(HW_RELAY_PORT, HW_RELAY_PIN);
  HAL_Delay(500);
  HAL_GPIO_TogglePin(HW_RELAY_PORT, HW_RELAY_PIN);
  HAL_Delay(500);
  HAL_GPIO_TogglePin(HW_RELAY_PORT, HW_RELAY_PIN);
}

void HW_Tick() {
  if (HW_ENCODER_TIM_INSTANCE->CNT != encoderPrevCount) {
    if (HW_ENCODER_TIM_INSTANCE->CNT > encoderPrevCount) {
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
    encoderPrevCount = HW_ENCODER_TIM_INSTANCE->CNT;

    HAL_TIM_PWM_Start(&HW_BUZZER_TIM, HW_BUZZER_TIM_CHANNEL);
    HAL_Delay(50);
    HAL_TIM_PWM_Stop(&HW_BUZZER_TIM, HW_BUZZER_TIM_CHANNEL);
  }
}
