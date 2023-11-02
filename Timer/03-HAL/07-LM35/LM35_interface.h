/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  24/10/2023               */
/* Layer               :  HAL LAYER                */
/* SWC                 :  LM35                     */
/* Version             :  1.0.0                    */
/***************************************************/ 


#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H


#define ADC_CHANNEL ADC_CHANNEL_A0

void LM35_Init(void);
uint32 LM35_Value(void);


#endif 
