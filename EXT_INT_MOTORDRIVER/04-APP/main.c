/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  19/10/2023               */
/* Layer               :  APP LAYER                */
/* SWC                 :  INTERRUPT MOTOR          */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "../01-LIB/BIT_MATH.h"
#include "../01-LIB/STD_TYPES.h"

#include "../02-MCAL/01-DIO/DIO_interface.h"
#include "../02-MCAL/02-EXT/EXT_INT_interface.h"
#include "../02-MCAL/03-GIE/GIE_interface.h"

//#include "../03-HAL/01-LED/LED_interface.h"
//#include "../03-HAL/02-SSD/SSD_config.h"
//#include "../03-HAL/03-CLCD/CLCD_interface.h"
#include "../03-HAL/04-PUSH_BUTTON/PushButton_interface.h"
//#include "../03-HAL/05-KEYPAD/KEYPAD_interface.h"
#include "../03-HAL/06-DC_MOTOR/DC_Motor_Interface.h"

#include <util/delay.h>

int counter = 2 ;
DC_Motor config;
void TASK();


int main(void){

	config.port = DC_Port; 		// Specify the port for the DC Motor
	config.pin_1= DIO_u8PIN0;	// Specify the first pin of the motor
	config.pin_2= DIO_u8PIN1;	// Specify the second pin of the motor
	DC_Init(config);			// Initialize the DC Motor

	DIO_voidSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8HIGH);
	DIO_voidSetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8OUTPUT);
	DIO_voidSetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8HIGH);

	EXT_INT_voidInit(INT0,INT_FALLING_EDGE);
	EXT_INT_voidSetCallBack(TASK,INT0);
	
	GIE_voidEnable();


	while (1){
		_delay_ms(200);
		DIO_voidSetTogglePin(DIO_u8PORTD,DIO_u8PIN3);
		_delay_ms(200);
	}
}


void TASK(){
	if (counter % 2 == 0){
		DC_Cw(config);
	}else if (counter % 2 != 0 ){
		DC_Ccw(config);
	}
	_delay_ms(3000);
	counter++;
}
