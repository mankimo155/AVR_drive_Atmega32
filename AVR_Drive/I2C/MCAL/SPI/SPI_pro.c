/*
 * SPI_pro.c
 *
 *  Created on: Sep 13, 2023
 *      Author: userH
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SPI_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"

void MSPI_vInit(void)
{

//#if SPI_MODE==SPI_MASTER

	MDIO_vSetPinDir(DIO_PORTB, DIO_PIN5, DIO_OUTPUT); // MOSI -> OUTPUT
	MDIO_vSetPinDir(DIO_PORTB, DIO_PIN7, DIO_OUTPUT); // SCK -> OUTPUT
	MDIO_vSetPinDir(DIO_PORTB, DIO_PIN6, DIO_INPUT); // MISO -> INPUT
	MDIO_vSetPinDir(DIO_PORTB, DIO_PIN6, DIO_HIGH);

//#endif

	const u8 spcr_setting = 0b01011110;

	/* write your configurable code here */

	SPCR = spcr_setting ;

}

u8   MSPI_u8Transceive(u8 A_u8Data)
{


	/* Start transmission */
	SPDR = A_u8Data;
	/* Wait for transmission complete */
	while(GET_BIT(SPSR, SPIF) != 1){}


//	dummy = SPSR ;
//	dummy = SPDR ;


	return SPDR;
}

