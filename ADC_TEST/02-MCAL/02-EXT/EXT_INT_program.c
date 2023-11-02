/*****************************************************************************/
/* Author       	: 	Mohamed Ashraf	                                     */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            : 	External Interrupt                                   */
/* Version      	: 	1                                                    */
/*****************************************************************************/
#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

 #include "EXT_INT_interface.h"
 #include "EXT_INT_config.h"
 #include "EXT_INT_private.h"

void (*GAPF[3])(void) = {NULL, NULL, NULL}; // Group of array of Pointers
void EXT_INT_voidInit(uint8 Copy_u8INT_Num, uint8 Copy_u8SenseControl)
{
    if(Copy_u8INT_Num == INT0)
    {
        switch(Copy_u8SenseControl)
        {
            case INT_LOW_LEVEL:
             CLR_BIT(MCUCR, MCUCR_ISC00); 
             CLR_BIT(MCUCR, MCUCR_ISC01); 
             break;
            
            case INT_ANY_CHANGE:
             SET_BIT(MCUCR, MCUCR_ISC00); 
             CLR_BIT(MCUCR, MCUCR_ISC01); 
             break;
            
            case INT_FALLING_EDGE:
             CLR_BIT(MCUCR, MCUCR_ISC00); 
             SET_BIT(MCUCR, MCUCR_ISC01); 
             break;
            
            case INT_RISSING_EDGE:
             SET_BIT(MCUCR, MCUCR_ISC00); 
             SET_BIT(MCUCR, MCUCR_ISC01); 
             break;
        }

        SET_BIT(GICR, GICR_INT0);               
    }
    
    else if(Copy_u8INT_Num == INT1)
    {
        switch(Copy_u8SenseControl)
        {
            case INT_LOW_LEVEL:
             CLR_BIT(MCUCR, MCUCR_ISC10); 
             CLR_BIT(MCUCR, MCUCR_ISC11); 
             break;
            
            case INT_ANY_CHANGE:
             SET_BIT(MCUCR, MCUCR_ISC10); 
             CLR_BIT(MCUCR, MCUCR_ISC11); 
             break;
            
            case INT_FALLING_EDGE:
             CLR_BIT(MCUCR, MCUCR_ISC10); 
             SET_BIT(MCUCR, MCUCR_ISC11); 
             break;
            
            case INT_RISSING_EDGE:
             SET_BIT(MCUCR, MCUCR_ISC10); 
             SET_BIT(MCUCR, MCUCR_ISC11); 
             break;

        }
        SET_BIT(GICR, GICR_INT1);
    }

    else if(Copy_u8INT_Num == INT2)
    {
        switch(Copy_u8SenseControl)
        {
            case INT_FALLING_EDGE: CLR_BIT(MCUCSR, MCUCSR_ISC2); break;
            case INT_RISSING_EDGE: SET_BIT(MCUCSR, MCUCSR_ISC2); break;
        }
        SET_BIT(GICR, GICR_INT2);
    }
}

void EXT_INT_voidSetCallBack(void (*PF)(void), uint8 Copyu8EXT_INT_Num)  
{
    GAPF[Copyu8EXT_INT_Num] = PF; 
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    GAPF[INT0]();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    GAPF[INT1]();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    GAPF[INT2]();
}


void EXT_INT_voidClearFlag(uint8 Copy_u8INT_Num)
{
    if(Copy_u8INT_Num == INT0)
    {
        SET_BIT(GIFR, GIFR_INTF0);
    }

    else if(Copy_u8INT_Num == INT1)
    {
        SET_BIT(GIFR, GIFR_INTF1);
    }

    else if(Copy_u8INT_Num == INT2)
    {
        SET_BIT(GIFR, GIFR_INTF2);
    }
}
