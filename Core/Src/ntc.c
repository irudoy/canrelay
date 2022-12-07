#include "ntc.h"
#include <math.h>

void NTC_InitSteinhartHart(ntc_steinhart_hart_settings_t * obj) {
  double tk1 = obj->temp_c_1 + NTC_K_OFFSET;
  double tk2 = obj->temp_c_2 + NTC_K_OFFSET;
  double tk3 = obj->temp_c_3 + NTC_K_OFFSET;

  double lnv1 = log(obj->value_1);
  double lnv2 = log(obj->value_2);
  double lnv3 = log(obj->value_3);

  double lnv1p3 = lnv1 * lnv1 * lnv1;
  double lnv2p3 = lnv2 * lnv2 * lnv2;
  double lnv3p3 = lnv3 * lnv3 * lnv3;

  double lnv12diff = lnv1 - lnv2;
  double lnv13diff = lnv1 - lnv3;

  double tk12e = (1 / tk1) - (1 / tk2);
  double tk13e = (1 / tk1) - (1 / tk3);

  obj->_c = (tk12e - lnv12diff * tk13e / lnv13diff) / ((lnv1p3 - lnv2p3) - lnv12diff * (lnv1p3 - lnv3p3) / lnv13diff);
  obj->_b = (tk12e - obj->_c * (lnv1p3 - lnv2p3)) / lnv12diff;
  obj->_a = 1 / tk1 - obj->_c * lnv1p3 - obj->_b * lnv1;
}

double NTC_GetTempCSteinhartHart(ntc_steinhart_hart_settings_t * obj, double value) {
  double log_value = log(value);
  double log_value3 = log_value * log_value * log_value;
  return 1.0 / (obj->_a + obj->_b * log_value + obj->_c * log_value3) - NTC_K_OFFSET;
}

double NTC_GetTempCSteinhartHartBParam(ntc_steinhart_hart_settings_t * obj, double value) {
  double tk1 = obj->temp_c_1 + NTC_K_OFFSET;
  return 1 / (1 / tk1 + 1.0 / obj->b_coefficient * log(value / obj->value_1)) - NTC_K_OFFSET;
}
