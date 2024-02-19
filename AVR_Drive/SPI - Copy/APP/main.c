/*
 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: userH
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/DIO/DIO_int.h"

#include <util/delay.h>





int main(void)
{
	u8 C ;

	MSPI_vInit();
	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

	_delay_ms(2000);

	C = MSPI_u8Transceive('M');
	if(C == 'M')
	{
		MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
	}
	while(1)
	{

	}
}

