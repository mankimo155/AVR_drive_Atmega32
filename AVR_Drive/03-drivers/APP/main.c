/*
 * main.c
 *
 *  Created on: Jul 13, 2023
 *      Author: userH
 */

#include"../LIB/STD_TYPES.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../HAL/SSD/SSD_int.h"
#include<util/delay.h>

int main(void)
{

	HSSD_Init();
	HKPD_vInit();

	while(1)
	{
HSSD_vDisplayNum(HKPD_u8GetPressedKey());
	}




}
