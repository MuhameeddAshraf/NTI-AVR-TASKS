/*
 * 7_Segment.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int SSD_ARR[3] = {0b00111111, 0b0000011, 0b01011011};

int main(void){
	DDRA = 0xff;
	int i;
	while(1){
		for(i=0; i<3; i++){
			PORTA = SSD_ARR[i];
			_delay_ms(200);
		}
	}
}
