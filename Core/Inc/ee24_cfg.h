#ifndef	INC_EE24CFG_H_
#define	INC_EE24CFG_H_

#include "main.h"
#include "stm32f2xx_hal.h"

#define EE24_EEPROM_SIZE_KBIT 2 // M24C02 C02 =2 Kbit (256 x 8 bit)
#define EE24_EEPROM_I2C hi2c2
#define EE24_EEPROM_USE_FREERTOS 0
#define EE24_EEPROM_ADDRESS 0xAE
#define EE24_EEPROM_USE_WP_PIN 0

extern I2C_HandleTypeDef EE24_EEPROM_I2C;

#if (EE24_EEPROM_USE_WP_PIN == 1)
#define EE24_EEPROM_WP_GPIO EE_WP_GPIO_Port
#define EE24_EEPROM_WP_PIN EE_WP_Pin
#endif

#endif
