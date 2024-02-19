/*
 * main.c
 *
 *  Created on: Jul 24, 2023
 *      Author: userH
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/ADC/MADC-int.h"
#include "../MCAL/ADC/MADC-prv.h"
#include "../MCAL/GIE/GIE_int.h"
#include <util/delay.h>

volatile u16 G_u16Adc_Value = 0 ;

void Adc_Isr(void)
{
	HLCD_vGoToXY(0,5);
	G_u16Adc_Value = MADC_u16GetADCData();
	G_u16Adc_Value = (G_u16Adc_Value * 500)/1024;
	HLCD_vPrintNumber(G_u16Adc_Value);
	_delay_ms(1000);
	MADC_vStartConversion(CHANNEL_00);


}

int main(void)
{
	MGIE_vEnableGlobalInterrupt();
	MADC_vSetCallback(Adc_Isr);
	MADC_vInit();
	HLCD_vInit();
	HLCD_vPrintString("Temp= ");
	MADC_vStartConversion(CHANNEL_00);


	while(1)
	{

	}


}




/*
 * u8 L_u8AdcV=0;
	u8 L_u8VlauePin = 0 ;
	L_u8VlauePin = DIO_PIN0;
	MDIO_vSetPortDir(DIO_PORTB,0xff);
	MADC_vInit();

	while(1)
	{
		if(MADC_u16AnalogRead(0) > L_u8AdcV)
		{
			MDIO_vSetPinVal(DIO_PORTB,L_u8VlauePin,DIO_HIGH);
			L_u8VlauePin++;

		}
		else if(MADC_u16AnalogRead(0) < L_u8AdcV)
		{
			MDIO_vSetPinVal(DIO_PORTB,L_u8VlauePin,DIO_LOW);
			L_u8VlauePin--;

		}
		else if(MADC_u16AnalogRead(0)==0)
			MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_LOW);

		L_u8AdcV = 	MADC_u16AnalogRead(0);




	}
 * */
