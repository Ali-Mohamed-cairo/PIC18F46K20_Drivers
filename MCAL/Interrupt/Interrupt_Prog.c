#include <pic18f46k20.h>
#include <stdlib.h>

#include "Interrupt_Interface.h"

void (*EXTINT0_CallBack)(void) = NULL_PTR;
void (*EXTINT1_CallBack)(void) = NULL_PTR;
void (*EXTINT2_CallBack)(void) = NULL_PTR;
void (*IOCB_CallBack)(void)    = NULL_PTR;
void (*TMR0_CallBack)(void)    = NULL_PTR;
void (*TMR1_CallBack)(void)    = NULL_PTR;
void (*TMR2_CallBack)(void)    = NULL_PTR;
void (*CCP1_CallBack)(void)    = NULL_PTR;
void (*SSP_CallBack)(void)     = NULL_PTR;
void (*TX_CallBack)(void)      = NULL_PTR;
void (*RC_CallBack)(void)      = NULL_PTR;
void (*AD_CallBack)(void)      = NULL_PTR;
void (*PSP_CallBack)(void)     = NULL_PTR;
void (*CCP2_CallBack)(void)    = NULL_PTR;
void (*TMR3_CallBack)(void)    = NULL_PTR;
void (*HLVD_CallBack)(void)    = NULL_PTR;
void (*BCL_CallBack)(void)     = NULL_PTR;
void (*EE_CallBack)(void)      = NULL_PTR;
void (*C2_CallBack)(void)      = NULL_PTR;
void (*C1_CallBack)(void)      = NULL_PTR;
void (*OSCF_CallBack)(void)    = NULL_PTR;






Std_ReturnType MCAL_Interrupt_GlobalIntEnable()
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
#if(INTERRUPT_MODE == INT_COMPATABILITY_MODE)
    RCON_REG.IPEN_BIT7   = CLEAR;
    INTCON_REG.GIE_BIT7  = SET;
    INTCON_REG.PEIE_BIT6 = SET;
    Local_ErrorStatus = E_OK;
#elif(INTERRUPT_MODE == INT_COMPATABILITY_WITHOUT_PERIPH_MODE)
    RCON_REG.IPEN_BIT7   = CLEAR;
    INTCON_REG.GIE_BIT7  = SET;
    INTCON_REG.PEIE_BIT6 = CLEAR;
    Local_ErrorStatus = E_OK;
#elif(INTERRUPT_MODE == INT_PRIORITY_MODE)
    RCON_REG.IPEN_BIT7   = SET;
    INTCON_REG.GIEH_BIT7 = SET;
    INTCON_REG.GIEL_BIT6 = SET;
    Local_ErrorStatus = E_OK;
#elif(INTERRUPT_MODE == INT_PRIORITY_WITHOUT_LOW_MODE)
    RCON_REG.IPEN_BIT7   = SET;
    INTCON_REG.GIEH_BIT7 = SET;
    INTCON_REG.GIEL_BIT6 = CLEAR;
    Local_ErrorStatus = E_OK;
#endif /*INTT*/
    return Local_ErrorStatus;
}


/*********************************EXT Interrupts APIs*************************/
/*To configure any pin of the RB<2:0> as EXTINT pin:
 * 1- Create an object of the struct EXTINT_Config_t.
 * 2- Use the MCAL_Interrupt_EXTIntStatus API to set the needed pin as input and configure it as you stated in the object. 
 * 3- Set the priority of EXTINTx(Use MCAL_Interrupt_SetEXTIntPriority).
 */
