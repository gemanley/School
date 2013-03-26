#ifndef SERIAL_H
#define SERIAL_H

#define FOSC 16000000// Clock Speed
#define BAUD 57600

void init_USART( unsigned int ubrr );
void USART_Transmit( unsigned char data );
unsigned char USART_Receive();
void Transmit_String(char *str);

int calcUBRR();

#endif