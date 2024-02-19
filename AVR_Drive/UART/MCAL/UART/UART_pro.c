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

static void (*GS_TXC_Callback)(void);
static void (*GS_RXC_Callback)(void);
static u8* GS_InternalTXBuffer;
static u8* GS_InternalRXBuffer;
static u16 GS_u16TXBufferCounter = 0 ;
static u16 GS_u16RXBufferCounter = 0 ;
static u32 GS_u32TXBufferSize=0 ;
static u32 GS_u32RXBufferSize=0 ;

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


u8 MUART_vRecieve(void)
{
	/* Wait for data to be received */
	while(!(UCSRA & (1<<RXC))){}

	/* Get and return received data from buffer */
	return UDR;

}


void MUART_vSendString(u8 A_u8String[])
{

	for(u32 L_u8I = 0 ; A_u8String[L_u8I] != '\0' ; L_u8I++)
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
void MUART_vReceiveString(u8 A_u8String[],u32 A_u32Size)
{

	for(u32 i = 0 ; i<A_u32Size; i++)
	{
		A_u8String[i]=MUART_vRecieve();
		if((A_u8String[i] == '\n') || (A_u8String[i] == '\r'))
		{
			A_u8String[i] = '\0' ;
			break;
		}
	}
	A_u8String[A_u32Size-1]='/0';
}


void MUART_vEnableINT(u8 A_u8INTsource)
{
	switch(A_u8INTsource)
	{
	case UART_TX_COPLETE:
		SET_BIT(UCSRB,TXCIE);
		break;
	case UART_RX_COPLETE:
		SET_BIT(UCSRB,RXCIE);
		break;
	case UART_UDR_EMPTY:
		SET_BIT(UCSRB,UDRIE);
		break;

	}

}
void MUART_vDisableINT(u8 A_u8INTsource)
{
	switch(A_u8INTsource)
	{
	case UART_TX_COPLETE:
		CLR_BIT(UCSRB,TXCIE);
		break;
	case UART_RX_COPLETE:
		CLR_BIT(UCSRB,RXCIE);
		break;
	case UART_UDR_EMPTY:
		CLR_BIT(UCSRB,UDRIE);
		break;

	}


}

void MUART_vTransmit_Asyn(char A_xstr[],u32 A_u16Size,void (*Fptr)(void))
{
	GS_TXC_Callback=Fptr;
	GS_InternalTXBuffer = A_xstr;
	GS_u32TXBufferSize=A_u16Size;
	MUART_vEnableINT(UART_TX_COPLETE);
	UDR = A_xstr[0];
	GS_u16TXBufferCounter++;


}
void MUART_vRecieve_Asyn(char A_xBuffer[],u32 A_u16Size,void (*Fptr)(void))
{
	GS_RXC_Callback = Fptr ;
	GS_InternalTXBuffer = A_xBuffer ;
	GS_u32RXBufferSize = A_u16Size ;

}


void __vector_15(void)  __attribute__((signal));
void __vector_15(void)
{

	if(GS_TXC_Callback !=NULL)
	{
		GS_TXC_Callback();
	}
	if(GS_u16TXBufferCounter < GS_u32TXBufferSize)
	{
		if(GS_InternalTXBuffer[GS_u16TXBufferCounter] != '\0')
		{
			UDR =GS_InternalTXBuffer[GS_u16TXBufferCounter];
			GS_u16TXBufferCounter++;

		}
		else
		{
			MUART_vDisableINT(UART_TX_COPLETE);
		}
	}
	else
	{
		GS_u16TXBufferCounter = 0 ;

	}

}

void __vector_13(void)  __attribute__((signal));
void __vector_13(void)
{
	if(GS_TXC_Callback !=NULL)
	{
		GS_RXC_Callback();
	}
	if(GS_u16RXBufferCounter < GS_u32RXBufferSize)
	{

		if((GS_InternalRXBuffer[GS_u16RXBufferCounter] != '\n') || (GS_InternalRXBuffer[GS_u16RXBufferCounter]  != '\r'))
		{
			GS_InternalRXBuffer[GS_u16RXBufferCounter] = UDR ;
			GS_u16RXBufferCounter++;
		}
		else
		{
			GS_InternalRXBuffer[GS_u16RXBufferCounter] ='\0';
		}
	}
	else
	{

		GS_u16RXBufferCounter = 0 ;

	}


}
