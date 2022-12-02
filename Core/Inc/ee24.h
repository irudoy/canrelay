#ifndef	_EE24_H
#define	_EE24_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "ee24_cfg.h"

bool ee24_isConnected(void);
bool ee24_write(uint16_t address, uint8_t *data, size_t lenInBytes, uint32_t timeout);
bool ee24_read(uint16_t address, uint8_t *data, size_t lenInBytes, uint32_t timeout);
bool ee24_eraseChip(void);

#ifdef __cplusplus
}
#endif

#endif
