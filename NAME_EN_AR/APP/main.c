/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  13/10/2023               */
/* Layer               :  APP LAYER                */
/* SWC                 :  LCD                      */
/* Version             :  1.0.0                    */
/***************************************************/

#include "../HAL/CLDC/CLCD_interface.h"
//#include "../HAL/KEYPAD/KEYPAD_interface.h"

uint8 arr_N1[8] = {0x00,0x00,0x00,0x00,0x1F,0x05,0x07,0x00}; // M
uint8 arr_N2[8] = {0x00,0x00,0x0F,0x01,0x1F,0x00,0x00,0x00}; // H
uint8 arr_N3[8] = {0x00,0x00,0x04,0x04,0x1F,0x00,0x00,0x00}; // D
//uint8 arr_N4[8] = {0x0E,0x0E,0x04,0x0E,0x15,0x1F,0x00,0x00}; // Castle
uint8 arr_N4[8] = {0x00,0x00,0x0A,0x00,0x11,0x0E,0x00,0x00}; // Smile



//uint8 arr_Name[] = {'M','o','h','a','m','e','d'} ;

int main(void){
	LCD_Init();
	uint8 arr_Name[] = {'M','u','h','a','m','e','d'} ;
	LCD_Draw_Char(0, arr_N1);
	LCD_Draw_Char(1, arr_N2);
	LCD_Draw_Char(2, arr_N1);
	LCD_Draw_Char(3, arr_N3);
	LCD_Draw_Char(4, arr_N4);

	while (1){
		uint8 row = 2, col = 16, col_ar =1, j=0 ;
/*
		/////////////////////////////////////
		//			WRITE ARABIC WORD      //
		/////////////////////////////////////
		while (col > 0 ){
			LCD_Goto(row,col);
			LCD_WriteData(j);
			_delay_ms(250);
			col-- ;
			j++;
			if (row == 2 && col == 0){
				col = 16;
			}
			if(j == 5){
				j = 0 ;
			}
		}
*/


		//////////////////////////////////////
		//			WRITE ENGLISH WORD		//
		//////////////////////////////////////
		row = 1; col_ar = 1; j = 0;
		while (col_ar < 16){
			LCD_Goto(row,col_ar);
			LCD_WriteData(arr_Name[j]);
			_delay_ms(250);
			col_ar++;
			j++;
			if (col_ar == 16 && row == 1){
				LCD_WriteData(arr_Name[j]);
				col_ar = 0;
			}
			if (j==7){
				j=0;
			}
		}  // Comment here

	}

}
