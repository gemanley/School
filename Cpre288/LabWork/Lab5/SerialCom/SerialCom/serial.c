#include <avr/io.h>
#include "serial.h"

int calcUBRR()
{
	return FOSC / (8 * BAUD) - 1;
}

void Transmit_String(char *str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		USART_Transmit(str[i]);
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
