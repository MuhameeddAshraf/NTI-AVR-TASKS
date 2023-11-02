/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  24/10/2023               */
/* Layer               :  HAL LAYER                */
/* SWC                 :  LM35                     */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "../../02-MCAL/04-ADC/ADC_Interface.h"

#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"

void LM35_Init(void){
		ADC_voidInit();
}

uint32 LM35_Value(void){
		uint32 local_Digit_value = ADC_u8StartConversion(ADC_CHANNEL);
		//DIO_voidSetPortValue(DIO_u8PORTC,Local_u8ADC_Reading);

		uint32 local_Analog_value = (local_Digit_value*5000)/1024;

		uint32 Temp = local_Analog_value/10;
		
		return Temp;
}



