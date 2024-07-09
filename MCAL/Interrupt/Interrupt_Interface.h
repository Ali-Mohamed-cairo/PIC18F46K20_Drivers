/* 
 * File:   Interrupt_Interface.h
 * Author: Ali Mohamed
 *
 * Created on March 6, 2024, 12:46 PM
 */

#ifndef INTERRUPT_INTERFACE_H
#define	INTERRUPT_INTERFACE_H

#include "../../BIT_MATH.h"
#include "../../Platform_Types.h"
#include "../DIO/DIO_Interface.h"
#include "Interrupt_Config.h"
#include "Interrupt_Private.h"


/*The registers INTCON, INTCON2 and INTCON3 are the registers which control the 
 * operation of EXT interrupt, IOCB interrupt and TMR0 interrupt
 */


/*EXTERNAL INTERRUPT REQUIRED*/
typedef enum{
    EXTINT0= 0,/*Pin RB0(Pin 0 port B). It has no priority bit because it always has high priority.*/
    EXTINT1,   /*Pin RB1(Pin 1 port B)*/
    EXTINT2    /*Pin RB2(Pin 2 port B)*/
}EXINT_t;
    
typedef enum{
    FALLING_EDGE = 0,
    RISING_EDGE
}EXTINT_EDGESELECT_t;

typedef struct{
    EXINT_t INTNum;/*Use EXINT_t enum*/
    uint8 TriggerEdge;/*Use the EXTINT_EDGESELECT_t enum*/
    uint8 PriorityLevel;/*The available priority levels are present down in the Needed Macros section*/
}EXTINT_Config_t; 



/*INTERRUPT ON CHANGE REQUIRED*/
typedef enum{
    IOC_RB4 = 4,
    IOC_RB5,
    IOC_RB6,
    IOC_RB7
}IOCB_t;

typedef struct{
    IOCB_t IOCBNum;/*Use IOCB_t enum*/
    uint8 PullUp_Status;/*PULL_UP_NOT_REQUIRED or PULL_UP_REQUIRED*/
    uint8 PriorityLevel;/*The available priority levels are present down in the Needed Macros section*/
}IOCB_Config_t; 


/*******************************Needed Macros**********************************/
      /*Never change this Macros or the driver will operate improperly*/
/*******************************Needed Macros**********************************/

/*Interrupt status*/
#define INT_DISABLE            0
#define INT_ENABLE             1


/*<Priority level>*/
/*We have only two priority levels:
 * 1-High.
 * 2-LOw
 * You can also disable the priority by configuring the comp. mode
 */
#define PRIORITY_NONE         -1
#define PRIORITY_LOW           0
#define PRIORITY_HIGH          1

/*Pull-Up status for IOCB*/
#define PULL_UP_NOT_REQUIRED   0
#define PULL_UP_REQUIRED       1


/*TMR0 INT MACROS*/
#define TMR0IE_INT            05/*This macro is sent to MCAL_Interrupt_IntState API to enable/disable TMR0*/
#define TMR0IP_INT            02/*This macro is sent to MCAL_Interrupt_SetIntPriority API to set TMR0 priority*/
#define TMR0IF_INT            02/*This macro is sent to MCAL_Interrupt_ReadIntFlag or MCAL_Interrupt_ClearIntFlag APIs for TMR0 flag*/


/*REST INTERRUPTS*/
/* The registers PIEx, PIRx and IPRx are the registers which control the 
 * operation of all rest interrupts other than EXT interrupt, IOCB interrupt 
 * and TMR0 interrupt, such that:
 * PIEx : Enable bits are there.
 * PIRx : Flag bits are there.
 * IPRx : Priority bits are there. 
 */
/*For each interrupt there is a corresponding index. Its meaning is:
 * If tenth is 'x' this means that its proper enable/flag/priority register is PIEx/PIRx/IPRx
 * If unit is 'n' then the proper bit for this interrupt in PIEx/PIRx/IPRx is the n'th bit 
 */
/*Don't change this #define statements or the driver will operate improperly*/
#define TMR1I_INT         10
#define TMR2I_INT         11
#define CCP1I_INT         12
#define SSPI_INT          13
#define TXI_INT           14
#define RCI_INT           15
#define ADI_INT           16
#define PSPI_INT          17
#define CCP2I_INT         20
#define TMR3I_INT         21
#define HLVDI_INT         22
#define BCLI_INT          23
#define EEI_INT           24
#define C2I_INT           25
#define C1I_INT           26
#define OSCFI_INT         27


