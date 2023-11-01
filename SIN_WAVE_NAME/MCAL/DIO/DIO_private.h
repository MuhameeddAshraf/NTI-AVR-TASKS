/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  06/10/2023               */
/* Layer               :  MCAL Layer               */
/* SWC                 :  DIO                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef  DIO_PRIVATE_H
#define  DIO_PRIVATE_H

#define DDRA   *((uint8 *) 0x3A)
#define PORTA  *((uint8 *) 0x3B)
#define PINA   *((uint8 *) 0x39)

#define DDRB   *((uint8 *) 0x37)
#define PORTB  *((uint8 *) 0x38)
#define PINB   *((uint8 *) 0x36)

#define DDRC   *((uint8 *) 0x34)
#define PORTC  *((uint8 *) 0x35)
#define PINC   *((uint8 *) 0x33)

#define DDRD   *((uint8 *) 0x31)
#define PORTD  *((uint8 *) 0x32)
#define PIND   *((uint8 *) 0x30)


#endif
