#include "ee24.h"
#if (EE24_EEPROM_USE_FREERTOS == 1)
#include "cmsis_os.h"
#define ee24_delay(x) osDelay(x)
#else
#define ee24_delay(x) HAL_Delay(x)
#endif

#if (EE24_EEPROM_SIZE_KBIT == 1) || (EE24_EEPROM_SIZE_KBIT == 2)
#define EE24_EEPROM_PSIZE 8
#elif (EE24_EEPROM_SIZE_KBIT == 4) || (EE24_EEPROM_SIZE_KBIT == 8) || (EE24_EEPROM_SIZE_KBIT == 16)
#define _EEPROM_PSIZE 16
#else
#define _EEPROM_PSIZE 32
#endif

uint8_t ee24_lock = 0;

bool ee24_isConnected(void) {
  #if (EE24_EEPROM_USE_WP_PIN == 1)
  HAL_GPIO_WritePin(EE24_EEPROM_WP_GPIO, EE24_EEPROM_WP_PIN, GPIO_PIN_SET);
  #endif
  if (HAL_I2C_IsDeviceReady(&EE24_EEPROM_I2C, EE24_EEPROM_ADDRESS, 2, 100) == HAL_OK) {
    return true;
  } else {
    return false;
  }
}

bool ee24_write(uint16_t address, uint8_t *data, size_t len, uint32_t timeout) {
  if (ee24_lock == 1) {
    return false;
  }
  ee24_lock = 1;
  uint16_t w;
  uint32_t startTime = HAL_GetTick();
  #if	(EE24_EEPROM_USE_WP_PIN==1)
  HAL_GPIO_WritePin(EE24_EEPROM_WP_GPIO, EE24_EEPROM_WP_PIN, GPIO_PIN_RESET);
  #endif
  while (1) {
    w = EE24_EEPROM_PSIZE - (address % EE24_EEPROM_PSIZE);
    if (w > len) {
      w = len;
    }
    #if ((EE24_EEPROM_SIZE_KBIT == 1) || (EE24_EEPROM_SIZE_KBIT == 2))
    if (HAL_I2C_Mem_Write(&EE24_EEPROM_I2C, EE24_EEPROM_ADDRESS, address, I2C_MEMADD_SIZE_8BIT, data, w, 100) == HAL_OK)
    #elif (EE24_EEPROM_SIZE_KBIT == 4)
    if (HAL_I2C_Mem_Write(&_EEPROM_I2C, _EEPROM_ADDRESS | ((address & 0x0100) >> 7), (address & 0xff), I2C_MEMADD_SIZE_8BIT, data, w, 100) == HAL_OK)
    #elif (_EEPROM_SIZE_KBIT == 8)
    if (HAL_I2C_Mem_Write(&_EEPROM_I2C, _EEPROM_ADDRESS | ((address & 0x0300) >> 7), (address & 0xff), I2C_MEMADD_SIZE_8BIT, data, w, 100) == HAL_OK)
    #elif (_EEPROM_SIZE_KBIT == 16)
    if (HAL_I2C_Mem_Write(&_EEPROM_I2C, _EEPROM_ADDRESS | ((address & 0x0700) >> 7), (address & 0xff), I2C_MEMADD_SIZE_8BIT, data, w, 100) == HAL_OK)
    #else
    if (HAL_I2C_Mem_Write(&_EEPROM_I2C, _EEPROM_ADDRESS, address, I2C_MEMADD_SIZE_16BIT, data, w, 100) == HAL_OK)
    #endif
    {
      ee24_delay(10);

      len -= w;
      data += w;
      address += w;

      if (len == 0) {
        #if (EE24_EEPROM_USE_WP_PIN==1)
        HAL_GPIO_WritePin(EE24_EEPROM_WP_GPIO, EE24_EEPROM_WP_PIN, GPIO_PIN_SET);
        #endif
        ee24_lock = 0;
        return true;
      }

      if (HAL_GetTick() - startTime >= timeout) {
        ee24_lock = 0;
        return false;
      }
    } else {
      #if (EE24_EEPROM_USE_WP_PIN==1)
      HAL_GPIO_WritePin(EE24_EEPROM_WP_GPIO, EE24_EEPROM_WP_PIN, GPIO_PIN_SET);
      #endif
      ee24_lock = 0;
      return false;
    }
  }
}

