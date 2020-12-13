/*
 * DIO_cfg(SLAVE).c
 *
 * Created: 1/12/2020 10:37:08 PM
 *  Author: Karim
 */ 

#include "DIO_cfg.h"

const DIO_PinCFG PinCfg[] = 
{
	//PORTA
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Input,STD_low},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	//PORTB
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Input,STD_low},
	{Input,STD_low},
	{Output,STD_high},
	{Input,STD_low},
	//PORTC
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},	
	//PORTD
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high}
};

void DIO_Init()
{
	Uint8 count = 0;
	DIO_PortTypes Portx;
	DIO_channelTypes channelPos;
	for(count=DIO_channelA0;count<PINCOUNT;count++){
		Portx = count/8;
		channelPos = count%8;
		switch(Portx)
		    {
			case DIO_PortA:
			if(PinCfg[count].PinDir == Output){
				SET_BIT(DDRA_Reg,channelPos);
			}
			else{
				CLEAR_BIT(DDRA_Reg,channelPos);
			}
			break;
			case DIO_PortB:
			if(PinCfg[count].PinDir == Output){
				SET_BIT(DDRB_Reg,channelPos);
			}
			else{
				CLEAR_BIT(DDRB_Reg,channelPos);
			}
			break;
			case DIO_PortC:
			if(PinCfg[count].PinDir == Output){
				SET_BIT(DDRC_Reg,channelPos);
			}
			else{
				CLEAR_BIT(DDRC_Reg,channelPos);
			}
			break;
			case DIO_PortD:
			if(PinCfg[count].PinDir == Output){
				SET_BIT(DDRD_Reg,channelPos);
			}
			else{
				CLEAR_BIT(DDRD_Reg,channelPos);
			}
			break;
		}
	}
}