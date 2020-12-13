/*
 * spimaster.h
 *
 * Created: 4/12/2020 7:35:49 AM
 *  Author: Karim
 */ 

#include <avr/io.h>
#include "DIO.h"

#ifndef SPIMASTER_H_
#define SPIMASTER_H_

#define SCK  DIO_channelB7
#define MISO DIO_channelB6
#define MOSI DIO_channelB5
#define SS   DIO_channelB4

#define SlaveEn() ( DIO_Write(SS,STD_low) )
#define SlaveDis() ( DIO_Write(SS,STD_high) )

void SPI_Init(Uint8);
void SPI_Write(Uint8 data);
Uint8 SPI_Receive();



#endif /* SPIMASTER_H_ */