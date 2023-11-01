/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  07/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  LED                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef          LED_INTERFACE_H
#define          LED_INTERFACE_H

#include "LED_config.h"
#include "LED_private.h"


void  LED_voidInit(uint8 Copy_u8PortNum ,uint8 Copy_u8PinNum );

void  LED_voidLedMode(uint8 Copy_u8PortNum ,uint8 Copy_u8PinNum ,uint8 Copy_u8Mode );


#endif
