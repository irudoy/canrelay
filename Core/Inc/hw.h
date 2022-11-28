#ifndef INC_HW_H_
#define INC_HW_H_

#include "main.h"

#define HW_RELAY_PORT RELAY_GPIO_Port
#define HW_RELAY_PIN RELAY_Pin

#define HW_LCD_LED_PWM_TIM htim5
#define HW_LCD_LED_PWM_TIM_INSTANCE TIM5
#define HW_LCD_LED_PWM_TIM_CHANNEL TIM_CHANNEL_1
extern TIM_HandleTypeDef HW_LCD_LED_PWM_TIM;

#define HW_ENCODER_BTN_PORT ENC_BTN_GPIO_Port
#define HW_ENCODER_BTN_PIN ENC_BTN_Pin

#define HW_ENCODER_TIM htim3
#define HW_ENCODER_TIM_INSTANCE TIM3
#define HW_ENCODER_TIM_CHANNEL TIM_CHANNEL_ALL
extern TIM_HandleTypeDef HW_ENCODER_TIM;

#define HW_BUZZER_TIM htim8
#define HW_BUZZER_TIM_INSTANCE TIM8
#define HW_BUZZER_TIM_CHANNEL TIM_CHANNEL_2
#define HW_BUZZER_TIM_ACTIVE_CHANNEL HAL_TIM_ACTIVE_CHANNEL_2
extern TIM_HandleTypeDef HW_BUZZER_TIM;

void HW_Init();
void HW_Tick();

void HW_Buzz();
void HW_RelayToggle();
void HW_RelaySwitchON();
void HW_RelaySwitchOFF();
uint8_t HW_GetRelayState();
void HW_LCDSetBrightness(uint8_t value);
uint8_t HW_LCDGetBrightness();

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_HW_H_ */
