/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  19/10/2023               */
/* Layer               :  MCAL LAYER               */
/* SWC                 :  GIE                      */
/* Version             :  1.0.0                    */
/***************************************************/ 
#ifndef GIE_PRIVATE_H
#define GIE_PRIVATE_H

#define HWR8(X)        *((volatile uint8*)(X))

#define SREG          HWR8(0x5f)
#define SREG_BIT7      7   

#endif