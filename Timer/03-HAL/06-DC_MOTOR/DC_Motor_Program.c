/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  14/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  DC_MOTOR                 */
/* Version             :  1.0.0                    */
/***************************************************/ 

//	DC_Motor config;
//	config.port = DC_Port; 		// Specify the port for the DC Motor
//	config.pin_1= DIO_u8PIN0;	// Specify the first pin of the motor
//	config.pin_2= DIO_u8PIN1;	// Specify the second pin of the motor
//	DC_Init(config);			// Initialize the DC Motor

#include "util/delay.h"
#include "DC_Motor_Interface.h"


void DC_Init(DC_Motor config){
	DIO_voidSetPinDirection(config.port,config.pin_1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(config.port,config.pin_2,DIO_u8OUTPUT);

}

void DC_Cw(DC_Motor config){
	DIO_voidSetPinValue(config.port,config.pin_2,DIO_u8HIGH);
	DIO_voidSetPinValue(config.port,config.pin_1,DIO_u8LOW);
}

void DC_Ccw(DC_Motor config){
	DIO_voidSetPinValue(config.port,config.pin_1,DIO_u8HIGH);
	DIO_voidSetPinValue(config.port,config.pin_2,DIO_u8LOW);
}

void DC_Off(DC_Motor config){
	DIO_voidSetPinValue(config.port,config.pin_1,DIO_u8LOW);
	DIO_voidSetPinValue(config.port,config.pin_2,DIO_u8LOW);
}
void DC_Tog(DC_Motor config , uint64 delay)
{
	DIO_voidSetPinValue(config.port,config.pin_2,DIO_u8HIGH);
	DIO_voidSetPinValue(config.port,config.pin_1,DIO_u8LOW);
	_delay_ms(delay);
	DIO_voidSetPinValue(config.port,config.pin_1,DIO_u8HIGH);
	DIO_voidSetPinValue(config.port,config.pin_2,DIO_u8LOW);
	_delay_ms(delay);
}
