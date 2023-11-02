/*****************************************************************************/
/* Author       	: 	Mohamed Ashraf	                                     */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            : 	External Interrupt                                   */
/* Version      	: 	1                                                    */
/*****************************************************************************/


#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

#define HWR8(X)     *((volatile uint8*)(X))

#define MCUCR          	HWR8(0x55)
#define MCUCR_ISC00    		0
#define MCUCR_ISC01    		1
#define MCUCR_ISC10    		2
#define MCUCR_ISC11    		3

#define MCUCSR         	HWR8(0x54)
#define MCUCSR_ISC2    		6

#define GICR       	   	HWR8(0x5B)
#define GICR_INT0			6
#define GICR_INT1     		7
#define GICR_INT2			5

#define GIFR          	HWR8(0x5A)
#define GIFR_INTF0			6
#define GIFR_INTF1			7
#define GIFR_INTF2			5


#endif 
