/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  11/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  KEYPAD                   */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef      KEYPAD_INTERFACE_H
#define      KEYPAD_INTERFACE_H

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"

#include "../../02-MCAL/01-DIO/DIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "util/delay.h"
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>

#define PortNum     DIO_u8PORTC



uint8 KeyBad_uint8GetKey(void);
void Keypad_init(void);

#endif
