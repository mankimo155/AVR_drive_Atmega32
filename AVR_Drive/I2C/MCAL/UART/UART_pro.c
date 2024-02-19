/*
 * UART_pro.c
 *
 *  Created on: Sep 10, 2023
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "UART_int.h"
#include "UART_prv.h"
#include "UART_cfg.h"


void MUART_vImit(void)
{
	/*UART TX AND RX ENABLE*/
#if UART_TX_EN==ENABLE
	SET_BIT(UCSRB,TXEN);
#else
	CLR_BIT(UCSRB,TXEN);
#endif
#if UART_RX_EN==ENABLE
	SET_BIT(UCSRB,RXEN);
#else
	CLR_BIT(UCSRB,RXEN);
#endif
	/*UART ISR EN*/
#if UART_ISR_EN==ENABLE
#if RX_COMPLETE_ISR_EN==ENABLE
	SET_BIT(UCSRB,RXCIE);
#endif
#if TX_COMPLETE_ISR_EN==ENABLE
	SET_BIT(UCSRB,TXCIE);
#endif
#if UDR_EMPTY_ISR_EN==ENABLE
	SET_BIT(UCSRB,UDRIE);
#endif
#else
	UCSRB = UCSRB & 0x1F ;
#endif

	/*UART CHAR SIZE*/



	/*UART MODE */


	/*UART Parity Mode*/



/*USART Baud Rate*/
	UBRRL = UART_UBRR_VALUE ;


/*	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	*/
}

void MUART_vTransmit(u8 A_u18Byte)
{


	/* Wait for empty transmit buffer */
	while(!( UCSRA & (1<<UDRE))){}

	/* Put data into buffer, sends the data */
	UDR = A_u18Byte;

}


u8 MUART_u8Recieve(void)
{
	/* Wait for data to be received */
	while(!(UCSRA & (1<<RXC))){}

	/* Get and return received data from buffer */
	return UDR;

}


void MUART_vSendString(u8 A_u8String[])
{
	for(u8 L_u8I = 0 ; A_u8String[L_u8I] != '\0' ; L_u8I++)
	{
		MUART_vTransmit(A_u8String[L_u8I]);

	}

}
void MUART_vSendNumber(s32 A_s32Number)
{
	u8 L_u8Digits[10]={0};
	u8 L_u8counter = 0;
	while(A_s32Number >0)
	{
		L_u8Digits[L_u8counter]=A_s32Number%10;
		L_u8counter++;
		A_s32Number/=10 ;
	}
	for(s8 L_s8loop=L_u8counter-1;L_s8loop>=0;L_s8loop--)
		MUART_vTransmit('0'+L_u8Digits[L_s8loop]);


}


