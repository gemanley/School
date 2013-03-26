/*
 * servo.c
 *
 * Created: 10/16/2012 6:18:21 PM
 *  Author: lbreuer
 */ 


#include "servo.h"
#include <avr/io.h>
#include <math.h>

unsigned pulse_interval = 43000;
unsigned mid_point = 1500;

void init_timer3()
{
	OCR3A = pulse_interval-1;  // number of cycles in the interval
	//OCR3B = mid_point-1;   // if you want to move servo to the middle
	TCCR3A = 0x23;   // set COM and WGM (bits 3 and 2)
	TCCR3B = 0x1A;   // set WGM (bits 1 and 0) and CS
	TCCR3C = _BV(FOC3B);
	
	// it’s necessary to set the OC3B (PE4) pin as the output
	DDRE |= _BV(4);   // set Port E pin 4 (OC3B) as output
}

void move_servo(unsigned degree)
{
	unsigned pulse_width;   // pulse width in cycles
	pulse_width = 900 + 20 * degree;     // calculate pulse width
	//pulse_width = 4400;
	OCR3B = pulse_width-1;  // set pulse width
	wait_ms(200);

	// you need to call wait_ms(20) here to enforce a delay for the servo to
	/// move to the position
}

int countConvert(int c)
{
	return (c-900)/20;
}