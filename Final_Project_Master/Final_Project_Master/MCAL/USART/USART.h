/*
 * USART.h
 *
 * Created: 9/22/2021 12:17:05 AM
 * Author : TAI
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

#include <avr/io.h>

void USART_Init(unsigned int baud);
void USART_Transmit_5_8(unsigned char data);
unsigned char USART_Receive(void);

#endif /* MCAL_USART_USART_H_ */
