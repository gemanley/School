/**
 * clock-intr.c: timer- and interrupt-based clock program
 * This is skeleton code. You need to make it complete.
 *
 * @author Zhao Zhang
 * @date 06/26/2012
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "lcd.h"
#include "util.h"

#warning "CLOCK_COUNT may not be defined correctly" // delete this line after defining CLOCK_COUNT
#warning "CHECK_COUNT may not be defined correctly" // delete this line after defining CHECK_COUNT
#define CLOCK_COUNT 50 // TODO - Edit this to be equal to the number of Timer Increments in 1 second
#define CHECK_COUNT 10 // TODO - Edit this to be equal to the number of Timer Increments in 200 ms

/// Initialize the timers
void timer_init(void) {
	// set up timer 1: WGM1 bits = 0100, CS = 101, set OCR1A, set TIMSK
	TCCR1A = 0b00000000;		// WGM1[1:0]=00
	TCCR1B = 0b00001101;		// WGM1[3:2]=01, CS=101
	OCR1A = CLOCK_COUNT - 1; 	// counter threshold for clock
	TIMSK = _BV(OCIE1A);		// enable OC interrupt, timer 1, channel A

	// set up timer 3: WGM1 bits = 0100, CS = 101, set OCR3A, set TIMSK
	TCCR3A = 0b00000000;		// WGM1[1:0]=00
	TCCR3B = 0b00001101;		// WGM1[3:2]=01, CS=101
	OCR3A = CHECK_COUNT - 1; 	// counter threshold for checking push button
	ETIMSK = _BV(OCIE3A);		// enable OC interrupt, timer 3, channel A

	sei();
}


/**
 * Timer interrupt source 1: the function will be called every one second
 * (you need define CLOCK_COUNT correctly) 
 */
ISR (TIMER1_COMPA_vect) {
	
	// DELETE ME - About the ISR macro
	// ----------------------------------------
	// ISR is a macro defined in interrupt.h.  You should not call an ISR function.
	// The ATmega128 is specifically built to run these functions for you when an
	// event occurs.
	//
	// ISRs (Interrupt Service Routines) are interrupt handlers specific to the platform 
	// on which we're working. In this case, this function will be run when the value 
	// of Timer1 matches OCR1A.
	//
	// OCR1A = Output Compare Register A for timer1
	//
	// For more information, consult the Atmel User Guide.
	//

	// Be sure to correctly initialize CLOCK_COUNT and CHECK_COUNT so these interrupts 
	// get called at the right frequency.

}




/**
 * Timer interrupt source 2: the function will be called every 200 milliseconds
 * (you need define CHECK_COUNT correctly) 
 */
ISR (TIMER3_COMPA_vect) {

	// Insert interrupt handler code for checking push buttons here

}


/// Displays the time of day on the LCD
/**
 * Displays the time of day on the LCD in the format "HH:MM:SS".  Allows the user to adjust the time using
 * the push buttons.  The push buttons will be checked every 200ms, and will update the screen every time
 * the time is adjusted.
 *
 * SW6 increment hours
 * SW5 decrement hours
 * SW4 increment minutes
 * SW3 decrement minutes
 * SW2 increment seconds
 * SW1 decrement seconds
 */
int main() {

	lcd_init();
	timer_init();
	init_push_buttons();
	
	while (1) {
		/* Add your code here */
	}
}
