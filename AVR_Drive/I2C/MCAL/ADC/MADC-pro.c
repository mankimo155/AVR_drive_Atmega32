/*
 * MADC-pro.c
 *
 *  Created on: Jul 24, 2023
 *      Author: userH
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "MADC-cfg.h"
#include "MADC-prv.h"
#include "MADC-int.h"


void (*ADC_CallBack)(void);



void MADC_vInit(void)
{
	/* 1- Reference voltage selection */
#if ADC_REF_VOLT==AVCC
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#elif ADC_REF_VOLT==INTERNAL_REF
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, REFS0);
#elif ADC_REF_VOLT==AREF
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#else
#error "Please select correct refence voltage"
#endif

	/* 2- Data Adjustment direction  */
	CLR_BIT(ADMUX, ADLAR);
	/* 3- Select Prescaler Bits    */
	ADCSRA = (ADCSRA & 0xF8) | (ADC_PRESCALER) ;
	/* 4- Auto trigger Enable     */
	/*  4a- Select Auto trigger source  */
	CLR_BIT(ADCSRA, ADATE);
	/* 5- Interrupt Enable/disable    */
#if ADC_INTERRUPT_ENABLE==DISABLE
	CLR_BIT(ADCSRA, ADIE);
#elif ADC_INTERRUPT_ENABLE==ENABLE
	SET_BIT(ADCSRA, ADIE);
#endif
	/* 6- Enable ADC peripheral   */
	SET_BIT(ADCSRA, ADEN);
}

u16 MADC_u16AnalogRead(u8 A_u8ChannelNo)
{

	/* 1- Select Channel   */
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07) ;
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
	/* 3- Poll on Flag     */
	while( GET_BIT(ADCSRA, ADIF) != 1 ){}
	/* 4- Clear Flag       */
	SET_BIT(ADCSRA, ADIF);
	/* 5- return ADC Data  */
	return ADC;
}


void MADC_vStartConversion(u8 A_u8ChannelNo)
{
	/* 1- Select Channel   */
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07) ;
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
}


u16   MADC_u16GetADCData(void)
{
	/* 5- return ADC Data  */
	return ADC;
}

void MADC_vSetCallback( void (*A_Fptr)(void)  )
{


	ADC_CallBack = A_Fptr;

}

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	 ADC_CallBack();
}

