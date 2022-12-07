#ifndef CANRELAY_COMM_H
#define CANRELAY_COMM_H

#include "main.h"
#include "stm32f2xx_hal.h"

#define COMM_CAN_ID_TARGET_BASE 0x640

#define COMM_CAN_HANDLE hcan1
extern CAN_HandleTypeDef COMM_CAN_HANDLE;

void COMM_init(void);
void COMM_setupCANFilter(void);

#endif //CANRELAY_COMM_H
