/*
 * UART_cfg.h
 *
 *  Created on: Sep 10, 2023
 *      Author: userH
 */

#ifndef MCAL_UART_UART_CFG_H_
#define MCAL_UART_UART_CFG_H_
/*UART ISR ENABLE*/
/*
 * 1-ENABLE
 * 2-DISABLE
 * */

#define UART_ISR_EN         DISABLE
#define TX_COMPLETE_ISR_EN  DISABLE
#define RX_COMPLETE_ISR_EN  DISABLE
#define UDR_EMPTY_ISR_EN    DISABLE

#
/******************************************************/

/*UART TX AND RX ENABLE*/
/*
 * 1-ENABLE
 * 2-DISABLE
 * */
#define UART_TX_EN      ENABLE
#define UART_RX_EN      ENABLE

/*UART DATA SIZE*/
/*
 * 1-CHAR_SIZE_5
 * 2-CHAR_SIZE_6
 * 3-CHAR_SIZE_7
 * 4-CHAR_SIZE_8
 * */
#define UART_DATA_SIZE     CHAR_SIZE_8
/***********************************************************************************/
/* STOP_BIT_NUM*/
/*
 * 1-ONE_BIT
 * 2-TOW_BIT
 * */
#define STOP_BIT_NUM    ONE_BIT
/********************************************************************************/

/* UART MODE*/
/* 1-UART_SYN
 * 2-UART_ASYN
 * */
#define UART_MODE      UART_ASYN
/*********************************************************************************/

/*UART Parity Mode*/
/*
 * 1-PARITY_DISABLE
 * 1-PARITY_EVEN_MODE
 * 1-PARITY_ODD_MODE
 * */

#define UART_PARITY_MODE    PARITY_DISABLE
/***********************************************************************************/

/*CLOCK POLARITY*/
/*
 * 1-TXflaing_RXrising
 * 2-RXflaing_TXrising
 * */

#define UART_CLK_POLARITY   TXflaing_RXrising

#define UART_UBRR_VALUE  UART_UBRR
#endif /* MCAL_UART_UART_CFG_H_ */
