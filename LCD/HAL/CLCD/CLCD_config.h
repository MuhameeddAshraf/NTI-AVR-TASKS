/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  09/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  LCD                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef      CLCD_CONFIG_H
#define      CLCD_CONFIG_H

#define    LCD_DataPort  	  PORTA
#define    LCD_RS   	   	DIO_u8PIN5
#define    LCD_RW		   	DIO_u8PIN6
#define    LCD_EN		   	DIO_u8PIN7

#define    LCD_DataPort   	   PORTA

#define    LCD_SendCmd      	  0
#define    LCD_SendData       	  1

#define    LCD_HIGH           	  1
#define    LCD_LOW		      	  0




#endif

