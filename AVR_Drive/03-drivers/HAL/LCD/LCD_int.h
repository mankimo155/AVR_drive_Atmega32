/*
 * LCD_int.h
 *
 *  Created on: Jul 15, 2023
 *      Author: userH
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_ControlPort DIO_PORTA;
#define LCD_DataPort    DIO_PORTD ;



void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Cmd);
void HLCD_vSendCher(u8 A_u8Char );
void HLCD_vPrintString(char A_s8Sstring[]);
void HLCD_vSendData(s8 A_s8Data);
void HLCD_VPrintNumber(s32  A_s32Number);


#endif /* HAL_LCD_LCD_INT_H_ */
