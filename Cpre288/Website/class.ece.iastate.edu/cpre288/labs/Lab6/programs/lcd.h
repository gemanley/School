#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define HD_LCD_CLEAR 0x01
#define HD_RETURN_HOME 0x02
#define HD_CURSOR_SHIFT_DEC 0x05
#define HD_CURSOR_SHIFT_INC 0x07
#define HD_DISPLAY_CONTROL 3
#define HD_DISPLAY_ON 2
#define HD_CURSOR_ON 1
#define HD_BLINK_ON 0
#define HD_CURSOR_MOVE_LEFT 0x10
#define HD_CURSOR_MOVE_RIGHT 0x14
#define HD_DISPLAY_SHIFT_LEFT 0x18
#define HD_DISPLAY_SHIFT_RIGHT 0x1C

/// Initializes PORTA to communicate with LCD controller
void lcd_init(void);

/// Sets cursor position to left side of a given line
void lcd_home_line1(void);
void lcd_home_line2(void);
void lcd_home_line3(void);
void lcd_home_line4(void);

/// Prints a string to the lcd; Google "printf" for documentation.
void lprintf(const char *formatter, ...);

/// Prints a string of characters starting at the current cursor position
void lcd_puts(char *data);

/// Prints one character at the current cursor position
void lcd_putc(char data);

/// Clears the LCD
void lcd_clear(void);

/// Submits command to LCD controller
void lcd_command(char data);
