/*
 * Sweep.c
 *
 * Created: 10/23/2012 6:03:58 PM
 *  Author: lbreuer
 */ 


#include <avr/io.h>
#include "ping.h"
#include "util.h"
#include "lcd.h"
#include "IRSensor.h"
#include "servo.h"
#include "serial.h"

#define BAUD 57600

int main(void)
{
	//lprintf("%d", 4);
	init_ADC();
	init_timer3();
	init_timer();
	init_USART(calcUBRR(BAUD));
	char * str = "Degrees\tIR Distance (cm)\tSonar Distance (cm)\n\n\r";
	move_servo(0);
	char degrees = 0;
    while(1)
    {
        //send_pulse();
		Transmit_String(str);
		sprintf(str, "%d\t%d\t%d\n\r", degrees, ir_distance(), time2dist(ping_read()));
		move_servo(degrees);
		degrees += 2;
		if(degrees > 180)
			break;
    }
}