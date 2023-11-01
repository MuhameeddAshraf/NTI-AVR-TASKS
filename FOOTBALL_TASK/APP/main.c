/*
 * main.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Mohamed
 */

#include "../HAL/CLCD/CLCD_interface.h"
//#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../HAL/PUSHBUTTON/PushButton_interface.h"


uint8 boyChar[]   = {0x1F,0x11,0x11,0x1F,0x04,0x0E,0x04,0x0E};
uint8 ballChar[]  = {0x00,0x00,0x00,0x0E,0x0E,0x0E,0x00,0x00};
uint8 goalPlace[] = {0x00,0x07,0x01,0x01,0x01,0x01,0x07,0x00};
uint8 nullChar[]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
char word_StartWord[] = "FOOTBALL GAME!";
char word_Welcome[]   = "WELCOME TO"  ;
char word_Goal[]      = "GOAAAAAL!!"    ;
char word_Lose[]	  = "GAME OVER!!"   ;
char word_Push[]      = "Please_Press"  ;
char word_B1[]		  = "Button1_Pushed";
char word_B2[]		  = "Button2_Pushed";
char word_EndGame[]   = "End Game !!"	;


int main(void){
	Button myButton1;
	Button myButton2;
	myButton1.Button_pin =  DIO_u8PIN0;
	myButton1.Button_port = DIO_u8PORTB;
	myButton2.Button_port = DIO_u8PORTB;
	myButton2.Button_pin =  DIO_u8PIN1;

	LCD_Init();
	//Keypad_init();
	PushButton_voidInit(&myButton1);
	PushButton_voidInit(&myButton2);

	LCD_Draw_Char(0,nullChar);
	LCD_Draw_Char(1,boyChar);
	LCD_Draw_Char(2,ballChar);
	LCD_Draw_Char(3,goalPlace);

	while(1){
		LCD_Clear();
		LCD_Goto(1,4);
		LCD_WriteString(word_Welcome);
		LCD_Goto(2,2);
		LCD_WriteString(word_StartWord);
		_delay_ms(2000);
		LCD_Clear();
		LCD_Goto(1,1);
		LCD_WriteString("Loading");
		_delay_ms(500);
		LCD_Goto(1,8);
		LCD_WriteString("..");
		_delay_ms(500);
		LCD_Goto(1,10);
		LCD_WriteString("..");
		_delay_ms(500);
		LCD_Goto(1,12);
		LCD_WriteString("..");
		_delay_ms(1000);
		LCD_Clear();
		_delay_ms(100);
		LCD_Goto(2,1);
		LCD_WriteData(1);
		LCD_Goto(2,3);
		LCD_WriteData(2);
		LCD_Goto(2,16);
		LCD_WriteData(3);
		_delay_ms(300);
		LCD_Goto(1,3);
		LCD_WriteString(word_Push);
		_delay_ms(800);
		uint8 Button_1 = PushButton_voidRead(&myButton1);
		uint8 Button_2 = PushButton_voidRead(&myButton2);
		_delay_ms(1000);

		if (Button_1 == 0 && Button_2 == 1){
			LCD_Clear();
			LCD_Goto(1,2);
			LCD_WriteString(word_B1);
			_delay_ms(500);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(2,16);
			LCD_WriteData(3);
			LCD_Goto(2,3);
			LCD_WriteData(2);

			LCD_Goto(2,1);
			LCD_WriteData(1);
			_delay_ms(500);
			LCD_Goto(2,1);
			LCD_WriteData(0);
			LCD_Goto(2,2);
			LCD_WriteData(1);
			_delay_ms(500);
			LCD_Goto(2,2);
			LCD_WriteData(0);
			_delay_ms(300);
			LCD_Goto(2,3);
			LCD_WriteData(1);

			LCD_Goto(2,15);
			LCD_WriteData(2);
			_delay_ms(1000);
			LCD_Clear();

			LCD_Goto(1,4);
			LCD_WriteString(word_Goal);
			_delay_ms(1000);
			LCD_Clear();
			_delay_ms(1000);
			LCD_Goto(1,4);
			LCD_WriteString(word_Goal);
			_delay_ms(1000);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(1,4);
			LCD_WriteString(word_Goal);
			_delay_ms(1000);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(1,4);
			LCD_WriteString(word_Goal);
			_delay_ms(1000);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(2,4);
			LCD_WriteString(word_EndGame);
			_delay_ms(500);
			LCD_Clear();
			_delay_ms(500);

		}

		else if (Button_1 == 1 && Button_2 == 0){
			LCD_Clear();
			LCD_Goto(1,2);
			LCD_WriteString(word_B2);
			_delay_ms(500);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(2,16);
			LCD_WriteData(3);
			LCD_Goto(2,3);
			LCD_WriteData(2);

			LCD_Goto(2,1);
			LCD_WriteData(1);
			_delay_ms(500);
			LCD_Goto(2,1);
			LCD_WriteData(0);
			LCD_Goto(2,2);
			LCD_WriteData(1);
			_delay_ms(500);
			LCD_Goto(2,2);
			LCD_WriteData(0);
			_delay_ms(300);
			LCD_Goto(2,3);
			LCD_WriteData(1);

			LCD_Goto(1,16);
			LCD_WriteData(2);
			_delay_ms(1000);
			LCD_Clear();

			LCD_Goto(1,4);
			LCD_WriteString(word_Lose);
			_delay_ms(1000);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(1,4);
			LCD_WriteString(word_Lose);
			_delay_ms(1000);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(1,4);
			LCD_WriteString(word_Lose);
			_delay_ms(1000);
			LCD_Clear();
			_delay_ms(500);
			LCD_Goto(2,4);
			LCD_WriteString(word_EndGame);
			_delay_ms(500);
			LCD_Clear();
			_delay_ms(500);
		}
		else {
/*			LCD_Goto(2,1);
			LCD_WriteData(1);
			LCD_Goto(2,3);
			LCD_WriteData(2);
			_delay_ms(1000);
			LCD_Goto(2,1);
			LCD_WriteData(0);
			LCD_Goto(2,3);
			LCD_WriteData(0);
			_delay_ms(500);
			LCD_Goto(2,1);
			LCD_WriteData(1);
			LCD_WriteData(2);
			_delay_ms(500);
*/		}

	}

}
