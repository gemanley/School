/*
 * sensor.c
 *
 * Created: 10/8/2012 9:22:22 AM
 *  Author: lbreuer
 */ 


#include <avr/io.h>
#include <math.h>
#include "util.h"
#include "lcd.h"
#include "IRSensor.h"

int main(void)
{
	lcd_init();
	ADC_init();
	
	float sum_dis = 0;
	float avg_dis = 0;
	
    while(1)
    {
       for(int i = 0;i<5;i++)
       {
	       sum_dis += ir_distance();
	       wait_ms(50);
       }
      
	    avg_dis = (sum_dis/5);
		lprintf("%u, %f cm", ADC_read(), avg_dis);
		wait_ms(300);
		avg_dis = 0;
		sum_dis = 0;
    }
}



