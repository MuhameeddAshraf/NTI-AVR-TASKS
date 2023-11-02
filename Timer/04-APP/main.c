/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  XX/XX/2023               */
/* Layer               :  APP LAYER                */
/* SWC                 :  ------                   */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "../01-LIB/BIT_MATH.h"
#include "../01-LIB/STD_TYPES.h"

#include "../02-MCAL/01-DIO/DIO_interface.h"
#include "../02-MCAL/02-EXT/EXT_INT_interface.h"
#include "../02-MCAL/03-GIE/GIE_interface.h"
#include "../02-MCAL/04-ADC/ADC_interface.h"
#include "../02-MCAL/05-TIMER/Timer_interface.h"

#include "../03-HAL/01-LED/LED_interface.h"
#include "../03-HAL/02-SSD/SSD_config.h"
#include "../03-HAL/03-CLCD/CLCD_interface.h"
#include "../03-HAL/04-PUSH_BUTTON/PushButton_interface.h"
#include "../03-HAL/05-KEYPAD/KEYPAD_interface.h"
#include "../03-HAL/06-DC_MOTOR/DC_Motor_Interface.h"
#include "../03-HAL/07-LM35/LM35_interface.h"
#include "../03-HAL/08-POT/POT_interface.h"

#include <util/delay.h>
/*
// over flow
void fun_zero (void){
	static volatile uint32 counter = 0;
	counter++;
	if (counter==1953){
		DIO_voidSetTogglePin(DIO_u8PORTB,DIO_u8PIN3);
		counter=0;
		TCNT0=224;
	}
}
*/

		/*	PWM  */
void fun_zero (void){
	static volatile uint8 counter = 0;
	if (counter==0){
		DIO_voidSetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8LOW);
		counter=1;
		TCNT0=251;
	}
	else if (counter==1){
		DIO_voidSetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8HIGH);
		counter=0;
		TCNT0=241;
	}
}

/*
// ctc

void fun_ctc (void){
	static volatile uint32 counter = 0;
	counter++;
	if (counter==1000){
		DIO_voidSetTogglePin(DIO_u8PORTB,DIO_u8PIN0);
		counter=0;
	}
}
*/

int main(void){
	//DIO_voidSetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8OUTPUT); // --> CTC
	DIO_voidSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8OUTPUT); // --> OVER FLOW

	// over flow
	//Timer0_OverFlow_init(8,224);
	//call_back_over_flow(fun_zero);
	//ctc
	//Timer0_CTC_init(64,62);
	//Call_back_CTC(fun_ctc);

	//pwm
	Timer0_OverFlow_init(8,241);
	call_back_over_flow(fun_zero);

	GIE_voidEnable();

	while(1){

	}
}



