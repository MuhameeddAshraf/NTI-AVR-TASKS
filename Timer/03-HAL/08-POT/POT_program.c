/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  24/10/2023               */
/* Layer               :  HAL LAYER                */
/* SWC                 :  POT                      */
/* Version             :  1.0.0                    */
/***************************************************/ 


#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "../../02-MCAL/04-ADC/ADC_Interface.h"

#include "POT_interface.h"
#include "POT_private.h"
#include "POT_config.h"

void POT_Init(void){
		ADC_voidInit();
}

void POT_CallValue(uint32 *Copy_Digital, uint32 *Copy_Volt){
		
		uint32 local_Digital = ADC_u8StartConversion(ADC_CHANNEL);
		uint32 local_Volt	 = (local_Digital*5)/1023;
		
		*Copy_Digital	= local_Digital;
		*Copy_Volt 		= local_Volt;
		
}



