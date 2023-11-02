/*
 * main.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mohamed
 */
#include "../HAL/CLCD/CLCD_interface.h"


int main(void){


	    LCD_Init();
	    LCD_PrintHex(244);
}
