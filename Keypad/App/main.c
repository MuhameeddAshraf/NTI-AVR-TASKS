/*
 * main.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Mohamed
 */

#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"

int main(void){
	uint64 num_1 = 0 , num_2 = 0 , result = 0 ;
	char operator = ' ';
	LCD_Init();
	Keypad_init();

/*
              // Convert Binary .. Hex //
   	uint64 num = 0;

	while (1){
	uint64 n = KeyBad_uint8GetKey();

	if(n != 'z'){
		LCD_WriteData(n);
		if(n >= '0' && n <= '9'){
			num = num * 10 +(n-'0');
		}
		else if (n == '='){
			LCD_Goto(2,1);
			LCD_PrintBinary(num);
			LCD_Goto(2,11);
			LCD_PrintHex(num);
		}
		else if (n == 'c'){
				num=0;
				LCD_Clear();
				LCD_Goto(1,1);
			}
	}
  }

*/

          	//    Sum of two numbers //


	while (1){
		uint64 n = KeyBad_uint8GetKey();

		if(n != 'z'){
			LCD_WriteData(n);
			if(n >= '0' && n <= '9'){

				if (operator == ' '){
					num_1 = num_1 * 10 +(n-'0');
				}else {
					num_2 = num_2 * 10 +(n-'0');
				}
			}
			else if (n == '+'){
				operator = '+';
			}
			else if (n == '='){
				if (operator == '+'){
				result = num_1 + num_2;
				LCD_Goto(2,1);
				LCD_PrintNumber(result);
				num_1 = result;
				num_2 = 0;
				LCD_Clear();
				LCD_PrintNumber(num_1);
				}
			}else if (n == 'c'){
				num_1=0;
				num_2=0;
				operator = ' ';
				LCD_Clear();
				LCD_Goto(1,1);
			}
		}
	}
}
