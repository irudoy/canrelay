#ifndef	_EE24CFG_H
#define	_EE24CFG_H

#include "main.h"
#include "stm32f2xx_hal.h"

#define _EEPROM_SIZE_KBIT 2 // M24C02 C02 =2 Kbit (256 x 8 bit)
#define _EEPROM_I2C hi2c2
#define _EEPROM_USE_FREERTOS 0
#define _EEPROM_ADDRESS 0xAE
#define _EEPROM_USE_WP_PIN 0

extern I2C_HandleTypeDef _EEPROM_I2C;

#if (_EEPROM_USE_WP_PIN==1)
#define _EEPROM_WP_GPIO EE_WP_GPIO_Port
#define _EEPROM_WP_PIN EE_WP_Pin
#endif

#endif
