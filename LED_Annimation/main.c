/*
 * main.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_private.h"
#include "DIO_interface.h"

int main(void){

	DIO_voidSePortDirection(DIO_u8PORTA, DIO_u8PORTOUTPUT);

	for(int i=0; i < 4; i++){
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN1,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN1,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN2,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN2,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN3,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN3,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN4,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN4,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN5,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN5,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN6,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN6,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN7,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN7,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN7,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN7,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN6,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN6,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN5,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN5,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN4,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN4,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN3,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN3,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN2,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN2,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN1,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN1,DIO_u8LOW);
				_delay_ms(200);

				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8HIGH);
				_delay_ms(200);
				DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8LOW);
				_delay_ms(200);
		}

	for(int k=0; k < 4; k++){

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN3,DIO_u8HIGH);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN4,DIO_u8HIGH);
		_delay_ms(200);

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN2,DIO_u8HIGH);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN5,DIO_u8HIGH);
		_delay_ms(200);

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN1,DIO_u8HIGH);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN6,DIO_u8HIGH);
		_delay_ms(200);

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8HIGH);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN7,DIO_u8HIGH);
		_delay_ms(200);

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8LOW);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN7,DIO_u8LOW);
		_delay_ms(200);

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN1,DIO_u8LOW);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN6,DIO_u8LOW);
		_delay_ms(200);

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN2,DIO_u8LOW);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN5,DIO_u8LOW);
		_delay_ms(200);

		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN3,DIO_u8LOW);
		DIO_voidSetPenValue(DIO_u8PORTA, DIO_u8PIN4,DIO_u8LOW);
		_delay_ms(200);

	}
	for (int j=0; j<8; j++){
		DIO_voidSetPortValue(DIO_u8PORTA, DIO_u8PORTHIGH);
		_delay_ms(500);
		DIO_voidSetPortValue(DIO_u8PORTA, DIO_u8PORTLOW);
		_delay_ms(500);
	}

	while(1)
	{

	}

}
