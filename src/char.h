/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef BT_LBS_H_
#define BT_LBS_H_

/**@file
 * @defgroup bt_lbs LED Button Service API
 * @{
 * @brief API for the LED Button Service (LBS).
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/types.h>


#define BT_UUID_LED           BT_UUID_DECLARE_128(BT_UUID_LED_VAL)
#define BT_UUID_LED_ON    BT_UUID_DECLARE_128(BT_UUID_LED_ON_VAL)

#define BT_UUID_LED_VAL \
	BT_UUID_128_ENCODE(0x00001526, 0x1212, 0xefde, 0x1523, 0x785feabcd123)

#define BT_UUID_LED_ON_VAL \
	BT_UUID_128_ENCODE(0x00001527, 0x1212, 0xefde, 0x1523, 0x785feabcd123)

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* BT_LBS_H_ */

void MEASURE_TEMPERATURE_NO_HOLD_MASTER_MODE (void);
void MEASURE_RELATIVE_HUMIDITY_NO_HOLD_MASTER_MODE (void);
void si7004(void);
