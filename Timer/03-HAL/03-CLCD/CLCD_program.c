/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  09/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  LCD                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "CLCD_interface.h"

void LCD_Init(void){
	DIO_voidSetPortDirection(DIO_u8PORTA ,DIO_u8PortOn);
	DIO_voidSetPinDirection(DIO_u8PORTB ,LCD_RS ,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTB ,LCD_EN ,DIO_u8OUTPUT);
	_delay_ms(50);
	LCD_WriteInst(0x38);
	LCD_WriteInst(0x0C);
	LCD_WriteInst(0x01);
	_delay_ms(1);
	LCD_WriteInst(0x06);

}

void LCD_WriteInst(uint8 Ins)
{
	DIO_voidSetPinValue(DIO_u8PORTB  ,LCD_RS ,LCD_SendCmd);
	DIO_voidSetPortValue(DIO_u8PORTA ,Ins);
	DIO_voidSetPinValue(DIO_u8PORTB  ,LCD_EN ,LCD_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DIO_u8PORTB  ,LCD_EN ,LCD_LOW);
	_delay_ms(1);
}

void LCD_WriteData(uint8 data)
{
	DIO_voidSetPinValue(DIO_u8PORTB  ,LCD_RS ,LCD_SendData);
	DIO_voidSetPortValue(DIO_u8PORTA ,data);
	DIO_voidSetPinValue(DIO_u8PORTB  ,LCD_EN ,LCD_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DIO_u8PORTB  ,LCD_EN ,LCD_LOW);
	_delay_ms(1);
}

void LCD_WriteString(char* Name)
{
	for(int i= 0 ; i < strlen(Name);i++)
	{
		LCD_WriteData(Name[i]);
	}
}

void LCD_Goto(uint8 row,uint8 col)
{
	 row--;
	 col--;
	 switch(row)
	 {
	 case 0: LCD_WriteInst(0x80+col);break;
	 case 1: LCD_WriteInst(0xc0+col);break;
	 }
	}
void LCD_PrintNumber(uint64 num)
{
	uint64 reverse= 1;
	    while (num > 0) //123
	    {
	        reverse= (reverse * 10) + num % 10;

	        num = num / 10;
	    }

	    while(reverse>1) //321
	    {

	    	LCD_WriteData((reverse%10)+48);
	    	reverse=reverse/10;
	    }
}

void LCD_PrintBinary(uint8 num)
{
	for (sint8 i=7; i>=0; i--)
	{
		LCD_WriteData(GET_BIT(num,i)?'1':'0');
	}

}

void LCD_PrintHex(uint8 num)
{
	uint8 Upper = 0, Lower = 0;
	LCD_WriteString("0X");

	Upper = num >> 4;     //0b000 0010
	Lower = num & 0X0f;   //0b000 0000

	if (Upper < 10){
		LCD_WriteData(Upper+'0');
	}
	else {

		LCD_WriteData(Upper+'A'-10);
	}

	if (Lower < 10){

		LCD_WriteData(Lower+'0');
	}
	else {

		LCD_WriteData(Upper+'A'-10);

	}
}


uint8 arr[] ={0x00,
		  	  0x00,
			  0x00,
			  0x07,
			  0x1D,
			  0x07,
			  0x00,
			  0x00};

uint8 arr_2[] ={0x00,
				0x00,
				0x00,
				0x07,
				0x1D,
				0x07,
				0x00,
				0x00};

void LCD_DrawCharInAdd(uint8 Data)
{
	LCD_WriteInst(0x40);
	for(uint8 i=0; i<8;i++){
		LCD_WriteData(arr[i]);
	}

	LCD_WriteInst(0x80);
	LCD_WriteData(Data);

}

void LCD_Draw_Char(uint8 Address_Data, uint8* charArray) {
    LCD_WriteInst(0x40 | (Address_Data * 8)); // Set CGRAM address
    for (uint8 j = 0; j < 8; j++) {
        LCD_WriteData(charArray[j]);
    }
    LCD_WriteInst(0x80); // Set DDRAM address to return to the display area
}

void LCD_Clear(void)
{
	LCD_WriteInst(0x01);
}


/*
uint8 LCD_ConvertNumToASCII(uint8 Input){
	return Input+0x30;
}
*/


sint32 LCD_ReverseNumber(sint32 NUM){
	uint32 reverse =1;
	while (NUM != 0){
		reverse = (reverse*10)+(NUM%10);
		NUM = NUM / 10;
	}
	return reverse;
}


void LCD_WriteNum(uint64 NUM) {
	if (NUM == 0){
		LCD_WriteData((NUM%10)+48);
	}
	else{
		uint64 reverse=1;
		reverse = LCD_ReverseNumber(NUM);
		while(reverse!=1)
		{
			LCD_WriteData((reverse%10)+48);
			reverse/=10;
		}
	}
}