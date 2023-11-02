/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  24/10/2023               */
/* Layer               :  HAL LAYER                */
/* SWC                 :  POT                      */
/* Version             :  1.0.0                    */
/***************************************************/ 


#ifndef POT_INTERFACE_H
#define POT_INTERFACE_H


#define ADC_CHANNEL ADC_CHANNEL_A0


void POT_init(void);
void POT_CallValue(uint32 * Copy_u8Digital, uint32 * Copy_u8Volt);

#endif 
