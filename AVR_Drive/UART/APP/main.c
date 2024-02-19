/*
 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: userH
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/UART/UART_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI-int.h"
#include "../MCAL/DIO/DIO_int.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


u8 G_u8Cunter=0;
u8 G_u8I=0;
u8 G_String[32];
ISR(INT2_vect)
{
	if(G_u8Cunter!=0)
	{
	HLCD_vShiftPostion(SHIFT_Cursor_LEFT);
	HLCD_vSendChar(' ');
	HLCD_vShiftPostion(SHIFT_Cursor_LEFT);
	G_u8Cunter--;
	}

	if(G_u8Cunter>16)
	{
		G_u8I--;
	}

}

int main(void)
{

	MEXTI_vEnableInterrupt(EXTI_INT2);
	MEXTI_vSetSenseControl(EXTI_INT2,EXTI_FALLING_EDGE);
	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	HLCD_vInit();
	MUART_vImit();
	MGIE_vEnableGlobalInterrupt();

	while(1)
	{


		if(G_u8Cunter<16)
		{

				HLCD_vSendChar(MUART_vRecieve());
				G_u8Cunter++;

		}
		else if (G_u8Cunter<33)
		{

				HLCD_vGoToXY(1,G_u8I);
				HLCD_vSendChar(MUART_vRecieve());
				G_u8Cunter++;
				G_u8I++;

		}
		else
		{
			HLCD_vClearDisplay();
			G_u8Cunter=0;
			G_u8I=0;

		}


	}
}

