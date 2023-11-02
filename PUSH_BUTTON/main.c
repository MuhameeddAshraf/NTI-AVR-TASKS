/*
 * main.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"



int main(void){

	DIO_voidSetPortDirection(DIO_u8PORTC,DIO_u8PORTOUTPUT);
	DIO_voidSetPortDirection(DIO_u8PORTD,DIO_u8PORTINPUT);
	DIO_voidSetPortValue(DIO_u8PORTD,DIO_u8HIGH);
	int read_pin  ;

	while(1){

		read_pin = DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0);
		if ( 0 == read_pin){
			_delay_ms(100);
			read_pin = DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0);
			if(0 == read_pin){
				DIO_voidSetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8HIGH);
			}

		}
		else{
				DIO_voidSetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8LOW);

		}
	}

}
