/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  14/10/2023               */
/* Layer               :  HAL Layer                */
/* SWC                 :  PUSHBUTTON               */
/* Version             :  1.0.0                    */
/***************************************************/

#ifndef     PushButton_CONFIG_H
#define     PushButton_CONFIG_H

typedef enum {
	Button_PRESSESD =0,
	Button_RELEASED
}Button_state;

typedef struct {
	uint8 Button_pin;
	uint8 Button_port;
	Button_state Button;
}Button;


#endif