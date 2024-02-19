/*
 * STM-int.h
 *
 *  Created on: Jul 22, 2023
 *      Author: userH
 */

#ifndef HAL_STEPER_MOTOR_STM_INT_H_
#define HAL_STEPER_MOTOR_STM_INT_H_

u8 L_u8Steps[]={9,1,3,2,6,4,12,8};

#define STPR_PORT DIO_PORTA
#define STPR_PORT_DIR 0x0f
#define STPR_STEP_ANGEL 2.8125
#define STPR_STEP_NUM   8

void HSTPR_vInit();
void HSTPR_vRotateCW(u16 A_u8Angle);
void HSTPR_vRotateCCW(u16 A_u8Angle);

void HSTPR_vRotateStepsCW(u16 A_u8Steps);
void HSTPR_vRotateStepsCCW(u16 A_u8Steps);


#endif /* HAL_STEPER_MOTOR_STM_INT_H_ */
