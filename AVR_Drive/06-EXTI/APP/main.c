/*

 * main.c
 *
 *  Created on: Jul 23, 2023
 *      Author: userH
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI-int.h"
#include "../MCAL/EXTI/EXTI-con.h"
#include "../MCAL/GIE/GIE_int.h"
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>


ISR(INT2_vect)
{
	MDIO_vTogPinVal(DIO_PORTA,DIO_PIN0);
}

int main(void)
{
MEXTI_vEnableInterrupt(EXTI_INT2);
MEXTI_vSetSenseControl(EXTI_INT2,EXTI_FALLING_EDGE);
MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
MGIE_vEnableGlobalInterrupt();



	while(1)
	{

	}

}

