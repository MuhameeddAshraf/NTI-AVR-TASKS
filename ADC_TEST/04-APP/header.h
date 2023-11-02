/***************************************************/
/* Author              :  Mohamed Ashraf           */
/* Origin Date         :  21/10/2023               */
/* Layer               :  APP LAYER                */
/* SWC                 :  ------                   */
/* Version             :  1.0.0                    */
/***************************************************/

#include "../01-LIB/BIT_MATH.h"
#include "../01-LIB/STD_TYPES.h"

#include "../02-MCAL/01-DIO/DIO_interface.h"
#include "../02-MCAL/02-EXT/EXT_INT_interface.h"
#include "../02-MCAL/03-GIE/GIE_interface.h"
#include "../02-MCAL/04- ADC/ADC_interface.h"

#include "../03-HAL/01-LED/LED_interface.h"
#include "../03-HAL/02-SSD/SSD_config.h"
#include "../03-HAL/03-CLCD/CLCD_interface.h"
#include "../03-HAL/04-PUSH_BUTTON/PushButton_interface.h"
#include "../03-HAL/05-KEYPAD/KEYPAD_interface.h"
#include "../03-HAL/06-DC_MOTOR/DC_Motor_Interface.h"

#include <util/delay.h>
