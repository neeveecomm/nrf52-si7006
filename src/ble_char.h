
#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/types.h>




#define ESS_UUID_BASE         BT_UUID_DECLARE_16(0x181A)
#define BT_UUID_TIMER_VAL 0x1234

#define BT_UUID_TIMER \
	BT_UUID_DECLARE_16(BT_UUID_TIMER_VAL)


#ifdef __cplusplus
}
#endif

void MEASURE_TEMPERATURE_NO_HOLD_MASTER_MODE (void);
void MEASURE_RELATIVE_HUMIDITY_NO_HOLD_MASTER_MODE (void);
void si7006(void);
