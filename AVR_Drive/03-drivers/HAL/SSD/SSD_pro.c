/*
 * SSD_pro.c
 *
 *  Created on: Jul 14, 2023
 *      Author: userH
 */

#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"SSD_int.h"

static const u8 CGS_SSD_u8Nums[] = {
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b01111101,
		0b01000111,
		0b01111111,
		0b01101111
};
void HSSD_Init(void)
{
	DIO_vSetPortDir(SSD_PORT, 0xff );
}

void HSSD_vDisplayNum(u8 A_u8Num)
{
	if(A_u8Num < 10)
	{
#if SSD_TYPE == COM_CATHODE
		DIO_vSetPortVal(SSD_PORT, CGS_SSD_u8Nums[A_u8Num]);

#elif SSD_TYPE==COM_ANODE
		DIO_vSetPortVal(SSD_PORT, ~CGS_u8SSD_Nums[A_u8Num]);

#endif
	}
}

void HSSD_vTurnOff(void)
{

#if SSD_TYPPE == COM_CATHODE
	DIO_vSetPortVal(SSD_PORT, 0);

#elif SSD_TYPPE == COM_ANODE
	DIO_vSetPortVal(SSD_PORT,0xff);

#endif
}

