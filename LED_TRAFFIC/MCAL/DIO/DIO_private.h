/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  06/10/2023               */
/* Layer               :  MCAL Layer               */
/* SWC                 :  DIO                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define PORTA  *((uint8 *) 0x3B)
#define DDRA   *((uint8 *) 0x3A)
#define PINA   *((volatile uint8 *) 0x39)

#define PORTB  *((uint8 *) 0x38)
#define DDRB   *((uint8 *) 0x37)
#define PINB   *((volatile uint8 *) 0x36)

#define PORTC  *((uint8 *) 0x35)
#define DDRC   *((uint8 *) 0x34)
#define PINC   *((volatile uint8 *) 0x33)

#define PORTD  *((uint8 *) 0x32)
#define DDRD   *((uint8 *) 0x31)
#define PIND   *((volatile uint8 *) 0x30)


#endif
