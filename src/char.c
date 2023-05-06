#include "led.h"
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/drivers/gpio.h>
#include <dk_buttons_and_leds.h>
extern int cTemp;
static ssize_t led_rd(struct bt_conn *conn,
                        const struct bt_gatt_attr *attr,
                        void *buff,
                        uint16_t len,
                        uint16_t offset)
{
    const char *value =attr->user_data;

    printk("led read button pressed\n");
    dk_set_led_on(2);
k_sleep(K_MSEC(1000));
dk_set_led_off(2);

    return bt_gatt_attr_read(conn, attr, buff, len, offset, attr->user_data, strlen(attr->user_data));

}

static ssize_t led_wr(struct bt_conn *conn,
                        const struct bt_gatt_attr *attr,
                        void *buff,
                        uint16_t len,
                        uint16_t offset)
{
    const char *value = attr->user_data;
    printk("led write is done : %s\n",buff);
    
dk_set_led_on(2);
k_sleep(K_MSEC(1000));
dk_set_led_off(2);
return 0;
}


uint8_t led_val[5]="hi\0";
BT_GATT_SERVICE_DEFINE(led,
BT_GATT_PRIMARY_SERVICE(BT_UUID_LED),
// BT_GATT_CCC(lbslc_ccc_cfg_changed,
// BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
BT_GATT_CHARACTERISTIC(BT_UUID_LED_ON,BT_GATT_CHRC_READ|BT_GATT_CHRC_WRITE|BT_GATT_CHRC_WRITE_WITHOUT_RESP ,BT_GATT_PERM_READ|BT_GATT_PERM_WRITE,
led_rd,led_wr,&cTemp),
);