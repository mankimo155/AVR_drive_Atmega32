/*
 * main.c
 *
 *  Created on: Jul 16, 2023
 *      Author: userH
 */
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/KPD/KPD_int.h"
#include <util/delay.h>

u8 G_Custom0[]={0, 0, 0, 31, 9, 9, 15, 0};
u8 G_Custom1[]={24, 4, 2, 31, 0, 0, 0, 0};
u8 G_Custom2[]={0, 0, 0, 31, 10, 10, 14, 0};
u8 G_Custom3[]={0, 28, 20, 31, 4, 4, 28, 0};
u8 G_Custom4[]={0, 0, 0, 2, 2, 14, 0, 0};
u8 G_u8Pattern1[]={10, 21, 10, 4, 0, 0, 0, 0};

void main(void)
{
	u8 L_u8Sum=0;
	u8 L_u8Flag=0 ;

	u8 L_u8Name0={"MAHMOUD"};
	u8 L_u8Name={"ASMAA"};
	u8 L_u8Name1={"MY LOVE"};
	HLCD_vInit();
	HKPD_vInit();
	HLCD_vPrintString("Tahoon");
	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTA,DIO_PIN7,DIO_HIGH);
	/*
	HLCD_vSaveCustomChar(0,G_Custom0);
	HLCD_vSaveCustomChar(1,G_Custom1);
	HLCD_vSaveCustomChar(2,G_Custom2);
	HLCD_vSaveCustomChar(3,G_Custom3);
	HLCD_vSaveCustomChar(4,G_Custom4);
	HLCD_vSaveCustomChar(5,G_u8Pattern1);
	 */


	/*
	HLCD_vGoToXY(0,10);
	HLCD_vDisplayCustomChar(0);
	HLCD_vGoToXY(0,9);
	HLCD_vDisplayCustomChar(1);
	HLCD_vGoToXY(0,8);
	HLCD_vDisplayCustomChar(2);
	HLCD_vGoToXY(0,7);
	HLCD_vDisplayCustomChar(3);
	HLCD_vGoToXY(0,6);
	HLCD_vDisplayCustomChar(4);

	 */
	/*
HLCD_vPrintString(L_u8Name0);
HLCD_vDisplayCustomChar(5);
HLCD_vPrintString(L_u8Name);
HLCD_vGoToXY(1,3);
HLCD_vPrintString(L_u8Name1);
	 */

	/*
		for(u8 L_u8Cunter0=0 ;L_u8Cunter0 < 2 ;L_u8Cunter0++)
		{
			for(u8 L_u8Cunter1=0;L_u8Cunter1<=15;L_u8Cunter1++)
			{
				HLCD_vClearDisplay();
				HLCD_vGoToXY(L_u8Cunter0,L_u8Cunter1);
				HLCD_vPrintString(L_u8Name0);
				_delay_ms(25);

			}*/


	while(1)

	{
/*
		switch(HKPD_u8GetPressedKey())
		{
		case 2 :
			HLCD_vClearDisplay();
			HLCD_vGoToXY(0,0);
			HLCD_vPrintString(L_u8Name0);
			L_u8Flag=0;
			break;
		case 8 :
			HLCD_vClearDisplay();
			HLCD_vGoToXY(1,0);
			HLCD_vPrintString(L_u8Name0);
			L_u8Flag=1;
			break;
		case 4 :
			if(L_u8Flag ==0)
			{
				HLCD_vClearDisplay();
				HLCD_vGoToXY(0,0);
				HLCD_vPrintString(L_u8Name0);
			}
			else
			{
				HLCD_vClearDisplay();
				HLCD_vGoToXY(1,0);
				HLCD_vPrintString(L_u8Name0);
			}
			break;
		case 6 :
			if(L_u8Flag ==0)
			{
				HLCD_vClearDisplay();
				HLCD_vGoToXY(0,7);
				HLCD_vPrintString(L_u8Name0);
			}
			else
			{
				HLCD_vClearDisplay();
				HLCD_vGoToXY(1,7);
				HLCD_vPrintString(L_u8Name0);
			}
			break;

		}
*/
		/*
HLCD_vPrintNumber(HKPD_u8GetPressedKey());
*/

	}
}
