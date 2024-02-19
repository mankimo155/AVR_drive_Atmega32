/*
 * I2C_prg.c
 *
 *  Created on: Sep 16, 2023
 *      Author: userH
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "I2C_int.h"
#include "I2C_prv.h"
#include "I2C_cfg.h"



void MI2C_u8Init(void)
{
	/*interrupt enable/disable*/
	CLR_BIT(TWCR, TWIE);
	/*Bit Rate*/
	TWBR = 10 ;


}

u8 MI2C_u8SendStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while (!(TWCR & (1<<TWINT)));

	/*check status Reg*/
	return (TWSR & 0xF8);
}

u8 MI2C_u8SendRepeatedStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	/*check status Reg*/
	return (TWSR & 0xF8);

}

u8 MI2C_u8SendSlaveAddressRW(u8 A_u8Sla, u8 A_u8RW)
{
	TWDR = ((A_u8Sla << 1) | (A_u8RW));
	TWCR = (1<<TWINT) | (1<<TWEN);
	CLR_BIT(TWCR,TWSTA);
	while (!(TWCR & (1<<TWINT)));

	/*check status Reg*/
	return (TWSR & 0xF8);
}

u8 MI2C_u8SendByte(u8 A_u8Byte)
{
	TWDR = A_u8Byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

	/*check status Reg*/
	return (TWSR & 0xF8);

}

u8  MI2C_u8ReceiveByte(u8* A_pu8Byte,u8 A_u8Ack)
{
	switch(A_u8Ack)
	{
	case I2C_ACK :
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		break;
	case I2C_NOT_ACK :
		TWCR = (1<<TWINT) | (1<<TWEN);
		CLR_BIT(TWCR,TWEA);
		break;
	}
	while (!(TWCR & (1<<TWINT)));
	*A_pu8Byte = TWDR ;

	/*check status Reg*/
	return (TWSR & 0xF8);

}

u8 MI2C_u8SendStoptCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);


	/*check status Reg*/
	return (TWSR & 0xF8);
}

u8 MI2C_u8GetStatus(void)
{

	return (TWSR & 0xF8);
}
