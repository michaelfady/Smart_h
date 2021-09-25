/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: ahmed
 */


#include <avr/io.h>
#include <util/delay.h>
#include "MCAL/Dio/Dio.h"
#include "MCAL/SPI/SPI.h"
#include "BIT_MATH.h"
#include "STD_Types.h"


int main() {

	// PORTS Configuration & Initialization.
	Dio_init();
	// SPI_SLAVE Intializtaion.
	SPI_SLAVE_INIT();

	while (1) {
		_delay_ms(10);
		uint8 data = SPI_SLV_RECEV();

		if (data == '1') {					// Toggling 1st Device.
			Dio_Toggle_Channel(LED_0);
		} else if (data == '2') {			// Toggling 2nd Device.
			Dio_Toggle_Channel(LED_1);
		} else if (data == '3') {			// Switching Both Devices ON.
			Dio_write_PORT(LED_0, HIGH);
			Dio_write_PORT(LED_1, HIGH);
		} else if (data == '4') {			// Switch Devices OFF.
			Dio_write_PORT(LED_0, LOW);
			Dio_write_PORT(LED_1, LOW);
		}
	}
}
