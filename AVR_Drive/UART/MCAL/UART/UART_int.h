/*
 * UART_int.h
 *
 *  Created on: Sep 10, 2023
 *      Author: userH
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_


#define UART_TX_COPLETE  0
#define UART_RX_COPLETE  1
#define UART_UDR_EMPTY   2

void MUART_vImit(void);
void MUART_vTransmit(u8 A_u18Byte);
u8 MUART_vRecieve(void);

void MUART_vSendString(u8 A_u8String[]);
void MUART_vSendNumber(s32 A_s32Number);
void MUART_vReceiveString(u8 A_u8String[],u32 A_u32Size);

void MUART_vEnableINT(u8 A_u8INTsource);
void MUART_vDisableINT(u8 A_u8INTsource);

void MUART_vTransmit_Asyn(char A_xstr[],u32 A_u16Size,void (*Fptr)(void));
void MUART_vRecieve_Asyn(char A_xBuffer[],u32 A_u16Size,void (*Fptr)(void));

#endif /* MCAL_UART_UART_INT_H_ */
