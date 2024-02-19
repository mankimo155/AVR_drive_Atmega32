/*
 * SPI_prv.h
 *
 *  Created on: Sep 13, 2023
 *      Author: userH
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPI_MASTER   1
#define SPI_SLAVE	 2


#define SPIF		7
#define SPCR		*((volatile u8*)(0x2D))
#define SPSR		*((volatile u8*)(0x2E))
#define SPDR		*((volatile u8*)(0x2F))

#endif /* MCAL_SPI_SPI_PRV_H_ */
