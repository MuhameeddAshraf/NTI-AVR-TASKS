/***************************************************/
/* Author              :  Mohamed Ashraf           */
/* Origin Date         :  21/10/2023               */
/* Layer               :  APP LAYER                */
/* SWC                 :  ------                   */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "header.h"

int main(void){
	
	//uint8 Local_u8ADC_Reading;
	uint16 local_Digit_value= 0;
	//uint16 local_u8volt =0 ;
	uint16 MilliVolt = 0;
	uint16 Temp =0;

	/* STATIC CONFIG FOR 1 Time */
	//ADC PIN (INPUT)
	DIO_voidSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8INPUT);
	// PORT C (OUTPUT)
	//DIO_voidSetPortDirection(DIO_u8PORTC,DIO_u8PortOn);


	ADC_voidInit();
	LCD_Init();

	while (1){
	
		local_Digit_value = ADC_u8StartConversion(ADC_CHANNEL_A0);
		//DIO_voidSetPortValue(DIO_u8PORTC,Local_u8ADC_Reading);

		MilliVolt = ((uint32)local_Digit_value*5000UL)/1024;
		Temp = MilliVolt/10;

		LCD_Goto(1,1);
		LCD_WriteString("Temp= ");
		LCD_WriteNum(Temp);
		_delay_ms(100);
		//	LCD_Clear();


		//
//		LCD_Goto(2,1);
//		LCD_WriteString("Volt= ");
//		LCD_WriteNum(local_u8volt);
	}
}
