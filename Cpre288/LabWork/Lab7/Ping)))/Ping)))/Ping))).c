/*
 * Ping___.c
 *
 * Created: 10/9/2012 5:51:01 PM
 *  Author: lbreuer
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "util.h"
#include "lcd.h"
#include "ping.h"

int main(void)
{
	lcd_init();
	timer_init();
	while(1)
	{
		unsigned pulse_width = ping_read();
		unsigned long distance = time2dist(pulse_width);
		lprintf("Delta: %d \nDistance: %d \nOverflows: %d", pulse_width, distance, getOverflow());
		wait_ms(300);
	}
}