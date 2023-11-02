/************************************************************/
/* Author              :  Mohamed_Ashraf                    */
/* Origin Date         :  25/10/2023                        */
/* Layer               :  MCAL_Layer                        */
/* SWC                 :  Timer 		                    */
/* Version             :  1.0.0                             */
/************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "../01-DIO/DIO_interface.h"
#include "../02-EXT/EXT_INT_interface.h"
#include "Timer_private.h"


void Timer0_OverFlow_init(uint8 prescaler , uint8 preload);
void call_back_over_flow(void(*func)(void));

void Timer0_CTC_init(uint8 prescaler, uint8 OCR_value);
void Call_back_CTC(void(*func)(void));

#endif /* TIMER_INTERFACE_H_ */
