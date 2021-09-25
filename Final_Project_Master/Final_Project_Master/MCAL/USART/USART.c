/*
 * USART.c
 *
 * Created: 9/22/2021 12:17:05 AM
 * Author : TAI
 */


#include "USART.h"

void USART_Init(unsigned int baud) {
/* Set baud rate */
UBRRH = (unsigned char)(baud>>8);
UBRRL = (unsigned char)baud;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}


void USART_Transmit_5_8(unsigned char data) {
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR = data;
}


unsigned char USART_Receive(void) {
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
return UDR;
}
