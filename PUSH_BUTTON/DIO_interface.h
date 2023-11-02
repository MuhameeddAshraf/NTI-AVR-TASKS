/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  06/10/2023               */
/* Layer               :  MCAL Layer               */
/* SWC                 :  DIO                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_u8PORTA         1
#define DIO_u8PORTB         2
#define DIO_u8PORTC         3
#define DIO_u8PORTD         4

#define DIO_u8OUTPUT        1
#define DIO_u8INPUT         0

#define DIO_u8HIGH 	        1
#define DIO_u8LOW           0


#define DIO_u8PIN0          0
#define DIO_u8PIN1          1
#define DIO_u8PIN2          2
#define DIO_u8PIN3          3
#define DIO_u8PIN4          4
#define DIO_u8PIN5          5
#define DIO_u8PIN6          6
#define DIO_u8PIN7          7

#define PINA   *((volatile uint8 *)0x39)
#define PINB   *((volatile uint8 *)0x36)
#define PINC   *((volatile uint8 *)0x33)
#define PIND   *((volatile uint8 *)0x30)


#define DIO_u8PORTHIGH    0xFF
#define DIO_u8PORTLOW     0x00

#define DIO_u8PORTOUTPUT  0xFF
#define DIO_u8PORTINPUT   0x00




void  DIO_voidSetPinDirection(uint8 Copy_u8PortNum, uint8 Copy_u8PinNum, uint8 Copy_u8Mode);

void  DIO_voidSetPinValue(uint8 Copy_u8PortNum, uint8 Copy_u8PinNum, uint8 Copy_u8Value);

uint8 DIO_u8GetPinValue(uint8 Copy_u8PortNum, uint8 Copy_u8PinNum);

void DIO_voidSetPortDirection(uint8 Copy_u8PortNum, uint8 copy_u8Mode);

void DIO_voidSetPortValue(uint8 Copy_u8PortNum, uint8 Copy_u8Value);

void DIO_voidSetTogglePin(uint8 Copy_u8PortNum,uint8 Copy_u8PinNum);


#endif
