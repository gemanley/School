/*
 * hw5.c
 *
 * Created: 10/3/2012 4:50:14 PM
 *  Author: lbreuer
 */ 


#include <avr/io.h>

int main(void)
{
    while(1)
    {
       char byte = -24;
	   short ADC_input = 1020;
	   unsigned n;
	   
	   n = (int) byte;
	   printf("%d", n);
	   

    }
}