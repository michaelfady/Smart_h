/*
 * SPI.h
 *
 * Created: 9/22/2021 12:24:06 AM
 *  Author: TAI
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);

#endif /* SPI_H_ */