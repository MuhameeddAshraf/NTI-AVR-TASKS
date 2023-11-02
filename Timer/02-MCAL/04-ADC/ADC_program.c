/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  20/10/2023               */
/* Layer               :  MCAL LAYER               */
/* SWC                 :  ADC                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"



void ADC_voidInit(void)
{
	/* select vref: AVCC at reference voltage */
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

	/* Activate left adjust result 	*/
	//SET_BIT(ADMUX, ADMUX_ADLAR);
	
	/* Activate Right adjust result 	*/
	//CLR_BIT(ADMUX, ADMUX_ADLAR);

	/*		No auto trigger 		*/
	CLR_BIT(ADCSRA, ADCSRA_ADATE);

	/* 	ADC Prescaler Select Bits	*/
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);


	/*		  set prescaler			*/
	ADCSRA &= ADC_PRESC_MASK;
	ADCSRA |= ADC_PRESC;

	/*			ADC Enable 			*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);


}



uint16 ADC_u8StartConversion(uint8 Copy_u8ChannelNumber)
{
	/*		 ADC Set Channel		*/
	ADMUX &= ADC_CHANNEL_MASK;
	ADMUX |= Copy_u8ChannelNumber;


//	/*		   	Enable ADC  		*/
//	SET_BIT(ADCSRA, ADCSRA_ADSC);


	/*		Start Conversion		*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);


	/* Wait for Conversion Complete falg */
	while (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0 );
	SET_BIT(ADCSRA, ADCSRA_ADIF);  // reset flag 


	return ADC;
}

