/*************************************************
* Author               :   Mostafa hessin
* Date                 :   6/10/2023
* layer                :   HAL
* SWC                  :   LED
* Version              :   1.0.0
*************************************************/

#ifndef               SSD_INTERFACE_H
#define               SSD_INTERFACE_H


#define     SSD_u8Num0        0b00111111
#define     SSD_u8Num1        0b00000110
#define     SSD_u8Num2        0b01011011
#define     SSD_u8Num3        0b01001111
#define     SSD_u8Num4        0b01100110
#define     SSD_u8Num5        0b01101101
#define     SSD_u8Num6        0b01111101
#define     SSD_u8Num7        0b00000111
#define     SSD_u8Num8        0b01111111
#define     SSD_u8Num9        0b01101111

void SSD_voidSetSSD(uint8 Copy_u8PortNum ,uint8 Copy_u8Num);


#endif
