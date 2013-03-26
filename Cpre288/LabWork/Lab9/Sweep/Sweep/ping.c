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

char working;
char overflows;
volatile unsigned rising_time;
volatile unsigned falling_time;

char getOverflow()
{
	return overflows;
}

void init_timer()
{
	overflows = 0;
	TCCR1A = 0x00;
	TCCR1B = (2<<CS10)|(0<<WGM12);; // Enable interrupt, choose right edge select, WGM bits = 0, choose good clock select
	sei();
}

ISR (TIMER1_CAPT_vect)
{
	cli();
	int event_time = ICR1;

	if(TCCR1B &(1<<ICES1))
	{
		rising_time = event_time;
		TCCR1B &= ~(1<<ICES1);
		
	}
	else
	{
		falling_time = event_time;
		working = 0;
		TIMSK &= ~(1<<TICIE1);
	}
	TIFR |= (1<<ICF1);
	sei();
}

ISR(TIMER1_OVF_vect)
{
	overflows++;
}

unsigned ping_read()
{
	DDRD |= 0x10;
	PORTD |= 0x10;
	wait_ms(1);
	PORTD &= 0xEF;
	DDRD &= 0xEF;
	
	TCNT1 = 0;
	
	TIFR |= (1<<ICF1);
	TCCR1B |= (1<<ICES1);
	TCCR1B |= (1 <<1);
	TIMSK |= (1<<TICIE1);
	working = 1;
	//while (working);
	return falling_time - rising_time;
}

void send_pulse()
{
	DDRD |= 0x10;
	PORTD |= 0x10;
	wait_ms(1);
	PORTD &= 0xEF;
	DDRD &= 0xEF;
	
	TCNT1 = 0;
	
	TIFR |= (1<<ICF1);
	TCCR1B |= (1<<ICES1);
	TCCR1B |= (1 <<1);
	TIMSK |= (1<<TICIE1);
	working = 1;
	while (working);
}

unsigned long time2dist( unsigned long time )
{
	
	return (time*272000.0)/32000000.0;
	//return (time / 2 * 340 * 100 / 1000.0 / 1000.0);
}