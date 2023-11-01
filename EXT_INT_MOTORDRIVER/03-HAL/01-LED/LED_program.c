/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  07/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  LED                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"

#include "../../02-MCAL/01-DIO/DIO_interface.h"

#include "LED_interface.h"



void  LED_voidInit(uint8 Copy_u8PortNum ,uint8 Copy_u8PinNum )
{
	DIO_voidSetPinDirection(Copy_u8PortNum , Copy_u8PinNum , DIO_u8OUTPUT);

	DIO_voidSetPinValue(Copy_u8PortNum , Copy_u8PinNum , DIO_u8LOW);
}

void  LED_voidLedMode(uint8 Copy_u8PortNum ,uint8 Copy_u8PinNum ,uint8 Copy_u8Mode )
{
	switch(Copy_u8Mode)
	{
		case LED_OFF  :

			DIO_voidSetPinValue(Copy_u8PortNum, Copy_u8PinNum, DIO_u8LOW);

			break;

		case LED_ON   :

			DIO_voidSetPinValue(Copy_u8PortNum, Copy_u8PinNum, DIO_u8HIGH);

			break;

		case LED_TOG  :

			DIO_voidSetTogglePin(Copy_u8PortNum ,Copy_u8PinNum);

	}
}
