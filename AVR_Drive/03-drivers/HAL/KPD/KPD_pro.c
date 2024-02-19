/*
 * KPD_pro.c
 *
 *  Created on: Jul 14, 2023
 *      Author: userH
 */
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "KPD_int.h"

#include"util/delay.h"



void HKPD_vInit(void)
{
	MDIO_vSetPortDir(KPD_PORT, 0x0f);
	MDIO_vSetPortVal(KPD_PORT, 0xff);
}

u8   HKPD_u8GetPressedKey(void)
{
	u8 pressed_key = 0 ;
	for(u8 col=0; col<4; col++)
	{
		/* activate current column */
		MDIO_vSetPinVal(KPD_PORT, col, DIO_LOW);
		for(u8 row=0; row < 4; row++)
		{
			if(MDIO_u8GetPinVal(KPD_PORT, row+4) == 0) // a button in pressed
			{
				pressed_key = row + (col*4) +1  ;
			}
			while(MDIO_u8GetPinVal(KPD_PORT, row+4) == 0){}
			_delay_ms(10);
		}
		/* deactivate current column */
		MDIO_vSetPinVal(KPD_PORT, col, DIO_HIGH);
	}
	return pressed_key;
}