Std_ReturnType MCAL_Interrupt_EXTIntStatus(const EXTINT_Config_t Copy_EXTInt, const uint8 Copy_EXTIntStatus)/*Set the pin direction. Then Disable or Enable EXT INT and set the triggering edge*/
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    switch(Copy_EXTInt.INTNum)
    {
        case EXTINT0:
            if(Copy_EXTIntStatus == INT_DISABLE)
            {
                INTCON_REG.INT0IE_BIT4   = Copy_EXTIntStatus;
                Local_ErrorStatus = E_OK; 
            }
            else
            {
                Pin_Conig_t INT0 = {
                .PORT_ID = PORTB,
                .Pin_Num = DIO_PIN0,
                .Pin_Direction = DIO_PIN_INPUT
                };
                if(MCAL_DIO_SetPinDirection(&INT0))
                {
                    INTCON_REG.INT0IE_BIT4   = Copy_EXTIntStatus;
                    INTCON2_REG.INTEDG0_BIT6 = Copy_EXTInt.TriggerEdge;
                    Local_ErrorStatus = E_OK;   
                }
            }
            break;
        case EXTINT1:
            if(Copy_EXTIntStatus == INT_DISABLE)
            {
                INTCON3_REG.INT1IE_BIT3  = Copy_EXTIntStatus;
                Local_ErrorStatus = E_OK; 
            }
            else
            {
                Pin_Conig_t INT1 = {
                   .PORT_ID = PORTB,
                   .Pin_Num = DIO_PIN1,
                   .Pin_Direction = DIO_PIN_INPUT
               };
               if(MCAL_DIO_SetPinDirection(&INT1))
               {
                   INTCON3_REG.INT1IE_BIT3  = Copy_EXTIntStatus;
                   INTCON2_REG.INTEDG1_BIT5 = Copy_EXTInt.TriggerEdge;
                   Local_ErrorStatus = E_OK;
               }
            }
            break;
        case EXTINT2:
            if(Copy_EXTIntStatus == INT_DISABLE)
            {
                INTCON3_REG.INT2IE_BIT4  = Copy_EXTIntStatus;    
                Local_ErrorStatus = E_OK; 
            }
            else
            {
                Pin_Conig_t INT2 = {
                .PORT_ID = PORTB,
                .Pin_Num = DIO_PIN2,
                .Pin_Direction = DIO_PIN_INPUT
                };
                if(MCAL_DIO_SetPinDirection(&INT2))
                {
                    INTCON3_REG.INT2IE_BIT4  = Copy_EXTIntStatus;
                    INTCON2_REG.INTEDG2_BIT4 = Copy_EXTInt.TriggerEdge;
                    Local_ErrorStatus = E_OK;
                }   
            }
            break;
        default:
            Local_ErrorStatus = E_NOT_OK;
            break;
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_SetEXTIntPriority(const EXTINT_Config_t Copy_EXTInt)
{ 
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    if((INTERRUPT_MODE == INT_COMPATABILITY_MODE) || (INTERRUPT_MODE == INT_COMPATABILITY_WITHOUT_PERIPH_MODE))
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_EXTInt.INTNum)
        {
            case EXTINT0:
                //Do nothing bec. INT0 has fixed high priority.
                Local_ErrorStatus = E_NOT_OK;
                break;
            case EXTINT1:
                INTCON3_REG.INT1IP_BIT6 = Copy_EXTInt.PriorityLevel;
                Local_ErrorStatus = E_OK;
                break;
            case EXTINT2:
                INTCON3_REG.INT2IP_BIT7 = Copy_EXTInt.PriorityLevel;
                Local_ErrorStatus = E_OK;
                break;
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_ClearEXTIntFlag(const EXTINT_Config_t Copy_EXTInt)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    switch(Copy_EXTInt.INTNum)
    {
        case EXTINT0:
            INTCON_REG.INT0IF_BIT1 = CLEAR;
            Local_ErrorStatus = E_OK;
            break;
        case EXTINT1:
            INTCON3_REG.INT1IF_BIT0 = CLEAR;
            Local_ErrorStatus = E_OK;
            break;
        case EXTINT2:
            INTCON3_REG.INT2IF_BIT1 = CLEAR;
            Local_ErrorStatus = E_OK;
            break;
        default:
            Local_ErrorStatus = E_NOT_OK;
            break;
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_ReadEXTIntFlag(const EXTINT_Config_t Copy_EXTInt, uint8 *Copy_FlagValue)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    switch(Copy_EXTInt.INTNum)
    {
        case EXTINT0:
            *Copy_FlagValue = GET_BIT(INTCON_REG.INTCON_Register, _1st_BIT);
            Local_ErrorStatus = E_OK;
            break;
        case EXTINT1:
            *Copy_FlagValue = GET_BIT(INTCON3_REG.INTCON3_Register, _0TH_BIT);   
            Local_ErrorStatus = E_OK;
            break;
        case EXTINT2:
            *Copy_FlagValue = GET_BIT(INTCON3_REG.INTCON3_Register, _1st_BIT);
            Local_ErrorStatus = E_OK;
            break;
        default:
            Local_ErrorStatus = E_NOT_OK;
            break;
    }
    return Local_ErrorStatus;
}

/*SetCallBack APIs for EXTINTx */

Std_ReturnType MCAL_Interrupt_SetEXTINT0CallBack(void (*Copy_CallBackPtr)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    EXTINT0_CallBack = Copy_CallBackPtr;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_SetEXTINT1CallBack(void (*Copy_CallBackPtr)(void))
{
   Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    EXTINT1_CallBack = Copy_CallBackPtr;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_SetEXTINT2CallBack(void (*Copy_CallBackPtr)(void))
{
   Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    EXTINT2_CallBack = Copy_CallBackPtr;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}


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
Std_ReturnType MCAL_Interrupt_IOCBInit()/*Enable IOCB INT globally*/
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    INTCON_REG.RBIE_BIT3 = SET;
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_IOCBPinStatus(const IOCB_Config_t Copy_IOCBInt, const uint8 Copy_IOCBIntStatus)/*Disable or Enable IOCB INT for certain pin*/
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    if(Copy_IOCBInt.IOCBNum < IOC_RB4 || Copy_IOCBInt.IOCBNum > IOC_RB7)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        if(Copy_IOCBIntStatus == INT_ENABLE)
        {
            SET_BIT(IOCB_REG, Copy_IOCBInt.IOCBNum);
            if(Copy_IOCBInt.PullUp_Status == PULL_UP_REQUIRED)
                MCAL_DIO_PORTBEnablePinPullUp(Copy_IOCBInt.IOCBNum);
            Local_ErrorStatus = E_OK;
        }
        else if(Copy_IOCBIntStatus == INT_DISABLE)
        {
            CLEAR_BIT(IOCB_REG, Copy_IOCBInt.IOCBNum);
            Local_ErrorStatus = E_OK;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_SetIOCBIntPriority(const IOCB_Config_t Copy_IOCBInt)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    if((INTERRUPT_MODE == INT_COMPATABILITY_MODE) || (INTERRUPT_MODE == INT_COMPATABILITY_WITHOUT_PERIPH_MODE))
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        INTCON2_REG.RBIP_BIT0 = Copy_IOCBInt.PriorityLevel;
        Local_ErrorStatus = E_OK;
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_ReadIOCBIntFlag(uint8 *Copy_FlagValue)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    *Copy_FlagValue = INTCON_REG.RBIF_BIT0;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_ClearIOCBIntFlag()
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    INTCON_REG.RBIF_BIT0 = CLEAR;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

/*SetCallBack APIs for IOCB */

Std_ReturnType MCAL_Interrrupt_SetIOCBCallBack(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    IOCB_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

/*********************************Rest Interrupts APIs*************************/

Std_ReturnType MCAL_Interrupt_IntState(uint8 Copy_INT, const uint8 Copy_INTStatus)/*Disable or Enable given INT*/
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    uint8 Local_BitNum = Copy_INT % 10;
    Copy_INT /= 10;
    uint8 Local_EnableRegisterNum = Copy_INT;
    switch(Local_EnableRegisterNum)
    {
        case INTCON_M:
            if(Copy_INTStatus == INT_DISABLE)
            {
                CLEAR_BIT(INTCON_REG.INTCON_Register, Local_BitNum);
                Local_ErrorStatus = E_OK;
            }
            else if(Copy_INTStatus == INT_ENABLE)
            {
                SET_BIT(INTCON_REG.INTCON_Register, Local_BitNum);
                Local_ErrorStatus = E_OK;
            }
            break;
        case PIE1_M:
            if(Copy_INTStatus == INT_DISABLE)
            {
                CLEAR_BIT(PIE1_REG.PIE1_Register, Local_BitNum);
                Local_ErrorStatus = E_OK;
            }
            else if(Copy_INTStatus == INT_ENABLE)
            {
                SET_BIT(PIE1_REG.PIE1_Register, Local_BitNum);
                Local_ErrorStatus = E_OK;
            }
            break;
        case PIE2_M:
            if(Copy_INTStatus == INT_DISABLE)
            {
                CLEAR_BIT(PIE2_REG.PIE2_Register, Local_BitNum);
                Local_ErrorStatus = E_OK;
            }
            else if(Copy_INTStatus == INT_ENABLE)
            {
                SET_BIT(PIE2_REG.PIE2_Register, Local_BitNum);
                Local_ErrorStatus = E_OK;
            }
            break;
        default:
            Local_ErrorStatus = E_NOT_OK;
            break;
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_SetIntPriority(uint8 Copy_INT, const uint8 Copy_INTPriority)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    if((INTERRUPT_MODE == INT_COMPATABILITY_MODE) || (INTERRUPT_MODE == INT_COMPATABILITY_WITHOUT_PERIPH_MODE))
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        uint8 Local_BitNum = Copy_INT % 10;
        Copy_INT /= 10;
        uint8 Local_PriorityRegisterNum = Copy_INT;
        switch(Local_PriorityRegisterNum)
        {
            case INTCON2_M:
                if(Copy_INTPriority == PRIORITY_LOW)
                {
                    CLEAR_BIT(INTCON2_REG.INTCON2_Register, Local_BitNum);
                    Local_ErrorStatus = E_OK;
                }
                else if(Copy_INTPriority == PRIORITY_HIGH)
                {
                    SET_BIT(INTCON2_REG.INTCON2_Register, Local_BitNum);
                    Local_ErrorStatus = E_OK;
                }
                break;
            case IPR1_M:
                if(Copy_INTPriority == PRIORITY_LOW)
                {
                    CLEAR_BIT(IPR1_REG.IPR1_Register, Local_BitNum);
                    Local_ErrorStatus = E_OK;
                }
                else if(Copy_INTPriority == PRIORITY_HIGH)
                {
                    SET_BIT(IPR1_REG.IPR1_Register, Local_BitNum);
                    Local_ErrorStatus = E_OK;
                }
                break;
            case IPR2_M:
                if(Copy_INTPriority == PRIORITY_LOW)
                {
                    CLEAR_BIT(IPR2_REG.IPR2_Register, Local_BitNum);
                    Local_ErrorStatus = E_OK;
                }
                else if(Copy_INTPriority == PRIORITY_HIGH)
                {
                    SET_BIT(IPR2_REG.IPR2_Register, Local_BitNum);
                    Local_ErrorStatus = E_OK;
                }
                break;
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_ReadIntFlag(uint8 Copy_INT, uint8 *Copy_FlagValue)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    uint8 Local_BitNum = Copy_INT % 10;
    Copy_INT /= 10;
    uint8 Local_FlagRegisterNum = Copy_INT;
    switch(Local_FlagRegisterNum)
    {
        case INTCON_M:
            *Copy_FlagValue = GET_BIT(INTCON_REG.INTCON_Register, Local_BitNum);
            Local_ErrorStatus = E_OK;
            break;
        case PIR1_M:
            *Copy_FlagValue = GET_BIT(PIR1_REG.PIR1_Register, Local_BitNum);
            Local_ErrorStatus = E_OK;
            break;
        case PIR2_M:
            *Copy_FlagValue = GET_BIT(PIR2_REG.PIR2_Register, Local_BitNum);
            Local_ErrorStatus = E_OK;
            break;
        default:
            Local_ErrorStatus = E_NOT_OK;
            break;
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_Interrupt_ClearIntFlag(uint8 Copy_INT)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    uint8 Local_BitNum = Copy_INT % 10;
    Copy_INT /= 10;
    uint8 Local_FlagRegisterNum = Copy_INT;
    switch(Local_FlagRegisterNum)
    {
        case INTCON_M:
            CLEAR_BIT(INTCON_REG.INTCON_Register, Local_BitNum);
            Local_ErrorStatus = E_OK;
            break;
        case PIR1_M:
            CLEAR_BIT(PIR1_REG.PIR1_Register, Local_BitNum);
            Local_ErrorStatus = E_OK;
            break;
        case PIR2_M:
            CLEAR_BIT(PIR2_REG.PIR2_Register, Local_BitNum);
            Local_ErrorStatus = E_OK;
            break;
        default:
            Local_ErrorStatus = E_NOT_OK;
            break;
    }
    return Local_ErrorStatus;
}

/*SetCallBack APIs for rest of the interrupt sources*/

Std_ReturnType MCAL_Interrupt_SetCallBack_TMR0(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TMR0_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_TMR1(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TMR1_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_TMR2(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TMR2_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_CCP1(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    CCP1_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_SSP(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    SSP_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_TX(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TX_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_RC(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    RC_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_AD(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    AD_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_PSP(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    PSP_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_CCP2(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    CCP2_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}


Std_ReturnType MCAL_Interrupt_SetCallBack_TMR3(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TMR3_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_HLVD(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    HLVD_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_BCL(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    BCL_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_EE(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    EE_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_C2(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    C2_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_C1(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    C1_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_Interrupt_SetCallBack_OSCF(void (*Copy_CallBack)(void))
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    OSCF_CallBack = Copy_CallBack;
    Local_ErrorStatus = E_OK;
    return Local_ErrorStatus;
}


/************************************ISRs**************************************/

#if((INTERRUPT_MODE == INT_COMPATABILITY_MODE) || (INTERRUPT_MODE == INT_COMPATABILITY_WITHOUT_PERIPH_MODE))
    void __interrupt() ISR()
    {
        if(INTCON_REG.INT0IF_BIT1)
        {
           EXTINT0_CallBack();
           INTCON_REG.INT0IF_BIT1 = CLEAR; //Clear the flag bit after the ISR ends.
        }
        EXTINT1_P
        EXTINT2_P
        IOCB_P
        TMR0_P
        TMR1_P
        TMR2_P
        CCP1_P
        SSP_P
        TX_P
        RC_P
        PSP_P
        CCP2_P
        TMR3_P
        HLVD_P
        BCL_P
        EE_P
        C2_P
        C1_P
        OSCF_P
    }
    
#elif((INTERRUPT_MODE == INT_PRIORITY_MODE) || (INTERRUPT_MODE == INT_PRIORITY_WITHOUT_LOW_MODE))
    //Low priority ISR
    void __interrupt(low_priority) ISR()
    {
        LOW_PRIO_1st 
        LOW_PRIO_2nd
        LOW_PRIO_3rd
        LOW_PRIO_4th
        LOW_PRIO_5th
        LOW_PRIO_6th
        LOW_PRIO_7th
        LOW_PRIO_8th
        LOW_PRIO_9th
        LOW_PRIO_10th
        LOW_PRIO_11th
        LOW_PRIO_12th
        LOW_PRIO_13th
        LOW_PRIO_14th
        LOW_PRIO_15th
        LOW_PRIO_16th
        LOW_PRIO_18th
        LOW_PRIO_19th
    }
    
    //High priority ISR
    void __interrupt(high_priority) ISR()
    {
        //Because the EXTINT0 has fixed high priority so that we won't treat it as other interrupts 
        if(INTCON_REG.INT0IF_BIT1)
        {
           EXTINT0_CallBack();
           INTCON_REG.INT0IF_BIT1 = CLEAR; //Clear the flag bit after the ISR ends.
        }  
        HIGH_PRIO_1st
        HIGH_PRIO_2nd
        HIGH_PRIO_3rd
        HIGH_PRIO_4th
        HIGH_PRIO_5th
        HIGH_PRIO_6th
        HIGH_PRIO_7th
        HIGH_PRIO_8th
        HIGH_PRIO_9th
        HIGH_PRIO_10th
        HIGH_PRIO_11th
        HIGH_PRIO_12th
        HIGH_PRIO_13th
        HIGH_PRIO_14th
        HIGH_PRIO_15th
        HIGH_PRIO_16th
        HIGH_PRIO_18th        
        HIGH_PRIO_19th
    }
    
#endif // INTERRUPT_MODE