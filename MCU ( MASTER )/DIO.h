/*
 * DIO.h
 *
 * Created: 1/12/2020 10:36:06 PM
 *  Author: Karim
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_cfg.h"


void DIO_Write(DIO_channelTypes channelId,STD_LevelTypes Level);
STD_LevelTypes DIO_Read(DIO_channelTypes channelId);
void DIO_Toggle(DIO_channelTypes channelId);



#endif /* DIO_H_ */