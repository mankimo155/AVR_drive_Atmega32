/*
 * UART_prv.h
 *
 *  Created on: Sep 10, 2023
 *      Author: userH
 */

#ifndef MCAL_UART_UART_PRV_H_
#define MCAL_UART_UART_PRV_H_


#define ENABLE  1
#define DISABLE 0

#define UDRE   5
#define RXC    7
#define RXCIE  7
#define TXCIE  6
#define UDRIE  5
#define RXEN   4
#define TXEN   3
#define UCSZ2  2
#define URSEL  7
#define UMSEL  6
#define USBS   3
#define UCSZ1  2
#define UCSZ0  1
#define UCPOL  0

#define ONE_BIT  0
#define TOW_BIT  1

#define UART_UBRR 51

#define UART_ASYN  0
#define UART_SYN  1

#define TXflaing_RXrising  0
#define RXflaing_TXrising  1

#define PARITY_DISABLE    0b000000
#define PARITY_EVEN_MODE  0b000010
#define PARITY_ODD_MODE   0b000011


#define CHAR_SIZE_5   0b000
#define CHAR_SIZE_6   0b001
#define CHAR_SIZE_7   0b010
#define CHAR_SIZE_8   0b011

#define UDR       *((volatile u8*)(0x2C))
#define UCSRA     *((volatile u8*)(0x2B))
#define UCSRB     *((volatile u8*)(0x2A))
#define UCSRC     *((volatile u8*)(0x40))
#define UBRRL     *((volatile u8*)(0x29))
#define UBRRH     *((volatile u8*)(0x40))

#endif /* MCAL_UART_UART_PRV_H_ */
