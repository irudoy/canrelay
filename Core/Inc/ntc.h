#ifndef CANRELAY_NTC_H
#define CANRELAY_NTC_H

#define NTC_K_OFFSET (273.15)

typedef struct {
  int temp_c_1;
  double value_1;
  int temp_c_2;
  double value_2;
  int temp_c_3;
  double value_3;

  int b_coefficient;

  double _a;
  double _b;
  double _c;
} ntc_steinhart_hart_settings_t;

void NTC_InitSteinhartHart(ntc_steinhart_hart_settings_t * obj);
double NTC_GetTempCSteinhartHart(ntc_steinhart_hart_settings_t * obj, double value);

double NTC_GetTempCSteinhartHartBParam(ntc_steinhart_hart_settings_t * obj, double value);

#endif //CANRELAY_NTC_H
