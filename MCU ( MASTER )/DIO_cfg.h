/*
 * DIO_cfg.h
 *
 * Created: 1/12/2020 10:37:48 PM
 *  Author: Karim
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct{
	DIO_DirTypes PinDir;
	STD_LevelTypes PinLevel;
}DIO_PinCFG;

#define PINCOUNT 32

void DIO_Init(void);




#endif /* DIO_CFG_H_ */