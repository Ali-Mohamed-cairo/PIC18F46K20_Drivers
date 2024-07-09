/* 
 * File:   DIO_Prog.c
 * Author: Ali Mohamed
 *
 * Created on March 1, 2024, 6:25 PM
*/
/*********************************Includes*************************************/
#include "../../BIT_MATH.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

/**********************************Pin APIs************************************/

#if(APIs_CONFIG == PIN_APIs_CONFIG || APIs_CONFIG == PORT_PIN_APIs_CONFIG)
Std_ReturnType MCAL_DIO_SetPinDirection(const Pin_Conig_t *Copy_PinInfo)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    if(Copy_PinInfo->Pin_Num > DIO_PIN7)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        SET_BIT(TRISA_REG.TRISA_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    case DIO_PIN_OUTPUT:
                        CLEAR_BIT(TRISA_REG.TRISA_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTB:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        SET_BIT(TRISB_REG.TRISB_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    case DIO_PIN_OUTPUT:
                        CLEAR_BIT(TRISB_REG.TRISB_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTC:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        SET_BIT(TRISC_REG.TRISC_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    case DIO_PIN_OUTPUT:
                        CLEAR_BIT(TRISC_REG.TRISC_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTD:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        SET_BIT(TRISD_REG.TRISD_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    case DIO_PIN_OUTPUT:
                        CLEAR_BIT(TRISD_REG.TRISD_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTE:
                Local_ErrorStatus = E_OK;
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = E_NOT_OK;
                    break;
                }
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        SET_BIT(TRISE_REG.TRISE_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    case DIO_PIN_OUTPUT:
                        CLEAR_BIT(TRISE_REG.TRISE_REGISTER, Copy_PinInfo->Pin_Num);
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;            
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_DIO_GetPinDirection(const Pin_Conig_t *Copy_PinInfo, DIO_PIN_DIRECTION_t *Copy_Direction)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    uint8 Local_PinDirection = INITIAL_VALUE;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
         switch(Copy_PinInfo->PORT_ID)
        {   
            case DIO_PORTA:
                Local_PinDirection = GET_BIT(TRISA_REG.TRISA_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                    Local_ErrorStatus = E_NOT_OK;   
                }
                break;
            case DIO_PORTB:
                Local_PinDirection = GET_BIT(TRISB_REG.TRISB_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                    Local_ErrorStatus = E_NOT_OK;   
                }
                break;
            case DIO_PORTC:
                Local_PinDirection = GET_BIT(TRISC_REG.TRISC_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                    Local_ErrorStatus = E_NOT_OK;   
                }
                break;
            case DIO_PORTD:
                Local_PinDirection = GET_BIT(TRISD_REG.TRISD_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                    Local_ErrorStatus = E_NOT_OK;   
                }
                break;
            case DIO_PORTE:
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = E_NOT_OK;
                    break;
                }
                Local_PinDirection = GET_BIT(TRISE_REG.TRISE_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                    Local_ErrorStatus = E_NOT_OK;   
                }
                break;          
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_SetPinValue(Pin_Conig_t *Copy_PinInfo, DIO_PIN_VALUE_t Copy_PinValue)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_INPUT)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        SET_BIT(LATA_REG.LATA_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        CLEAR_BIT(LATA_REG.LATA_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTB:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        SET_BIT(LATB_REG.LATB_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        CLEAR_BIT(LATB_REG.LATB_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTC:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        SET_BIT(LATC_REG.LATC_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        CLEAR_BIT(LATC_REG.LATC_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTD:
                Local_ErrorStatus = E_OK;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        SET_BIT(LATD_REG.LATD_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        CLEAR_BIT(LATD_REG.LATD_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;
            case DIO_PORTE:
                Local_ErrorStatus = E_OK;
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = E_NOT_OK;
                    break;
                }
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        SET_BIT(LATE_REG.LATE_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        CLEAR_BIT(LATE_REG.LATE_REGISTER, Copy_PinInfo->Pin_Num);
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = E_NOT_OK;
                        break;
                }
                break;            
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_ReadPinValue(const Pin_Conig_t *Copy_PinInfo, DIO_PIN_VALUE_t *Copy_PinValue)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    uint8 Local_PinValue = INITIAL_VALUE;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_OUTPUT)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                Local_PinValue = GET_BIT(PORTA_REG.PORTA_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                   Local_ErrorStatus = E_NOT_OK; 
                }
                break;
            case DIO_PORTB:
                Local_PinValue = GET_BIT(PORTB_REG.PORTB_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                   Local_ErrorStatus = E_NOT_OK; 
                }
                break;
            case DIO_PORTC:
                Local_PinValue = GET_BIT(PORTC_REG.PORTC_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                   Local_ErrorStatus = E_NOT_OK; 
                }
                break;
            case DIO_PORTD:
                Local_PinValue = GET_BIT(PORTD_REG.PORTD_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                   Local_ErrorStatus = E_NOT_OK; 
                }
                break;
            case DIO_PORTE:
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = E_NOT_OK;
                    break;
                }
                Local_PinValue = GET_BIT(PORTE_REG.PORTE_REGISTER, Copy_PinInfo->Pin_Num);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = E_OK;
                }
                else
                {
                   Local_ErrorStatus = E_NOT_OK; 
                }
                break;           
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }  
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_TogglePinValue(Pin_Conig_t *Copy_PinInfo)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_INPUT)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                TOGGLE_BIT(LATA_REG.LATA_REGISTER, Copy_PinInfo->Pin_Num);
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTB:
                TOGGLE_BIT(LATB_REG.LATB_REGISTER, Copy_PinInfo->Pin_Num);
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTC:         
                TOGGLE_BIT(LATC_REG.LATC_REGISTER, Copy_PinInfo->Pin_Num);
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTD:
                TOGGLE_BIT(LATD_REG.LATD_REGISTER, Copy_PinInfo->Pin_Num);
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTE:
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = E_NOT_OK;
                    break;
                }
                TOGGLE_BIT(LATE_REG.LATE_REGISTER, Copy_PinInfo->Pin_Num);
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = E_OK;
                break;           
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }  
    }
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_DIO_InitializePinOutput(const Pin_Conig_t *Copy_PinInfo)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_INPUT)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        MCAL_DIO_SetPinDirection(Copy_PinInfo);
        MCAL_DIO_SetPinValue(Copy_PinInfo, DIO_LOW);
    }
    return Local_ErrorStatus;
}


Std_ReturnType MCAL_DIO_PORTBWeakPullUpsInitStatus(uint8 Copy_PORTBPullUpStatus)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    //The RBPU bit is complemented which mean to set it we write 0 in it, and to clear we write 1 in it.
    if(Copy_PORTBPullUpStatus == PORTB_ENABLE_PULL_UP)
    {
        CLEAR_BIT(PORTB_INTCON2_REG, INTOCN2_RBPU_BIT7);
        Local_ErrorStatus = E_OK;
    }
    else if(Copy_PORTBPullUpStatus == PORTB_DISABLE_PULL_UP)
    {
        SET_BIT(PORTB_INTCON2_REG, INTOCN2_RBPU_BIT7);
        Local_ErrorStatus = E_OK;
    }
    else
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_DIO_PORTBEnablePinPullUp(DIO_PIN_t Copy_PinNum)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    SET_BIT(WPUB_REG, Copy_PinNum);
    return Local_ErrorStatus;
}

#endif /*APIs_CONFIG*/

/*********************************Port APIs************************************/

#if(APIs_CONFIG == PORT_APIs_CONFIG || APIs_CONFIG == PORT_PIN_APIs_CONFIG)

Std_ReturnType MCAL_DIO_SetPortDirection(const Port_Conig_t *Copy_PortInfo)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
       switch(Copy_PortInfo->PORT_ID)
       {
           case DIO_PORTA:
               TRISA_REG.TRISA_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTB:
               TRISB_REG.TRISB_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTC:
               TRISC_REG.TRISC_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTD:
               TRISD_REG.TRISD_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTE:
               TRISE_REG.TRISE_BITS = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = E_OK;
               break;            
           default:
               Local_ErrorStatus = E_NOT_OK;
               break;
       }   
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_GetPortDirection(const Port_Conig_t *Copy_PortInfo, uint8 *Copy_Direction)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_PortInfo->PORT_ID)
        {
            case DIO_PORTA:
                *Copy_Direction = TRISA_REG.TRISA_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTB:
                *Copy_Direction = TRISB_REG.TRISB_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTC:
                *Copy_Direction = TRISC_REG.TRISC_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTD:
                *Copy_Direction = TRISD_REG.TRISD_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTE:
                *Copy_Direction = TRISE_REG.TRISE_BITS;
                Local_ErrorStatus = E_OK;
                break;            
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_SetPortValue(Port_Conig_t *Copy_PortInfo, const uint8 Copy_PortValue)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
       switch(Copy_PortInfo->PORT_ID)
       {
           case DIO_PORTA:
               LATA_REG.LATA_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTB:
               LATB_REG.LATB_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTC:
               LATC_REG.LATC_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTD:
               LATD_REG.LATD_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = E_OK;
               break;
           case DIO_PORTE:
               LATE_REG.LATE_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = E_OK;
               break;            
           default:
               Local_ErrorStatus = E_NOT_OK;
               break;
       }   
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_ReadPortValue(const Port_Conig_t *Copy_PortInfo, uint8 *Copy_PortValue)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_PortInfo->PORT_ID)
        {
            case DIO_PORTA:
                *Copy_PortValue = PORTA_REG.PORTA_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTB:
                *Copy_PortValue = PORTB_REG.PORTB_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTC:
                *Copy_PortValue = PORTC_REG.PORTC_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTD:
                *Copy_PortValue = PORTD_REG.PORTD_REGISTER;
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTE:
                *Copy_PortValue = PORTE_REG.PORTE_REGISTER;
                Local_ErrorStatus = E_OK;
                break;            
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_TogglePortValue(Port_Conig_t *Copy_PortInfo)
{
    Std_ReturnType Local_ErrorStatus = E_NOT_OK; 
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = E_NOT_OK;
    }
    else
    {
        switch(Copy_PortInfo->PORT_ID)
        {
            case DIO_PORTA:
                LATA_REG.LATA_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTB:
                LATB_REG.LATB_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTC:
                LATC_REG.LATC_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTD:
                LATD_REG.LATD_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = E_OK;
                break;
            case DIO_PORTE:
                LATE_REG.LATE_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = E_OK;
                break;            
            default:
                Local_ErrorStatus = E_NOT_OK;
                break;
        }
    }
    return Local_ErrorStatus;
}
#endif /*APIs_CONFIG*/