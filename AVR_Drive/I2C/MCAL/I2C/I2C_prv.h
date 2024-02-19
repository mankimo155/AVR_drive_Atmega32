/*
 * I2C_prv.h
 *
 *  Created on: Sep 16, 2023
 *      Author: userH
 */

#ifndef MCAL_I2C_I2C_PRV_H_
#define MCAL_I2C_I2C_PRV_H_

#define TWIE         0
#define TWINT        7
#define TWSTA        5
#define TWEN         2
#define TWSTO        4
#define TWEA         6

#define TWBR    *((volatile u8*)(0x20))
#define TWCR    *((volatile u8*)(0x56))
#define TWSR    *((volatile u8*)(0x21))
#define TWDR    *((volatile u8*)(0x23))
#define TWAR    *((volatile u8*)(0x22))



#endif /* MCAL_I2C_I2C_PRV_H_ */
