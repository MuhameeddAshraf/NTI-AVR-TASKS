/************************************************************/
/* Author              :  Mohamed_Ashraf                    */
/* Origin Date         :  25/10/2023                        */
/* Layer               :  MCAL_Layer                        */
/* SWC                 :  Timer 		                    */
/* Version             :  1.0.0                             */
/************************************************************/

#include "Timer_interface.h"

void Timer0_OverFlow_init(uint8 prescaler , uint8 preload){

	// select over flow
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//
	TCNT0=preload;

	//select interrupt for over flow
	SET_BIT(TIMSK,0);

	// prescaler
	if(prescaler==8){
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
	else if(prescaler==64){
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
	}
}

void (*ptr_T0_overflow)(void);
void call_back_over_flow(void(*func)(void)){
	ptr_T0_overflow=func;
}
void __vector_11(void)__attribute((signal));
void __vector_11(void){
	ptr_T0_overflow();
	//toggle
}

void Timer0_CTC_init(uint8 prescaler, uint8 OCR_value){

	//select ctc page 78
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	OCR0=OCR_value;

	//select interrupt for ctc
	SET_BIT(TIMSK,1);

	//select prescaler
		if(prescaler==8){
			CLR_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		}
		else if(prescaler==64){
			SET_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		}
}
void (*ptr_T0_CTC)(void);
void Call_back_CTC(void(*func)(void)){
	ptr_T0_CTC=func;
}
void __vector_10(void)__attribute((signal));
void __vector_10(void){
	ptr_T0_CTC();
	//toggle
}
