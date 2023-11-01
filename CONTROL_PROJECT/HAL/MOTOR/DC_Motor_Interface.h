/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  14/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  DC_MOTOR                 */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#define DC_Port DIO_u8PORTD

typedef struct {
	uint8 pin_1;
	uint8 pin_2;
	uint8 port;

}DC_Motor;


void DC_Init(DC_Motor config);
void DC_Cw(DC_Motor config);
void DC_Ccw(DC_Motor config);
void DC_Off(DC_Motor config);
void DC_Tog(DC_Motor config , uint64 delay);



#endif /* DC_MOTOR_INTERFACE_H_ */
