/*
 * 0-99.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mohamed
 */
#include "STD_TYPES.h"
#include "DIO_private.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <util/delay.h>


uint8 SEGMENT[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b011111111,0b01101111};



int main() {
    DDRC &= ~(1 << DIO_u8PIN0);
    PORTC |= (1 << DIO_u8PIN0);
    DDRA = 0xff;
    DDRB = 0xff;

    uint8 ones = 0, tens = 0;
    uint8 switch_state = 0;

    while (1) {
        if (PINC & (1 << DIO_u8PIN0)) {
            if (switch_state == 0) {
                switch_state = 1;
                ones++;
                if (ones == 10) {
                    ones = 0;
                    tens++;
                    if (tens == 10) {
                        tens = 0;
                    }
                }
            }
        } else {
            switch_state = 0;
        }


        if (switch_state == 1) {
            PORTA = SEGMENT[ones];
            PORTB = SEGMENT[tens];
        }

        _delay_ms(100);
    }
}
