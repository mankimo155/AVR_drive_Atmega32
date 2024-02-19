/*
 * MADC-int.h
 *
 *  Created on: Jul 24, 2023
 *      Author: userH
 */

#ifndef MCAL_ADC_MADC_INT_H_
#define MCAL_ADC_MADC_INT_H_



void MADC_vInit(void);
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo);

/* Interrupt based APIs */
void MADC_vStartConversion(u8 A_u8ChannelNo);
u16   MADC_u16GetADCData(void);
void MADC_vSetCallback( void (*A_Fptr)(void)  );

#endif /* MCAL_ADC_MADC_INT_H_ */
