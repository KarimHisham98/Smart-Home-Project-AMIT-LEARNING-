/*
 * MCU ( MASTER ).c
 *
 * Created: 4/12/2020 4:41:21 AM
 * Author : Karim
 */ 


#include "SPI.h"
#include "DIO.h"
#include "util/delay.h"
#include "USART_RS232.h"
#include <avr/interrupt.h>
#define F_CPU 16000000UL

int main(void)
{
	DIO_Init();
	SPI_Init('M');
	SlaveEn();
	USART_Init(9600); /* initialize USART with 9600 baud rate */
	USART_SendString("    COMMANDS \n");
	USART_SendString(" f ==> Motor Forward \n");
	USART_SendString(" s ==> Motor Stop \n");
	USART_SendString(" r ==> Motor Reverse \n");
	USART_SendString(" l ==> Lamp On \n");
	USART_SendString(" d ==> Lamp Off \n");
	USART_SendString(" t ==> Room Temprature \n");
	while (1)
	{
		Uint8 Data_in;
		Data_in = USART_RxChar();
		_delay_ms(200);
		SPI_Write(Data_in);
	}
	
}
