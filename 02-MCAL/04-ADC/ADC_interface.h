/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  20/10/2023               */
/* Layer               :  MCAL LAYER               */
/* SWC                 :  ADC                      */
/* Version             :  1.0.0                    */
/***************************************************/ 


#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


void ADC_voidInit(void);
uint16 ADC_u8StartConversion(uint8 Copy_u8ChannelNumber);

#define ADC_CHANNEL_A0 		0
#define ADC_CHANNEL_A1		1
#define ADC_CHANNEL_A2		2
#define ADC_CHANNEL_A3 		3
#define ADC_CHANNEL_A4		4
#define ADC_CHANNEL_A5		5
#define ADC_CHANNEL_A6		6
#define ADC_CHANNEL_A7		7


#endif 
