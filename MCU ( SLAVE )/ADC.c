/*
 * ADC.c
 *
 * Created: 1/12/2020 10:33:59 PM
 *  Author: Karim
 */  

#include "ADC.h"
#include "DIO.h"
#include <avr/io.h>


void ADC_Init()
{
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADEN); // enable
}


Uint16 ADC_Read(Uint8 channel)
{
	Uint16 Data=0;
	
	
	ADMUX = (ADMUX & 0b11100000)|(channel & 0b00011111);
	SET_BIT(ADCSRA,ADSC);
	
	while (!((ADCSRA) & (1<<ADIF)));
	SET_BIT(ADCSRA,ADIF);
	
	Data = ADCL;
	Data |= (ADCH << 8);
	
	return Data;
	
}
