/*
 * ADC.h
 *
 * Created: 1/12/2020 10:33:59 PM
 *  Author: Karim
 */  


#ifndef ADC_H_
#define ADC_H_

#include "DIO.h"

void ADC_Init();
Uint16 ADC_Read(Uint8 channel);

#endif /* ADC_H_ */