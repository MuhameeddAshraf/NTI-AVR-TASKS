/*
 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_private.h"
#include "DIO_interface.h"

int main(void)
{
	uint8 SEGMENT[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b011111111,0b01101111};

	DIO_voidSePortDirection(DIO_u8PORTA,DIO_u8PORTOUTPUT);
	DIO_voidSePortDirection(DIO_u8PORTC,DIO_u8PORTOUTPUT);
	DIO_voidSePortDirection(DIO_u8PORTB, DIO_u8PORTOUTPUT);

/*
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN0,DIO_u8HIGH);  //RED
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN1,DIO_u8HIGH);  //YELLOW
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN2,DIO_u8HIGH);  //GREEN
*/
	while (1)
	{
	PORTB = SEGMENT[6];
	PORTB = SEGMENT[0];

	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN0,DIO_u8HIGH);
	_delay_ms(150);
	for (int i= 5 ;i >= 0; i--){
		for(int k= 9; k >=0; k--){
			PORTA = SEGMENT[k];
			PORTB = SEGMENT[i];
			_delay_ms(150);
		}
	}
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN0,DIO_u8LOW);
	_delay_ms(100);
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN1,DIO_u8HIGH);
	PORTB = SEGMENT[1];
	PORTA = SEGMENT[5];
	_delay_ms(150);
	for (int i= 1; i>=0; i--){
		for(int k=9; k >=0; k--){

		PORTA = SEGMENT[k];
		PORTB = SEGMENT[i];
		_delay_ms(150);
		}
	}
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN1,DIO_u8LOW);
	_delay_ms(100);
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN2,DIO_u8HIGH);
	PORTB = SEGMENT[6];
	PORTA = SEGMENT[0];
	for (int i= 5 ;i >= 0; i--){
			for(int k= 9; k >=0; k--){
				PORTA = SEGMENT[k];
				PORTB = SEGMENT[i];
				_delay_ms(150);
			}
	}
	DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN2,DIO_u8LOW);
	_delay_ms(100);
		DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN1,DIO_u8HIGH);
		PORTB = SEGMENT[1];
		PORTA = SEGMENT[5];
		_delay_ms(100);
		for (int i= 1; i>=0; i--){
			for(int k=9; k >=0; k--){

			PORTA = SEGMENT[k];
			PORTB = SEGMENT[i];
			_delay_ms(150);
			}
		}
		DIO_voidSetPenValue(DIO_u8PORTC, DIO_u8PIN1,DIO_u8LOW);
    }
}

