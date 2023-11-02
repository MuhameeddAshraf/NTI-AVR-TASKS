/*************************************************
* Author               :   Mostafa hessin
* Date                 :   6/10/2023
* layer                :   HAL
* SWC                  :   LED
* Version              :   1.0.0
*************************************************/
#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"

#include "../../02-MCAL/01-DIO/DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"


void SSD_voidSetSSD(uint8 Copy_u8PortNum ,uint8 Copy_u8NumValue)
{
	DIO_voidSetPortValue(Copy_u8PortNum  ,Copy_u8NumValue) ;
}
