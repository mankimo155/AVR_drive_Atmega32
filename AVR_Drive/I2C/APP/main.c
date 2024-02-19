/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: userH
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/I2C/I2C_int.h"
#include <util/delay.h>


void EEPROM_vWriteByte(u8 A_u8Byte, u16 A_u16Address)
{
	MI2C_u8SendStartCondition();
	MI2C_u8SendSlaveAddressRW(0b1010000,I2C_WRITE);
	MI2C_u8SendByte((u8)A_u16Address);
	MI2C_u8SendByte(A_u8Byte);
	MI2C_u8SendStoptCondition();
}
u8  EEPROM_vReadByte(u16 A_u16Adderss)
{
	u8 L_u8Byte = 0 ;
	MI2C_u8SendStartCondition();
	MI2C_u8SendSlaveAddressRW(0b1010000,I2C_WRITE);
	MI2C_u8SendByte((u8)A_u16Adderss);
	MI2C_u8SendStartCondition();
	MI2C_u8SendSlaveAddressRW(0b1010000,I2C_READ);
	MI2C_u8ReceiveByte(&L_u8Byte,I2C_NOT_ACK);
	MI2C_u8SendStoptCondition();
	return L_u8Byte;
}

int main(void)
{

	u8 c = 0 ;
	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

	MI2C_u8Init();
	EEPROM_vWriteByte('M',5);
	_delay_ms(10);
	c = EEPROM_vReadByte(5);
	if(c == 'M')
	{
		MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
	}
	else
	{
		MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);

	}

	while(1)
	{



	}

}
