/*
 * SerialCom.c
 *
 * Created: 9/25/2012 6:31:07 PM
 *  Author: lbreuer
 */ 


#include <avr/io.h>
#include"lcd.h"

#define FOSC 16000000// Clock Speed
#define BAUD 57600
#define MYUBRR 34

void USART_Init( unsigned int ubrr );
void USART_Transmit( unsigned char data );
unsigned char USART_Receive();
void Transmit_String(char *str);

int main( void )
{
	char buffer[21] = {'\0'};
	int i = 0;
	USART_Init ( MYUBRR );
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
void Transmit_String(char *str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		USART_Transmit(str[i]);
		lprintf(str);
	}
}

void USART_Init( unsigned int ubrr )
{

/* Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/* Enable receiver and transmitter */
UCSR0B = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<USBS)|(3<<UCSZ0);
UCSR0A = (1<<U2X);
}

void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !( UCSR0A & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR0 = data;
}

unsigned char USART_Receive()
{

/* Wait for data to be received */
while ( !(UCSR0A & (1<<RXC)) );
/* Get and return received data from buffer */
return UDR0;
}

