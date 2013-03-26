#include <inttypes.h>
#include <util/delay.h>

// Wait for "count" ms.
// Should be more robust than wait_ms
void delay_ms(uint16_t count);

// Wait for "count" microseconds
void delay_us(uint16_t count); 

/// Blocks for a specified number of milliseconds
void wait_ms(unsigned int time_val);

/// Shaft encoder initialization
void shaft_encoder_init(void);

/// Shaft encoder read function
int8_t read_shaft_encoder(void);

/// Initialize Stepper Motor
void stepper_init(void);

/// Stepper motor move function
void move_stepper_motor_by_step(int num_steps, int direction);

/// Initialize PORTC, which is used by the push buttons
void init_push_buttons(void);

/// Return the position of button being pushed
/**
 * Return the position of button being pushed.
 * @return the position of the button being pushed.  A 1 is the rightmost button.  0 indicates no button being pressed
 */
uint8_t read_push_buttons(void);
