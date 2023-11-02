/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  06/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  SSD                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef               SSD_INTERFACE_H
#define               SSD_INTERFACE_H

#define SEVEN_SEGMENT_PORT 	DIO_u8PORTD
#define SEVEN_SEGMENT_PORT2 DIO_u8PORTB

#define ZERO  0b00111111
#define ONE   0b00000110
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111


void SevenSegments_voidInit();
void SevenSegments_voidDispalyDecreasecount(uint8 Copy_u8Seconds);
void SevenSegments_voidDispaly(uint8 Copy_u8Value);
void SevenSegment_voidInit(void);
void SevenSegment_voidDispaly(uint8 Copy_u8Value);

#endif
