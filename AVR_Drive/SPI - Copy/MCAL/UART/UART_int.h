/*
 * UART_int.h
 *
 *  Created on: Sep 10, 2023
 *      Author: userH
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void MUART_vImit(void);
void MUART_vTransmit(u8 A_u18Byte);
u8 MUART_u8Recieve(void);

void MUART_vSendString(u8 A_u8String[]);
void MUART_vSendNumber(s32 A_s32Number);


#endif /* MCAL_UART_UART_INT_H_ */
