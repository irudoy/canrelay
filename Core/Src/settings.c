#include "settings.h"
#include "ee24.h"

canrelay_settings_t CRS_Settings;

void CRS_readSettings(void) {
  uint8_t needPersist = 0;
  ee24_read_obj(0, &CRS_Settings, sizeof CRS_Settings, 1000);
  if (CRS_Settings.targetValue > CR_SETTINGS_TARGET_VALUE_MAX || CRS_Settings.targetValue < CR_SETTINGS_TARGET_VALUE_MIN) {
    CRS_Settings.targetValue = CR_SETTINGS_DEFAULT_TARGET_VALUE;
    needPersist = 1;
  }
  if (CRS_Settings.buzzerEnabled > 1) {
    CRS_Settings.buzzerEnabled = CR_SETTINGS_DEFAULT_BUZZER_ENABLED;
    needPersist = 1;
  }
  if (CRS_Settings.brightness > 100) {
    CRS_Settings.brightness = CR_SETTINGS_DEFAULT_BRIGHTNESS;
    needPersist = 1;
  }
  if (needPersist) {
    CRS_persistSettings();
  }
}

void CRS_persistSettings(void) {
  ee24_update_obj(0, &CRS_Settings, sizeof CRS_Settings, 1000);
}