/*
 * We will make separate APIs for the EXTInt and others for the IOCB, while the rest of interrupts
 * are controlled using common APIs 
 */
/***********************************APIs***************************************/
Std_ReturnType MCAL_Interrupt_GlobalIntEnable();/*This API is common for all interrupts. Disable or Enable all interrupts globally*/

/*********************************EXTt Interrupts APIs*************************/
/*To configure any pin of the RB<2:0> as EXTINT pin:
 * 1- Create an object of the struct EXTINT_Config_t.
 * 2- Use the MCAL_Interrupt_EXTIntStatus API to set the needed pin as input and configure it as you stated in the object. 
 * 3- Set the priority of EXTINTx(Use MCAL_Interrupt_SetEXTIntPriority).
 */
Std_ReturnType MCAL_Interrupt_EXTIntStatus(const EXTINT_Config_t Copy_EXTInt, const uint8 Copy_EXTIntStatus);/*Disable or Enable EXT INT*/
Std_ReturnType MCAL_Interrupt_SetEXTIntPriority(const EXTINT_Config_t Copy_EXTInt);
Std_ReturnType MCAL_Interrupt_ReadEXTIntFlag(const EXTINT_Config_t Copy_EXTInt, uint8 *Copy_FlagValue);
Std_ReturnType MCAL_Interrupt_ClearEXTIntFlag(const EXTINT_Config_t Copy_EXTInt);
/*SetCallBack APIs for EXTINTx */
Std_ReturnType MCAL_Interrupt_SetEXTINT0CallBack(void (*Copy_CallBackPtr)(void));
Std_ReturnType MCAL_Interrupt_SetEXTINT1CallBack(void (*Copy_CallBackPtr)(void));
Std_ReturnType MCAL_Interrupt_SetEXTINT2CallBack(void (*Copy_CallBackPtr)(void));

/************************INT On Change Interrupts APIs*************************/
/*To configure any pin of the RB<7:4> as IOC pin:
 * 1- Set this pin as input(Use the DIO APIs to do that).
 * 2- Set the RBIE bit in the INTCON register(Use MCAL_Interrupt_IOCBInit function). 
 * 3- Set the corresponding IOCB bit in the IOCB register and the internal pull-up 
 *    resistance -if required-(Use MCAL_Interrupt_IOCBPinStatus).
 *    Note: To enable the pull-up resistance you must basically have enabled it 
 *    globally by using MCAL_DIO_PORTBWeakPullUpsInitStatus API.
 * 4- Set the priority of IOCB(Use MCAL_Interrupt_SetIOCBIntPriority).
 */
Std_ReturnType MCAL_Interrupt_IOCBInit();/*Disable or Enable IOCB INT*/
Std_ReturnType MCAL_Interrupt_IOCBPinStatus(const IOCB_Config_t Copy_IOCBInt, const uint8 Copy_IOCBIntStatus);/*Disable or Enable IOCB INT for certain pin*/
Std_ReturnType MCAL_Interrupt_SetIOCBIntPriority(const IOCB_Config_t Copy_IOCBInt);
Std_ReturnType MCAL_Interrupt_ReadIOCBIntFlag(uint8 *Copy_FlagValue);
Std_ReturnType MCAL_Interrupt_ClearIOCBIntFlag();
/*SetCallBack APIs for IOCB */
Std_ReturnType MCAL_Interrrupt_SetIOCBCallBack(void (*Copy_CallBack)(void));

/*********************************Rest Interrupts APIs*************************/
Std_ReturnType MCAL_Interrupt_IntState(uint8 Copy_INT, const uint8 Copy_INTState);/*Disable or Enable given INT*/
Std_ReturnType MCAL_Interrupt_SetIntPriority(uint8 Copy_INT, const uint8 Copy_INTPriority);
Std_ReturnType MCAL_Interrupt_ReadIntFlag(uint8 Copy_INT, uint8 *Copy_FlagValue);
Std_ReturnType MCAL_Interrupt_ClearIntFlag(uint8 Copy_INT);
/*SetCallBack APIs for rest of the interrupt sources*/
Std_ReturnType MCAL_Interrupt_SetCallBack_TMR0(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_TMR1(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_TMR2(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_CCP1(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_SSP(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_TX(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_RC(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_AD(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_PSP(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_CCP2(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_TMR3(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_HLVD(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_BCL(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_EE(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_C2(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_C1(void (*Copy_CallBack)(void));
Std_ReturnType MCAL_Interrupt_SetCallBack_OSCF(void (*Copy_CallBack)(void));



#endif	/* INTERRUPT_INTERFACE_H */

