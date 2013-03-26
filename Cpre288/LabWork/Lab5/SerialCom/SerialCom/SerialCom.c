/*
 * SerialCom.c
 *
 * Created: 9/25/2012 6:31:07 PM
 *  Author: lbreuer
 */ 


#include <avr/io.h>
#include "lcd.h"

int main( void )
{
	char buffer[21] = {'\0'};
	int i = 0;
	USART_Init ( calcUBRR() );
	init_push_buttons();
	lcd_init();
	while(1){
		switch(read_push_buttons())
		{
			case '6': USART_Transmit('Y');
			break;
			
			case '5': USART_Transmit('N');
			break;
			
			case '4': Transmit_String("AHHHH!!!!");
			break;
			
			case '3': Transmit_String("This");
			break;
			
			case '2': Transmit_String("computer is");
			break;
			
			case '1': Transmit_String("broken!");
			break;
					}
					wait_ms(100);
					/*
		unsigned char new_letter = USART_Receive();
		if(new_letter != 13)
		{
			buffer[i++] = new_letter;
			
		}			
		USART_Transmit(new_letter);
		lprintf("%d, %c", i, new_letter);
		if(i == 20 || new_letter == 13)
		{
			if(new_letter == 13)
			{
				USART_Transmit(10);
			}
			i = 0;
			lprintf("%s", buffer);
			for(int j=0;j<20;j++)
			{
				buffer[j] = 0;
			}
		}
		*/
	}	
}