bool ee24_read(uint16_t address, uint8_t *data, size_t len, uint32_t timeout) {
  if (ee24_lock == 1) {
    return false;
  }
  ee24_lock = 1;
  #if (EE24_EEPROM_USE_WP_PIN == 1)
  HAL_GPIO_WritePin(EE24_EEPROM_WP_GPIO, EE24_EEPROM_WP_PIN, GPIO_PIN_SET);
  #endif
  #if ((EE24_EEPROM_SIZE_KBIT == 1) || (EE24_EEPROM_SIZE_KBIT == 2))
  if (HAL_I2C_Mem_Read(&EE24_EEPROM_I2C, EE24_EEPROM_ADDRESS, address, I2C_MEMADD_SIZE_8BIT, data, len, timeout) == HAL_OK)
  #elif (EE24_EEPROM_SIZE_KBIT == 4)
  if (HAL_I2C_Mem_Read(&_EEPROM_I2C, _EEPROM_ADDRESS | ((address & 0x0100) >> 7), (address & 0xff), I2C_MEMADD_SIZE_8BIT, data, len, 100) == HAL_OK)
  #elif (_EEPROM_SIZE_KBIT == 8)
  if (HAL_I2C_Mem_Read(&_EEPROM_I2C, _EEPROM_ADDRESS | ((address & 0x0300) >> 7), (address & 0xff), I2C_MEMADD_SIZE_8BIT, data, len, 100) == HAL_OK)
  #elif (_EEPROM_SIZE_KBIT == 16)
  if (HAL_I2C_Mem_Read(&_EEPROM_I2C, _EEPROM_ADDRESS | ((address & 0x0700) >> 7), (address & 0xff), I2C_MEMADD_SIZE_8BIT, data, len, 100) == HAL_OK)
  #else
  if (HAL_I2C_Mem_Read(&_EEPROM_I2C, _EEPROM_ADDRESS, address, I2C_MEMADD_SIZE_16BIT, data, len, timeout) == HAL_OK)
  #endif
  {
    ee24_lock = 0;
    return true;
  } else {
    ee24_lock = 0;
    return false;
  }
}

void ee24_write_obj(uint16_t addr, void * obj, size_t lenInBytes, uint32_t timeout) {
  size_t i;
  uint8_t * ptr = (uint8_t *) obj;

  for (i = 0; i < lenInBytes; i++) {
    ee24_write(addr++, ptr++, 1, timeout);
  }
}

void ee24_update_obj(uint16_t addr, void * obj, size_t lenInBytes, uint32_t timeout) {
  uint8_t curr;
  size_t i;
  uint8_t * ptr = (uint8_t *) obj;

  for (i = 0; i < lenInBytes; i++) {
    ee24_read(addr, &curr, 1, timeout);
    if (curr != (* ptr)) {
      ee24_write(addr, ptr, 1, timeout);
    }
    addr++;
    ptr++;
  }
}

void ee24_read_obj(uint16_t addr, void * obj, size_t lenInBytes, uint32_t timeout) {
  size_t i;
  uint8_t * ptr = (uint8_t *) obj;

  for (i = 0; i < lenInBytes; i++) {
    ee24_read(addr++, ptr++, 1, timeout);
  }
}

bool ee24_eraseChip(void) {
  const uint8_t eraseData[32] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF\
    , 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  uint32_t bytes = 0;
  while (bytes < (EE24_EEPROM_SIZE_KBIT * 256)) {
    if (ee24_write(bytes, (uint8_t*)eraseData, sizeof(eraseData), 100) == false) {
      return false;
    }
    bytes += sizeof(eraseData);
  }
  return true;
}
