/*
 * PushButtons.c
 *
 * Created: 9/4/2012 7:17:46 PM
 *  Author: lbreuer
 */ 


#include <avr/io.h>

#include "lcd.h"
#include "util.h"

void main() {
	lcd_init();
	init_push_buttons();
	shaft_encoder_init();
	stepper_init();

	int sum = 0;
	int direction = 0;
	
	
	while(1) { // loop indefinitely
		
		char button = read_push_buttons();
		direction = read_shaft_encoder();
		sum += direction;
		move_stepper_motor_by_step(10, direction);
		lprintf("Button: %c  Shaft Encoder: %d", button, sum);
	}
}