/* 
 * File:   Interrupt_Config.h
 * Author: Ali Mohamed
 *
 * Created on March 6, 2024, 12:47 PM
 */

#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H

#include "Interrupt_Private.h"


#define INT_COMPATABILITY_MODE                  0
#define INT_COMPATABILITY_WITHOUT_PERIPH_MODE   1
#define INT_PRIORITY_MODE                       2
#define INT_PRIORITY_WITHOUT_LOW_MODE           3



#define INTERRUPT_MODE   INT_COMPATABILITY_MODE
/*Choose on of the modes: 1- INT_COMPATABILITY_MODE
 *                        2-INT_COMPATABILITY_WITHOUT_PERIPH_MODE
 *                        3- INT_PRIORITY_MODE
 *                        4-INT_PRIORITY_WITHOUT_LOW_MODE
 */

/*<In case of the using INT_PRIORITY_MODE or INT_PRIORITY_WITHOUT_LOW_MODE use the following 
 * macros to set the low and high priority sources.
 * Warning: Don't use the same macro in both low and high priority.
 * Interrupt sources :
 *  1 - EXTINT1_P
 *  2 - EXTINT2_P
 *  3 - IOCB_P
 *  4 - TMR0_P
 *  5 - TMR1_P
 *  6 - TMR2_P
 *  7 - CCP1_P
 *  8 - SSP_P
 *  9 - TX_P
 * 10 - RC_P
 * 11 - PSP_P
 * 12 - CCP2_P
 * 13 - TMR3_P
 * 14 - HLVD_P
 * 15 - BCL_P
 * 16 - EE_P
 * 17 - C2_P
 * 18 - C1_P
 * 19 - OSCF_P
 * >*/

/*Low priority macros*/
#define LOW_PRIO_1st     EXTINT1_P
#define LOW_PRIO_2nd     IOCB_P
#define LOW_PRIO_3rd     TMR0_P
#define LOW_PRIO_4th     CCP1_P
#define LOW_PRIO_5th     RC_P
#define LOW_PRIO_6th     PSP_P
#define LOW_PRIO_7th     TMR3_P
#define LOW_PRIO_8th     NOTHING
#define LOW_PRIO_9th     NOTHING
#define LOW_PRIO_10th    NOTHING
#define LOW_PRIO_11th    NOTHING
#define LOW_PRIO_12th    NOTHING
#define LOW_PRIO_13th    NOTHING
#define LOW_PRIO_14th    NOTHING
#define LOW_PRIO_15th    NOTHING
#define LOW_PRIO_16th    NOTHING
#define LOW_PRIO_17th    NOTHING
#define LOW_PRIO_18th    NOTHING
#define LOW_PRIO_19th    NOTHING






/*High priority macros*/
#define HIGH_PRIO_1st     EXTINT2_P
#define HIGH_PRIO_2nd     TMR1_P
#define HIGH_PRIO_3rd     TMR2_P
#define HIGH_PRIO_4th     SSP_P
#define HIGH_PRIO_5th     TX_P
#define HIGH_PRIO_6th     CCP2_P
#define HIGH_PRIO_7th     NOTHING
#define HIGH_PRIO_8th     NOTHING
#define HIGH_PRIO_9th     NOTHING
#define HIGH_PRIO_10th    NOTHING
#define HIGH_PRIO_11th    NOTHING
#define HIGH_PRIO_12th    NOTHING
#define HIGH_PRIO_13th    NOTHING
#define HIGH_PRIO_14th    NOTHING
#define HIGH_PRIO_15th    NOTHING
#define HIGH_PRIO_16th    NOTHING
#define HIGH_PRIO_17th    NOTHING
#define HIGH_PRIO_18th    NOTHING
#define HIGH_PRIO_19th    NOTHING



#endif	/* INTERRUPT_CONFIG_H */

