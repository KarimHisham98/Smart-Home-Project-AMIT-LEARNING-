/*
 * Motor.c
 *
 * Created: 12/12/2020 6:55:02 PM
 *  Author: Karim
 */ 
#include "Motor.h"
#include "DIO.h"


#define IN1 DIO_channelA0
#define IN2 DIO_channelA1
#define ENA DIO_channelA2

#define F DIO_channelD5
#define R DIO_channelD6
#define S DIO_channelD7

void MotorCW()
{
    DIO_Write(IN1,STD_high);
    DIO_Write(IN2,STD_low);
    DIO_Write(ENA,STD_high);
	
	DIO_Write(F,STD_high);
	DIO_Write(R,STD_low);
	DIO_Write(S,STD_low);
}

void MotorCCW(void)
{
	DIO_Write(IN1,STD_low);
	DIO_Write(IN2,STD_high);
	DIO_Write(ENA,STD_high);
	
	DIO_Write(F,STD_low);
	DIO_Write(R,STD_high);
	DIO_Write(S,STD_low);
}
void MotorStop(void)
{
	DIO_Write(IN1,STD_low);
	DIO_Write(IN2,STD_low);
	DIO_Write(ENA,STD_low);
	
	DIO_Write(F,STD_low);
	DIO_Write(R,STD_low);
	DIO_Write(S,STD_high);
}