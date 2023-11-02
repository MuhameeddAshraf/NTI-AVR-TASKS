/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  09/10/2023               */
/* Layer               :  HAL Layer               */
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
void print_Number(uint64 num)
{
	uint64 reverse= 0;
	    while (num > 0) //123
	    {
	        reverse= (reverse * 10) + num % 10;

	        num = num / 10;
	    }
	    while(reverse>0) //321
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
		LCD_Goto(1,3);
		LCD_WriteData(Upper+'0');
	}
	else {
		LCD_Goto(1,3);
		LCD_WriteData(Upper+'A'-10);
	}

	if (Lower < 10){
		LCD_Goto(1,4);
		LCD_WriteData(Lower+'0');
	}
	else {
		LCD_Goto(1,4);
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

void LCD_Arabic_letter(uint8 Data)
{
	LCD_WriteInst(0x40);
	for(uint8 i=0; i<8;i++){
		LCD_WriteData(arr[i]);
	}

	LCD_WriteInst(0x80);
	LCD_WriteData(Data);

}

