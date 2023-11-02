/*
 * main.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Mohamed
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>
#include"../MCAL/DIO/DIO_interface.h"

#define     MCUCR          *((volatile uint8 *)  0x55)
#define     MCUCSR         *((volatile uint8 *)  0x54)
#define     GICR           *((volatile uint8 *)  0x5B)
#define     GIFR           *((volatile uint8 *)  0x5A)
#define     SREG           *((volatile uint8 *)  0x5F)

int counter = 0 ;
void __vector_1 (void) __attribute__ 	((signal));
void __vector_1 (void)
{
	counter++;
	//_delay_ms(500);
	//DIO_voidSetTogglePin(DIO_u8PORTD , 6);
}


void Interrupt_Init(void)
{
	SET_BIT(MCUCR, 1) ;
	SET_BIT(GICR , 6);
	SET_BIT(SREG , 7) ;
}


int main(void)
{


	Interrupt_Init();
	DIO_voidSetPinDirection(DIO_u8PORTD ,DIO_u8PIN2 , DIO_u8INPUT);
	DIO_voidSetPinDirection(DIO_u8PORTD ,DIO_u8PIN5 , DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTD ,DIO_u8PIN6 , DIO_u8OUTPUT);

	DIO_voidSetPinValue(DIO_u8PORTD ,DIO_u8PIN2, DIO_u8HIGH);
	DIO_voidSetPinValue(DIO_u8PORTD ,DIO_u8PIN5, DIO_u8HIGH);
	DIO_voidSetPinValue(DIO_u8PORTD ,DIO_u8PIN6 , DIO_u8LOW);

	while(1)
	{
		_delay_ms(1000);
		DIO_voidSetTogglePin(DIO_u8PORTD , 5);
		_delay_ms(1000);
	}
}


