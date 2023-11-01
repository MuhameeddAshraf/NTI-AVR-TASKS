/*
 * main.c
 *
 *  Created on: Oct 14, 2023
 *      Author: Mohamed
 */

#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/MOTOR/DC_Motor_Interface.h"
#include "../HAL/LED/LED_interface.h"


int main(void){
	uint8 Key, Flag=1, Condition=1;

    // Initialize peripherals
	LCD_Init();
	Keypad_init();
	LED_voidInit(DIO_u8PORTD,DIO_u8PIN2); // Initialize an LED on Port D, Pin 2

    // Configuration for DC Motor
	DC_Motor config;
	config.port = DC_Port; 		// Specify the port for the DC Motor
	config.pin_1= DIO_u8PIN0;	// Specify the first pin of the motor
	config.pin_2= DIO_u8PIN1;	// Specify the second pin of the motor
	DC_Init(config);			// Initialize the DC Motor

    // Display welcome message
	LCD_Goto(1,5);
	LCD_WriteString("WELCOME To");
	LCD_Goto(2,1);
	LCD_WriteString("THE MINI PROJECT");
	_delay_ms(1500);
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_WriteString("===HOME PAGE!===");
	LCD_Goto(2,1);
	LCD_WriteString("================");
	_delay_ms(1500);
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_WriteString("1-CONTROL");
	LCD_Goto(2,1);
	LCD_WriteString("2-STATUS");

	while(1){
        // Get the pressed key
		Key = KeyBad_uint8GetKey();

		if (Key != 'z')
		{
			if (Condition == 1){   // Always true -> Main Menu
				if (Key == '1'){
					Condition = 2; //Go To Control Menu
					Flag = 2 ;
				}
				else if (Key == '2'){
					Condition  = 3; //Go To Status Menu
					Flag = 3;
				}
				else if (Key == 'c'){
								LCD_Clear();
								LCD_Goto(1,1);
								//LCD_WriteString("1234567890123456");
								LCD_WriteString("PROJCET->CLOSING");
								LCD_Goto(2,1);
								LCD_WriteString("## THANK YOU! ##");
								_delay_ms(2000);
								LCD_Clear();
								DC_Off(config);
								LED_voidLedMode(DIO_u8PORTD,DIO_u8PIN2,LED_OFF);
								break;
							}
			}
			else if (Condition == 2){
				if (Key == '1'){
					Condition = 21; // Go To LED_ MENU
				}
				else if (Key == '2'){
					Condition = 22; // GO TO MOTOR MENU
				}
			}
			else if (Condition == 3){
				if (Key == '1'){
					Condition = 31; // LED Status
				}
				else if (Key == '2'){
					Condition = 32; // MOTOR Status
				}
			}

			if (Key == 'c'){
				if (Condition == 21 || Condition == 22){
				Condition = 2; 		// Go To Control Menu
				Flag = 2;
				}
				else if (Condition == 2){
					Condition = 1 ;	// Go To Main Menu
					Flag = 1;
				}
				if (Condition == 31 || Condition ==32){
					Condition =3;	// Go To Status Menu
					Flag = 3;
				}
				else if (Condition == 3){
					Condition = 1;	// Go To Main Menu
					Flag = 1;
				}
			}

			switch (Condition){


				/***************************/
				/*****     MAIN MENU   *****/
			 	/***************************/
			case 1:
				LCD_Clear();
				LCD_Goto(1,1);
				LCD_WriteString("1-CONTROL");
				LCD_Goto(2,1);
				LCD_WriteString("2-STATUS");
				break;


				/***************************/
				/*****   CONTROL MENU  *****/
				/***************************/
			case 2:
				if (Flag ==2){
					LCD_Clear();
					LCD_Goto(1,1);
					LCD_WriteString("1- CONTROL LED");
					LCD_Goto(2,1);
					LCD_WriteString("2- CONTROL MOTOR");
					Flag = 3;
				}
				break;


				/***************************/
				/*****   STATUS MENU   *****/
				/***************************/
			case 3:
				if (Flag == 3){

					LCD_Clear();
					LCD_Goto(1,1);
					LCD_WriteString("1- LED STATUS");
					LCD_Goto(2,1);
					LCD_WriteString("2- MOTOR STATUS");
					Flag = 3;
				}
				break;


				/***************************/
				/*****     LED MENU    *****/
				/***************************/
			case 21:
				if (Flag == 3 ){

					LCD_Clear();
					LCD_Goto(1,1);
					LCD_WriteString("1- LED ON");
					LCD_Goto(2,1);
					LCD_WriteString("2- LED OFF");
					Flag = 4;

					while (1){
						Key= KeyBad_uint8GetKey();
						if (Key != 'z'){
							if (Key == '1'){
								LED_voidLedMode(DIO_u8PORTD,DIO_u8PIN2,LED_ON); 	// LED ON
							}
							else if (Key == '2'){
								LED_voidLedMode(DIO_u8PORTD,DIO_u8PIN2,LED_OFF);	// LED OFF
							}
							else if (Key == 'c'){				// TO Stop taking input from user and go our of this loop
								break;

							}
						}
					}
				}
				break;



				/***************************/
				/*****  DC MOTOR MENU  *****/
				/***************************/
			case 22:
				if (Flag == 3 ){
					LCD_Clear();
					LCD_Goto(1,1);
					LCD_WriteString("1- CW");
					LCD_Goto(2,1);
					LCD_WriteString("2- CCW");
					LCD_Goto(1,10);
					LCD_WriteString("3- OFF");
					Flag = 4 ;

					while (1){
						Key = KeyBad_uint8GetKey();
						if (Key != 'z'){
							if (Key == '1'){
								DC_Cw(config);				// DC MOTOR Rotate Clock wise

							}
							else if (Key == '2'){
							DC_Ccw(config);  				// DC MOTOR Rotates Counter Clock wise

							}
							else if (Key == '3'){
								DC_Off(config);				// DC MOTOR STOP Rotating
							}
							else if (Key == 'c'){			// TO Stop taking input from user and go our of this loop
								break;
							}
						}
					}
				}
				break;


				/***************************/
				/*****   LED STATUS	   *****/
				/***************************/
			case 31:
				if (Flag == 3){
					LCD_Clear();
					uint8 x;
					DIO_u8GetPinValue_Store(DIO_u8PORTD,DIO_u8PIN2, &x);   	// Store the value of pin in integer x
					if (x == 0){
						LCD_Goto(1,1);
						LCD_WriteString("LED IS OFF ");
					}
					if (x == 1){
						LCD_Goto(1,1);
						LCD_WriteString("LED IS ON");

					}
				}
				break;



				 /***************************/
				 /***** DC MOTOR STATUS *****/
				 /***************************/
			case 32:

				if (Flag == 3){
					LCD_Clear();
					uint8 y,z;
					DIO_u8GetPinValue_Store(DC_Port,DIO_u8PIN0,&y);				// To Store the Value of The pin 0
					DIO_u8GetPinValue_Store(DC_Port,DIO_u8PIN1,&z);				// To Store the Value of The pin 1
					if (y == 0 && z == 1 ){
						LCD_Goto(1,1);
						LCD_WriteString("THE MOTOR IS CW");
					}
					else if (y == 1 && z == 0){
						LCD_Goto(1,1);
						LCD_WriteString("THE MOTOR IS CCW");
					}
					else if (y == 0 && z == 0){
						LCD_Goto(1,1);
						LCD_WriteString("THE MOTOR IS OFF");
					}
				}
				break;
			}
		}
	}
}
