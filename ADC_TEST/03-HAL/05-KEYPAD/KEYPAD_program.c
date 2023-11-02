/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  11/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  KEYPAD                   */
/* Version             :  1.0.0                    */
/***************************************************/ 

#include "KEYPAD_interface.h"

uint8 Keypad_arr[4][4]= {
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'c','0','=','+'},
};

void Keypad_init(void){


	/*SET DIRECTION OF ROW -------> OUTPUT */
		for (int i=0; i<4; i++){
		DIO_voidSetPinDirection(PortNum, i, DIO_u8OUTPUT);
	}

			/*SET VALUES OF ROW -----------> 1 */
	for (int i=0; i<4; i++){
		DIO_voidSetPinValue(PortNum, i, DIO_u8HIGH);
	}

		/*SET DIRECTION OF COL -------> INPUT */
	for (int i=4; i<8; i++){
		DIO_voidSetPinDirection(PortNum, i, DIO_u8INPUT);
	}

		/*SET VALUES OF COL -------> PULL UP */
	for (int i=4; i<8; i++){
			DIO_voidSetPinValue(PortNum, i, DIO_u8HIGH);
		}

}



uint8 KeyBad_uint8GetKey(void){
	uint8 Key = 'z';
	uint8 x = 1 ;
	for (int r=0; r<4; r++){
		DIO_voidSetPinValue(PortNum,r,DIO_u8LOW);
		for(int c=4; c<8; c++){
		 x=	DIO_u8GetPinValue(PortNum,c);
			if (x ==0){
				Key = Keypad_arr[r][c-4];
				}
			while (DIO_u8GetPinValue(PortNum,c) == 0);
		}
		DIO_voidSetPinValue(PortNum,r,DIO_u8HIGH);
	}
	return Key;
}

