/*
 * TIMER-cfg.h
 *
 *  Created on: Aug 3, 2023
 *      Author: userH
 */

#ifndef MCAL_TIMER_TIMER_CFG_H_
#define MCAL_TIMER_TIMER_CFG_H_

/* ---------- Timer 0 Configurations ----------- */

#define TIMER0_ENABLE		ENABLE

/**
 * Options:
 * TIMER_OVF
 * TIMER_CTC
 * TIMER_FASTPWM
 * TIMER_PHASECORRECT
 */
#define TIMER0_MODE   TIMER_FASTPWM

/*
 * Options:
 TIMER_NO_PS
 TIMER_PS_8
 TIMER_PS_64
 TIMER_PS_256
 TIMER_PS_1024
 TIMER_DISABLE
 * */
#define TIMER_PRESCALER	TIMER_PS_8

/*
 * Option :
 OC_DISABLE
 OC_TOGGLE
 OC_CLEAR
 OC_SET
 *
 * */
#define TIMER0_OC0_MODE  OC_CLEAR


/* ---------- Timer 1 Configurations ----------- */
#define u16TIMER1_ENABLE		ENABLE




/* ---------- Timer 2 Configurations ----------- */
#define TIMER2_ENABLE		DISABLE

/**
 * Options:
 * TIMER_OVF
 * TIMER_CTC
 * TIMER_FASTPWM
 * TIMER_PHASECORRECT
 */
#define TIMER2_MODE   TIMER_FASTPWM

/*
 * Option :
 OC_DISABLE
 OC_TOGGLE  only for CTC mode
 OC_CLEAR
 OC_SET
 *
 * */
#define TIMER2_OC2_MODE  OC_CLEAR



#endif /* MCAL_TIMER_TIMER_CFG_H_ */
