#ifndef INC_HW_H_
#define INC_HW_H_

#include "main.h"

#define HW_RELAY_PORT RELAY_GPIO_Port
#define HW_RELAY_PIN RELAY_Pin

#define HW_LCD_LED_PWM_TIM htim5
#define HW_LCD_LED_PWM_TIM_INSTANCE TIM5
#define HW_LCD_LED_PWM_TIM_CHANNEL TIM_CHANNEL_1

#define HW_ENCODER_TIM htim3
#define HW_ENCODER_TIM_INSTANCE TIM3
#define HW_ENCODER_TIM_CHANNEL TIM_CHANNEL_ALL

#define HW_BUZZER_TIM htim8
#define HW_BUZZER_TIM_INSTANCE TIM8
#define HW_BUZZER_TIM_CHANNEL TIM_CHANNEL_2

extern TIM_HandleTypeDef HW_LCD_LED_PWM_TIM;
extern TIM_HandleTypeDef HW_ENCODER_TIM;
extern TIM_HandleTypeDef HW_BUZZER_TIM;

void HW_Init();
void HW_Tick();

#endif /* INC_HW_H_ */
