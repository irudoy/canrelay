#include "hw.h"
#include "settings.h"
#include "stm32f2xx_hal.h"
#include "../../lvgl/lvgl.h"

static int32_t encoderPrevCount = 0;
static int32_t buzzerPWMPulseCount = 0;

volatile lv_indev_state_t HW_encoderBtnState = LV_INDEV_STATE_RELEASED;
volatile int16_t HW_encoderDiff = 0;

extern canrelay_settings_t CRS_Settings;

static uint16_t lcdBacklightTick = 0;

static uint16_t brightnessPercentToPWMDuty(uint8_t value) {
  return (100 - value) * (61166 / 100);
}

void HW_Init() {
  HAL_TIM_Encoder_Start(&HW_ENCODER_TIM, HW_ENCODER_TIM_CHANNEL);
  CRS_readSettings();
  HW_RelayToggle();
  // HAL_Delay(500);
  // HW_RelayToggle();
  // HAL_Delay(500);
  // HW_RelayToggle();
}

void HW_LCDBacklightEnable() {
  lcdBacklightTick = 1;
  HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 = 65532;
  HAL_TIM_PWM_Start(&HW_LCD_LED_PWM_TIM, HW_LCD_LED_PWM_TIM_CHANNEL);
}

void HW_Tick() {
  if (HW_ENCODER_TIM_INSTANCE->CNT != encoderPrevCount && HW_ENCODER_TIM_INSTANCE->CNT % 4 == 0) {
    if (encoderPrevCount == 0 && HW_ENCODER_TIM_INSTANCE->CNT == 65532) {
      HW_encoderDiff--;
    } else if (encoderPrevCount == 65532 && HW_ENCODER_TIM_INSTANCE->CNT == 0) {
      HW_encoderDiff++;
    } else if (HW_ENCODER_TIM_INSTANCE->CNT > encoderPrevCount) {
      HW_encoderDiff++;
    } else {
      HW_encoderDiff--;
    }
    encoderPrevCount = HW_ENCODER_TIM_INSTANCE->CNT;
    // lv_msg_send(MSG_DEBUG_ENC_VAL, &encoderPrevCount);
  }

  if (lcdBacklightTick != 0) {
    if (lcdBacklightTick > 1) {
      HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 -= 1;
      if (HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 <= brightnessPercentToPWMDuty(CRS_Settings.brightness)) {
        HW_LCDSetBrightness(CRS_Settings.brightness);
        lcdBacklightTick = 0;
      }
    } else {
      lcdBacklightTick++;
    }
  }
}

void HW_Buzz() {
  if (CRS_Settings.buzzerEnabled) {
    HAL_TIM_PWM_Start_IT(&HW_BUZZER_TIM, HW_BUZZER_TIM_CHANNEL);
  }
}

void HW_RelayToggle() {
  HAL_GPIO_TogglePin(HW_RELAY_PORT, HW_RELAY_PIN);
}

void HW_RelaySwitchON() {
  HAL_GPIO_WritePin(HW_RELAY_PORT, HW_RELAY_PIN, GPIO_PIN_SET);
}

void HW_RelaySwitchOFF() {
  HAL_GPIO_WritePin(HW_RELAY_PORT, HW_RELAY_PIN, GPIO_PIN_RESET);
}

uint8_t HW_GetRelayState() {
  return HAL_GPIO_ReadPin(HW_RELAY_PORT, HW_RELAY_PIN);
}

/**
 * @brief Set LCD Brightness
 *
 * @param value 0-100%
 */
void HW_LCDSetBrightness(uint8_t value) {
  HW_LCD_LED_PWM_TIM_INSTANCE->CCR1 = brightnessPercentToPWMDuty(value);
  CRS_Settings.brightness = value;
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
      HW_encoderBtnState = LV_INDEV_STATE_RELEASED;
    } else { // LO
      HW_encoderBtnState = LV_INDEV_STATE_PRESSED;
    }
  }
}
