/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  14/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  PUSHBUTTON               */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "PushButton_interface.h"

void PushButton_voidInit(Button *Button){
	DIO_voidSetPinDirection(Button -> Button_port, Button -> Button_pin, DIO_u8INPUT);
	DIO_voidSetPinValue(Button-> Button_port, Button -> Button_pin, DIO_u8HIGH); //pull up
}

uint8 PushButton_voidRead(Button *Button){
    uint8 local_u8Read = DIO_u8GetPinValue(Button->Button_port, Button->Button_pin);
    static Button_state lastButtonState = Button_RELEASED; // Static variable to remember the last state

    if (local_u8Read == 0 && lastButtonState == Button_RELEASED) {
        // Button was just pressed
        lastButtonState = Button_PRESSESD;
    } else if (local_u8Read == 1 && lastButtonState == Button_PRESSESD) {
        // Button was just released
        lastButtonState = Button_RELEASED;
    }
    return lastButtonState;
}