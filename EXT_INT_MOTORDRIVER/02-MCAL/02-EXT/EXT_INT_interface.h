/*****************************************************************************/
/* Author       	: 	Mohamed Ashraf	                                     */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            : 	External Interrupt                                   */
/* Version      	: 	1                                                    */
/*****************************************************************************/
#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#define INT0    0
#define INT1    1
#define INT2    2

#define INT_LOW_LEVEL        1
#define INT_ANY_CHANGE       2
#define INT_FALLING_EDGE     3
#define INT_RISSING_EDGE     4

void EXT_INT_voidSetCallBack(void (*PF)(void), uint8 Copyu8EXT_INT_Num);
void EXT_INT_voidInit(uint8 Copy_u8INT_Num, uint8 Copy_u8SenseControl);
#endif
