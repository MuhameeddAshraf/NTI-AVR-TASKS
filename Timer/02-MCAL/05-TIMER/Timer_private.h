/************************************************************/
/* Author              :  Mohamed_Ashraf                    */
/* Origin Date         :  25/10/2023                        */
/* Layer               :  MCAL_Layer                        */
/* SWC                 :  Timer 		                    */
/* Version             :  1.0.0                             */
/************************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
#include "../../01-LIB/STD_TYPES.h"

#define  TCCR0  *((volatile uint8 *)0x53)
#define  TCNT0  *((volatile uint8 *)0x52)
#define  TIMSK  *((volatile uint8 *)0x59)

#define SREG    *((volatile uint8 *) 0x5f)
#define OCR0    *((volatile uint8 *) 0x5C)





#endif /* TIMER_PRIVATE_H_ */
