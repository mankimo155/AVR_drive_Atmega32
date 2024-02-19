/*
 * main.c
 *
 *  Created on: Jul 19, 2023
 *      Author: userH
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include <util/delay.h>



int main(void)
{

	u8 L_u8Steps[]={9,1,3,2,6,4,12,8};
	MDIO_vSetPortDir(DIO_PORTA,0x0f);

	while(1)
	{

		for(u8 j=0 ; j<16;j++)
		{
			for(s8 i = 8;i >= 0;i--)
			{
				MDIO_vSetPortVal(DIO_PORTA,L_u8Steps[i]);
				_delay_ms(2);
			}

		}

		/*
				for(u8 j=0 ; j<16;j++)
		{
			for(s8 i = 0;i < 8;i++)
			{
				MDIO_vSetPortVal(DIO_PORTA,L_u8Steps[i]);
				_delay_ms(2);
			}

		}
		 */

	}
}
