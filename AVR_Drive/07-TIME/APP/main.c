/*
 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: userH
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/TIMER/TIMER-int.h"
#include "../MCAL/GIE/GIE_int.h"
#include <util/delay.h>

/*how to creat ICU*/

volatile u8 reading_flag = 0;
volatile u16 PT;
volatile u16 ont ;

void readPWM(void)
{
	static u8 counter = 0;
	static u16 timereadings[3];
	counter ++;
	switch(counter)
	{
	case 1 :
		timereadings[counter-1]=MTIMERS_u16GetCapturedValue();
		MTIMERS_vSetIcuTrigger(ICU_Rising);

		break;
	case 2 :
		timereadings[counter-1]=MTIMERS_u16GetCapturedValue();
		MTIMERS_vSetIcuTrigger(ICU_Falling);
		PT=timereadings[1]-timereadings[0];
			break;
	case 3 :
		timereadings[counter-1]=MTIMERS_u16GetCapturedValue();
		MTIMERS_vSetIcuTrigger(ICU_Rising);
		MTimers_vIsrFeatuer(u16TIMER1,ISR_DISABLE);
		ont=timereadings[2]-timereadings[1];
		counter=0;
		reading_flag=1;
		break;
	}
}




int main(void)
{
	MGIE_vEnableGlobalInterrupt();
	HLCD_vInit();
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	MTIMERS_vSetCallback(u16TIMER1,TIM_mode_ICU,readPWM);
	MTimers_vIsrFeatuer(u16TIMER1,ISR_ICU);
	MTIMERS_vSetCompareValue(TIMER0,127);
	MTimers_vIsrFeatuer(TIMER0,ISR_DISABLE);
	MTIMERS_vInit();
	MTIMERS_vStartTimer(TIMER0);



	while(1)
	{
		if(reading_flag)
		{
			reading_flag=0;
			HLCD_vClearDisplay();
			HLCD_vPrintString("ont =");
			HLCD_vPrintNumber(ont);
			HLCD_vGoToXY(1,0);
			HLCD_vPrintString("PT=");
			HLCD_vPrintNumber(PT);
			_delay_ms(1000);
			MTimers_vIsrFeatuer(u16TIMER1,ISR_ICU);
		}
	}
}

