/*
 * STM-pro.c
 *
 *  Created on: Jul 22, 2023
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "util/delay.h"
#include "STM-int.h"

void HSTPR_vInit()
{
	MDIO_vSetPortDir(STPR_PORT,STPR_PORT_DIR);

}
void HSTPR_vRotateCW(u16 A_u16Angle)
{
	u8 L_u8NumOfFullStep = 0;
	u8 L_u8NumOfStep = 0 ;
	L_u8NumOfStep = A_u16Angle/STPR_STEP_ANGEL;
	L_u8NumOfStep = A_u16Angle/(STPR_STEP_ANGEL*STPR_STEP_NUM) ;

	if(L_u8NumOfStep>8)
	{

		for(u8 j=0 ; j<L_u8NumOfFullStep;j++)
		{
			for(s8 i = 7;i >= 0;i--)
			{
				MDIO_vSetPortVal(STPR_PORT,L_u8Steps[i]);
				_delay_ms(2);

			}
		}
	}

}

void HSTPR_vRotateCCW(u16 A_u16Angle)
{

	u8 L_u8NumOfFullStep = 0;
	u8 L_u8NumOfStep = 0 ;
	L_u8NumOfStep = A_u16Angle/STPR_STEP_ANGEL;
	L_u8NumOfStep = A_u16Angle/(STPR_STEP_ANGEL*STPR_STEP_NUM) ;

	if(L_u8NumOfStep>8)
	{

		for(u8 j=0 ; j<L_u8NumOfFullStep;j++)
		{
			for(u8 i = 0;i < 8;i++)
			{
				MDIO_vSetPortVal(STPR_PORT,L_u8Steps[i]);
				_delay_ms(2);

			}
		}
	}


}

void HSTPR_vRotateStepsCW(u16 A_u16Steps)
{
	u8 L_u8NumOfFullStep = 0;
	L_u8NumOfFullStep = A_u16Steps/STPR_STEP_NUM;


	if(	A_u16Steps>8)
	{

		for(u8 j=0 ; j<L_u8NumOfFullStep;j++)
		{
			for(s8 i = 7;i >= 0;i--)
			{
				MDIO_vSetPortVal(STPR_PORT,L_u8Steps[i]);
				_delay_ms(2);

			}
		}
	}


}
void HSTPR_vRotateStepsCCW(u16 A_u16Steps)
{

	u8 L_u8NumOfFullStep = 0;
	L_u8NumOfFullStep = A_u16Steps/STPR_STEP_NUM;


	if(	A_u16Steps>8)
	{

		for(u8 j=0 ; j<L_u8NumOfFullStep;j++)
		{
			for(u8 i = 0;i < 8;i++)
			{
				MDIO_vSetPortVal(STPR_PORT,L_u8Steps[i]);
				_delay_ms(2);

			}
		}
	}
}


