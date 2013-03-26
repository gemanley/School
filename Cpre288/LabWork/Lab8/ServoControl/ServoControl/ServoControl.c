/*
 * ServoControl.c
 *
 * Created: 10/16/2012 6:16:43 PM
 *  Author: lbreuer
 */ 


#include <avr/io.h>
#include "util.h"
#include "lcd.h"
#include "servo.h"

int main(void)
{
	lcd_init();
	timer3_init();
	init_push_buttons();

	int inc = 1;
	int count = 800;
	int degree = countConvert(count);

	move_servo(degree);
	while(1)
	{
		lprintf("Count: %d\n Direction: %d", count, inc);
		switch(read_push_buttons())
		{
			case '1':
			count += inc * 20;
			move_servo(countConvert(count));
			break;
			case '2':
			count += inc * 50;
			move_servo(countConvert(count));
			break;
			case '3':
			count += inc * 100;
			move_servo(countConvert(count));
			break;
			case '4':
			inc = -1 * inc;
			break;
		}

	}
}