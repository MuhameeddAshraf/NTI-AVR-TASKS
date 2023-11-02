	/***************************************************/
	/* Author              :  Mohamed AShraf           */
	/* Origin Date         :  06/10/2023               */
	/* Layer               :  MCAL Layer               */
	/* SWC                 :  DIO                      */
	/* Version             :  1.0.0                    */
	/***************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"  //proto types
#include "DIO_config.h"     //
#include "DIO_private.h"    //


/**************************************/

//DIO_voidSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8OUTPUT);
void  DIO_voidSetPinDirection(uint8 Copy_u8PortNum, uint8 Copy_u8PinNum, uint8 Copy_u8Mode)
{
	if (DIO_u8OUTPUT == Copy_u8Mode)
	{
		switch(Copy_u8PinNum)
		{
			case DIO_u8PORTA:  SET_BIT(DDRA, Copy_u8PinNum);  break;
			case DIO_u8PORTB:  SET_BIT(DDRB, Copy_u8PinNum);  break;
			case DIO_u8PORTC:  SET_BIT(DDRC, Copy_u8PinNum);  break;
			case DIO_u8PORTD:  SET_BIT(DDRD, Copy_u8PinNum);  break;
			default: 		/* return error */	   			  break;
		}
	}
	else if (DIO_u8INPUT == Copy_u8Mode)
	{
		switch(Copy_u8PinNum)
		{
			case DIO_u8PORTA:  CLR_BIT(DDRA, Copy_u8PinNum);  break;
			case DIO_u8PORTB:  CLR_BIT(DDRB, Copy_u8PinNum);  break;
			case DIO_u8PORTC:  CLR_BIT(DDRC, Copy_u8PinNum);  break;
			case DIO_u8PORTD:  CLR_BIT(DDRD, Copy_u8PinNum);  break;
			default: 		 	/* return error */ 			  break;
		}
	}
	else
	{
		 /* return error */
	}
	
}


//DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8HIGH);

void  DIO_voidSetPinValue(uint8 Copy_u8PortNum, uint8 Copy_u8PinNum, uint8 Copy_u8Value)
{
	if(DIO_u8HIGH == Copy_u8Value)
	{
		switch(Copy_u8PortNum)
		{
		    case DIO_u8PORTA:  SET_BIT(PORTA, Copy_u8PinNum);  break;
			case DIO_u8PORTB:  SET_BIT(PORTB, Copy_u8PinNum);  break;
			case DIO_u8PORTC:  SET_BIT(PORTC, Copy_u8PinNum);  break;
			case DIO_u8PORTD:  SET_BIT(PORTD, Copy_u8PinNum);  break;
			default: 		/* return error */	   			   break;
	    }
	}
	
	else if (DIO_u8LOW == Copy_u8Value) 
	{ 	
		switch(Copy_u8PortNum)
		{
			case DIO_u8PORTA:  CLR_BIT(PORTA, Copy_u8PinNum);  break;
			case DIO_u8PORTB:  CLR_BIT(PORTB, Copy_u8PinNum);  break;
			case DIO_u8PORTC:  CLR_BIT(PORTC, Copy_u8PinNum);  break;
			case DIO_u8PORTD:  CLR_BIT(PORTD, Copy_u8PinNum);  break;
			default: 		 	/* return error */ 			   break;	
		}
	}
	
	else 
	{
		/* return error */
	}
}


//DIO_u8GetPinValue(DIO_u8PORTA, DIO_u8PIN0);
uint8 DIO_u8GetPinValue(uint8 Copy_u8PortNum, uint8 Copy_u8PinNum)
{
	uint8 Local_u8Result = 0 ;
	switch(Copy_u8PinNum)
		{
			case DIO_u8PORTA:  Local_u8Result = GET_BIT(PORTA, Copy_u8PinNum);  break;
			case DIO_u8PORTB:  Local_u8Result = GET_BIT(PORTB, Copy_u8PinNum);  break;
			case DIO_u8PORTC:  Local_u8Result = GET_BIT(PORTC, Copy_u8PinNum);  break;
			case DIO_u8PORTD:  Local_u8Result = GET_BIT(PORTD, Copy_u8PinNum);  break;
			default: 		 	/* return error */ 			   					break;	
		}
		
		return Local_u8Result;
}

//DIO_voidSePortDirection(DIO_u8PORTA, DIO_u8PORTOUTPUT);
void DIO_voidSetPortDirection(uint8 Copy_u8PortNum, uint8 copy_u8Mode)
{

		switch (Copy_u8PortNum)
		{
			case DIO_u8PORTA:  DDRA = copy_u8Mode;   break;
			case DIO_u8PORTB:  DDRB = copy_u8Mode;   break;
			case DIO_u8PORTC:  DDRC = copy_u8Mode;   break;
			case DIO_u8PORTD:  DDRD = copy_u8Mode;   break;
			default:           /* return error */         break;
		}
}

//DIO_voidSetPortValue(DIO_u8PORTA, DIO_u8PORTHIGH);
void DIO_voidSetPortValue(uint8 Copy_u8PortNum, uint8 Copy_u8Value)
{
		switch (Copy_u8PortNum)
		{
			case DIO_u8PORTA:  PORTA = Copy_u8Value;     break;
			case DIO_u8PORTB:  PORTB = Copy_u8Value;     break;
			case DIO_u8PORTC:  PORTC = Copy_u8Value;     break;
			case DIO_u8PORTD:  PORTD = Copy_u8Value;     break;
			default:           /* return error */          break;
		}
	}

	
	
void DIO_voidSetTogglePin(uint8 Copy_u8PortNum,uint8 Copy_u8PinNum)
{
	switch(Copy_u8PortNum)
		{
			case DIO_u8PORTA:  TOG_BIT(DDRA, Copy_u8PinNum);  break;
			case DIO_u8PORTB:  TOG_BIT(DDRB, Copy_u8PinNum);  break;
			case DIO_u8PORTC:  TOG_BIT(DDRC, Copy_u8PinNum);  break;
			case DIO_u8PORTD:  TOG_BIT(DDRD, Copy_u8PinNum);  break;
			default: 		/* return error */	   			  break;
		}
}



