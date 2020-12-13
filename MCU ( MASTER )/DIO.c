/*
 * DIO.c
 *
 * Created: 1/12/2020 10:33:59 PM
 *  Author: Karim
 */ 

#include "DIO.h"

void DIO_Write(DIO_channelTypes channelId,STD_LevelTypes Level)
{
	DIO_PortTypes Portx = channelId/8;
	DIO_channelTypes channelPos = channelId%8;
	switch(Portx)
	{
		case DIO_PortA:
		if(Level == STD_high){
			SET_BIT(PORTA_Reg,channelPos);
		}
		else{
			CLEAR_BIT(PORTA_Reg,channelPos);
		}
		break;
		case DIO_PortB:
		if(Level == STD_high){
			SET_BIT(PORTB_Reg,channelPos);
		}
		else{
			CLEAR_BIT(PORTB_Reg,channelPos);
		}
		break;
		case DIO_PortC:
		if(Level == STD_high){
			SET_BIT(PORTC_Reg,channelPos);
		}
		else{
			CLEAR_BIT(PORTC_Reg,channelPos);
		}
		break;
		case DIO_PortD:
		if(Level == STD_high){
			SET_BIT(PORTD_Reg,channelPos);
		}
		else{
			CLEAR_BIT(PORTD_Reg,channelPos);
		}
		break;
	}
}

STD_LevelTypes DIO_Read(DIO_channelTypes channelId)
{
	STD_LevelTypes channelBit = STD_low;
	DIO_PortTypes Portx = channelId/8;
	DIO_channelTypes channelPos = channelId%8;
	switch(Portx)
	{
		case DIO_PortA:
		channelBit = READ_BIT(PINA_Reg,channelPos);
		break;
		case DIO_PortB:
		channelBit = READ_BIT(PINB_Reg,channelPos);
		break;
		case DIO_PortC:
		channelBit = READ_BIT(PINC_Reg,channelPos);
		break;
		case DIO_PortD:
		channelBit = READ_BIT(PIND_Reg,channelPos);
		break;
	}
	return(channelBit);
}

void DIO_Toggle(DIO_channelTypes channelId)
{
	DIO_PortTypes Portx = channelId/8;
	DIO_channelTypes channelPos = channelId%8;
	switch(Portx)
	{
		case DIO_PortA:
		Toggle_BIT(PORTA_Reg,channelPos);
		break;
		case DIO_PortB:
		Toggle_BIT(PORTB_Reg,channelPos);
		break;
		case DIO_PortC:
		Toggle_BIT(PORTC_Reg,channelPos);
		break;
		case DIO_PortD:
		Toggle_BIT(PORTD_Reg,channelPos);
		break;
	}
}