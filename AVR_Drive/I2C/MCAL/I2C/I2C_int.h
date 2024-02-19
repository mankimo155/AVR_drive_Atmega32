/*
 * I2C_int.h
 *
 *  Created on: Sep 16, 2023
 *      Author: userH
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

#define I2C_WRITE   0
#define I2C_READ    1

#define I2C_NOT_ACK   0
#define I2C_ACK       1

void MI2C_u8Init(void);

u8 MI2C_u8SendStartCondition(void);
u8 MI2C_u8SendRepeatedStartCondition(void);
u8 MI2C_u8SendSlaveAddressRW(u8 A_u8Sla, u8 A_u8RW);
u8 MI2C_u8SendByte(u8 A_u8Byte);
u8 MI2C_u8ReceiveByte(u8* A_pu8Byte,u8 A_u8Ack);
u8 MI2C_u8SendStoptCondition(void);
u8 MI2C_u8GetStatus(void);

void MI2C_vSetBitRate(u32 A_u32BitRate);
void MI2C_vSetSlaveAddress(u8 A_u8Ownsla);
#endif /* MCAL_I2C_I2C_INT_H_ */
