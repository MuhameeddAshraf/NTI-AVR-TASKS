/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  19/10/2023               */
/* Layer               :  MCAL LAYER               */
/* SWC                 :  GIE                      */
/* Version             :  1.0.0                    */
/***************************************************/ 
#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_config.h"
#include "GIE_private.h"

void GIE_voidEnable ()
{
    SET_BIT(SREG, SREG_BIT7);
}

void GIE_voidDisable ()
{
    CLR_BIT(SREG, SREG_BIT7);
}
