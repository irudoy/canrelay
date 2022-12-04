#ifndef CANRELAY_SETTINGS_H
#define CANRELAY_SETTINGS_H

#include <stdint.h>

#define CR_SETTINGS_TARGET_VALUE_MIN (-50)
#define CR_SETTINGS_TARGET_VALUE_MAX 999

#define CR_SETTINGS_DEFAULT_TARGET_VALUE 0
#define CR_SETTINGS_DEFAULT_BUZZER_ENABLED 1
#define CR_SETTINGS_DEFAULT_BRIGHTNESS 95

typedef struct {
  int16_t targetValue;
  uint8_t buzzerEnabled;
  uint8_t brightness;
} canrelay_settings_t;

void CRS_readSettings(void);
void CRS_persistSettings(void);

#endif //CANRELAY_SETTINGS_H
