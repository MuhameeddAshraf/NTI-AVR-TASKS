/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  09/10/2023               */
/* Layer               :  HAL Layer               */
/* SWC                 :  LCD                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef            CLCD_INTERFACE_H
#define            CLCD_INTERFACE_H

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include "util/delay.h"
#include  <string.h>
#include  <stdio.h>
#include  <stdlib.h>



void LCD_Init(void);
void LCD_WriteInst(uint8 Ins);
void LCD_WriteData(uint8 Data);
void LCD_WriteString(char* Name);
void print_Number(uint64 num);
void LCD_Goto(uint8 row,uint8 col);
void LCD_PrintBinary(uint8 num);
void LCD_Arabic_letter(uint8 Data);
void LCD_PrintHex(uint8 num);
void LCD_Clear(void);


#endif
