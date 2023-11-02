/***************************************************/
/* Author              :  Mohamed AShraf           */
/* Origin Date         :  20/10/2023               */
/* Layer               :  MCAL LAYER               */
/* SWC                 :  ADC                      */
/* Version             :  1.0.0                    */
/***************************************************/ 

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


#define ADMUX            *((volatile uint8  *) 0x27)
#define ADMUX_ADLAR      5
#define ADMUX_REFS0      6
#define ADMUX_REFS1      7

#define ADCSRA           *((volatile uint8  *) 0x26)
#define ADCSRA_ADPS0     0
#define ADCSRA_ADPS1     1
#define ADCSRA_ADPS2     2
#define ADCSRA_ADIE      3
#define ADCSRA_ADIF      4
#define ADCSRA_ADATE     5
#define ADCSRA_ADSC      6
#define ADCSRA_ADEN      7

#define SFIOR            *((volatile uint8  *) 0x50)
#define SFIOR_ADTS0      5
#define SFIOR_ADTS1      6
#define SFIOR_ADTS2      7

#define ADCH             *((volatile uint8  *) 0x25)
#define ADCL             *((volatile uint8  *) 0x24)
#define ADC              *((volatile uint16 *) 0x24)


#define DIV_BY_64     6
#define DIV_BY_128    7


#define ADC_PRESC_MASK     0b11111000
#define ADC_CHANNEL_MASK   0b11100000


#endif 
