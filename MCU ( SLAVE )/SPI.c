/*
 * SPI.c
 *
 * Created: 4/12/2020 3:14:59 AM
 *  Author: Karim
 */ 

#include "SPI.h"


void SPI_Init(Uint8 state)
{
	switch (state)
	{
		
		case 'M' :
		SPCR |= (1<<SPE)|(1<<MSTR);	/* Enable SPI in master mode with Fosc/16 */
		SlaveDis();
		break;
		
		case 'S' :
		SPCR |= (1<<SPE);//Enable the SPI
		break;

	}
}

void SPI_Write(Uint8 data)		/* SPI write data function */
{
	char flush_buffer;
	SPDR = data;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */			
	flush_buffer = SPDR; /* Flush received data */
}

Uint8 SPI_Receive()			/* SPI Receive data function */
{
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}