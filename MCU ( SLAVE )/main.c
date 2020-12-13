/*
 * main.c
 *
 * Created: 1/12/2020 9:24:50 PM
 * Author : Karim
 */ 

#include <stdlib.h>
#include <avr/io.h>
#include "SPI.h"
#include "DIO.h"
#include "util/delay.h"
#include "Motor.h"
#include "ADC.h"
#define F_CPU 16000000UL

int main(void)
{
	
	DIO_Init();
	SPI_Init('S');	LCD_Init();	ADC_Init();	//LCD_clr();	//LCD_cmd(0x85);	//LCD_StringPos("welcome home",1,2);
	
	Uint8 DATA_IN;
	Uint16 temp=0;
	Uint8 buffer[50];

	
	while(1)
	{
		
		Uint8 character = SPI_Receive();
		
		if(character == 'f')
		{
			LCD_clr();
			LCD_StringPos("Motor Forward",1,2);
			MotorCW();
		}
		
		if(character == 'r')
		{
			LCD_clr();
			LCD_StringPos("Motor Reverse",1,2);
			MotorCCW();
		}
		
		if(character == 's')
		{
			LCD_clr();
			LCD_StringPos("Motor Stop",1,2);
			MotorStop();
		}
		
		if(character == 'l')
		{
			LCD_clr();
			LCD_StringPos("Light on",1,2);
			DIO_Write(DIO_channelC3,STD_high);
			
		}
		
		if(character == 'd')
		{
			LCD_clr();
			LCD_StringPos("Light off",1,2);
			DIO_Write(DIO_channelC3,STD_low);
		}
		
		if (character =='t')
		{
			while(1)
			{
				LCD_clr();
				temp = ADC_Read(3);
				temp /=4;				itoa(temp,buffer,10);				LCD_StringPos("Temprature =", 1, 1);				LCD_string(buffer);
				if( temp > 60 )
				{
					DIO_Write(DIO_channelC5,STD_high);
					LCD_StringPos("Danger", 2, 5);
				}
				else if( temp < 60 )
				{
					DIO_Write(DIO_channelC5,STD_low);
				}
				_delay_ms(10000);
				LCD_clr();
			}
		}
		
		
		
		
	
	}
		
}


