/*
 * Final_Project_Slave.c
 *
 * Created: 9/22/2021 12:17:05 AM
 * Author : TAI
 */ 

#include <avr/io.h>
#include "MCAL/SPI/SPI.h"
#include "MCAL/USART/USART.h"


int main(void)
{
	
	USART_Init(103);
	SPI_MasterInit();
	
	unsigned char cData;
	
    while (1) 
    {
		cData=USART_Receive();
		SPI_MasterTransmit(cData);
    }
}

