/************************************************************************/
/* IRSensor.c                                                                     */
/************************************************************************/

#include <avr/io.h>
#include <math.h>
#include "util.h"
#include "IRSensor.h"

void init_ADC(){
	// REFS=11, ADLAR=0, MUX don’t care

	int channel = 2;
	ADMUX = (3 << REFS0) | channel;

	// ADEN=1, ADFR=0, ADIE=0, ADSP=111  prescalor 128
	// See page 246 of user guide
	ADCSRA = (1 << ADEN) | (7 << ADPS0);
}

unsigned ADC_read()
{
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC));
	unsigned int sample = ADCW;
	return ADC;
}

unsigned int ir_distance()
{
	float sample = (float) ADC_read();
	float distance_cm = 29698*pow(sample,-1.163);
	return distance_cm;
}