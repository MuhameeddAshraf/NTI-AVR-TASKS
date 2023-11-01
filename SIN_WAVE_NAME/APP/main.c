/*
 * main.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Mohamed
 */


#include "../HAL/CLCD/CLCD_interface.h"
//#include "../HAL/KEYPAD/KEYPAD_interface.h"

int main(void){

	LCD_Init();

	while (1){
		LCD_WriteString("Mohamed");
		_delay_ms(500);
		LCD_Clear();

		LCD_Goto(2,4);
		LCD_WriteString("Mohamed");
		_delay_ms(500);
		LCD_Clear();

		LCD_Goto(1,7);
		LCD_WriteString("Mohamed");
		_delay_ms(500);
		LCD_Clear();

		LCD_Goto(2,10);
		LCD_WriteString("Mohamed");
		_delay_ms(500);
		LCD_Clear();

		LCD_Goto(1,7);
		LCD_WriteString("Mohamed");
		_delay_ms(500);
		LCD_Clear();

		LCD_Goto(2,4);
		LCD_WriteString("Mohamed");
		_delay_ms(500);
		LCD_Clear();

	}
}
