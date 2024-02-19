/*
 * SSD_int.h
 *
 *  Created on: Jul 14, 2023
 *      Author: userH
 */

#ifndef HAL_SSD_INT_H_
#define HAL_SSD_INT_H_

#define COM_CATHODE  1
#define COM_ANODE    0

#define SSD_TYPE  COM_CATHODE

#define SSD_PORT  DIO_PORTC

void HSSD_vInit(void);

void HSSD_vDisplayNum(u8 A_u8Num);

void HSSD_vTurnOff(void);

#endif /* HAL_SSD_INT_H_ */
