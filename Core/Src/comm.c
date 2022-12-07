#include "comm.h"

static CAN_RxHeaderTypeDef CANRxHeader;
static CAN_TxHeaderTypeDef CANTxHeader;

uint8_t COMM_CANTxData[8];
uint8_t COMM_CANRxData[8];

static uint32_t CANTxMailbox;

void COMM_init(void) {
  HAL_CAN_Start(&COMM_CAN_HANDLE);
  HAL_CAN_ActivateNotification(&COMM_CAN_HANDLE, CAN_IT_RX_FIFO0_MSG_PENDING);

  CANTxHeader.DLC = 8;
  CANTxHeader.IDE = CAN_ID_STD;
  CANTxHeader.RTR = CAN_RTR_DATA;
  CANTxHeader.StdId = 0x666;
}

void COMM_setupCANFilter(void) {
  uint16_t canID = (COMM_CAN_ID_TARGET_BASE) << 5;

  CAN_FilterTypeDef canFilterConfig;
  canFilterConfig.FilterBank = 0; // 14
  canFilterConfig.FilterMode = CAN_FILTERMODE_IDLIST; // CAN_FILTERMODE_IDMASK
  canFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT; // CAN_FILTERSCALE_32BIT
  canFilterConfig.FilterIdHigh = canID;
  canFilterConfig.FilterIdLow = canID;
  canFilterConfig.FilterMaskIdHigh = canID;
  canFilterConfig.FilterMaskIdLow = canID;
  canFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
  canFilterConfig.FilterActivation = ENABLE;

  if (HAL_CAN_ConfigFilter(&COMM_CAN_HANDLE, &canFilterConfig) != HAL_OK) {
    /* Filter configuration Error */
    Error_Handler();
  }
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &CANRxHeader, COMM_CANRxData);
}
