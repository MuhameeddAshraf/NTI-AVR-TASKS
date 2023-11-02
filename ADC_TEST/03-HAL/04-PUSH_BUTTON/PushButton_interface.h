/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  14/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  PUSHBUTTON               */
/* Version             :  1.0.0                    */
/***************************************************/


#ifndef            PushButton_INTERFACE_H
#define            PushButton_INTERFACE_H

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"

#include "../../02-MCAL/01-DIO/DIO_interface.h"

#include "PushButton_config.h"
#include "PushButton_private.h"
#include "util/delay.h"
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>

void PushButton_voidInit(Button *button);
uint8 PushButton_voidRead(Button *button);




#endif