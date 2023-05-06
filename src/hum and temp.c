#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/sys/printk.h>
#include "led.h"

#define     SI7006_ADDRESS       0x40                                                
#define     SI7006_MEASURE_RELATIVE_HUMIDITY_NO_HOLD_MASTER_MODE           0xF5               
#define     SI7006_MEASURE_TEMPERATURE_NO_HOLD_MASTER_MODE                 0xF3               
#define I2C_NODE DT_NODELABEL(mysensor)
 struct i2c_dt_spec dev_i2c = I2C_DT_SPEC_GET(I2C_NODE);

int cTemp;

void tt_i2c_write(uint8_t slaveAddr, uint8_t regAddr)
{
	uint8_t buf[1];

	buf[0] = regAddr;
	//buf[1] = 0;
	 i2c_write_dt(&dev_i2c, buf, sizeof(buf));
	return ;
}

uint8_t tt_i2c_read(uint8_t slaveAddr)
{
	uint8_t data;
	i2c_read_dt(&dev_i2c, &data, sizeof(data));
	return data;
}



void MEASURE_RELATIVE_HUMIDITY_NO_HOLD_MASTER_MODE (void)
 {
	 uint32_t data1;
	 uint32_t data2;

	 // Send Relative humidity measurement command, NO HOLD MASTER(0xF5)

	 		tt_i2c_write(SI7006_ADDRESS, SI7006_MEASURE_RELATIVE_HUMIDITY_NO_HOLD_MASTER_MODE);

	 // for time delay
        k_sleep(K_MSEC(1000));

	    //  DelayCount = 100000;
	    //   Delay ();


	 // Read 2 bytes of humidity data

	 // humidity msb, humidity lsb

	 		data1 = tt_i2c_read(SI7006_ADDRESS);
	        data2 = tt_i2c_read(SI7006_ADDRESS);

	 		//printf("data1 : 0x%02x\n",data1);
	 		//printf("data2 : 0x%02x\n",data2);

	 // Convert the data

	 			 int humidity = ((((data1 * 256 )+ data2) * 125) / 65536) - 6;



	 // Output data to screen
	 			printk("FOR NO HOLD MASTER MODE\n");
	 			printk("Relative Humidity : %02d percentage\n", humidity);


 }

 void MEASURE_TEMPERATURE_NO_HOLD_MASTER_MODE (void)
 {
	 uint32_t data3;
     uint32_t data4;

	 // Send temperature measurement command, NO HOLD MASTER(0xF3)

	 		tt_i2c_write(SI7006_ADDRESS, SI7006_MEASURE_TEMPERATURE_NO_HOLD_MASTER_MODE);

	 // For time delay
        k_sleep(K_MSEC(1000));
	 		//  DelayCount = 100000;
	 		//  Delay ();


	 // Read 2 bytes of temperature data

	 // humidity msb, humidity lsb


	 	         data3 =	tt_i2c_read(SI7006_ADDRESS);
	 	         data4 =	tt_i2c_read(SI7006_ADDRESS);

	 	        //printf("data3 : 0x%02x\n",data3);
	 	        //printf("data4 : 0x%02x\n",data4);


	 // Convert the data

	 			 cTemp = ((((data3 * 256) + data4) * 175.72) / 65536) - 46.85;
	 			int fTemp = ( cTemp * 1.8 )+ 32;

	 // Output data to screen
	 			printk("FOR NO HOLD MASTER MODE\n");
	 			printk("Temperature in Celsius : %02d C \n", cTemp);
	 			printk("Temperature in Fahrenheit : %02d F \n", fTemp);


 }


void si7004(void)
{
 if (!device_is_ready(dev_i2c.bus))
	{
		printk("I2C bus %s is not ready!\n\r", dev_i2c.bus->name);
		return;
	}
 MEASURE_RELATIVE_HUMIDITY_NO_HOLD_MASTER_MODE ();

	MEASURE_TEMPERATURE_NO_HOLD_MASTER_MODE ();
}
