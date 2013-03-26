#include "lcd.h"
#include "util.h"

/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Chad Nelson
 * @date 06/26/2012
 */
int main (void) {
	// Initialize the the LCD.  This also clears the screen.
	lcd_init(); 

	// Clear the LCD screen and print "Hello, world" on the LCD
	lprintf("Hello, world");

	// Notes: Open util.h to see what functions are available for you to use.
	// You will need to use these functions in future labs.
    
	// It is recommended that you use only lcd_init() and lprintf() from lcd.h.
    
	return 0;
}
