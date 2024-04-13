# 1 "MCAL/DIO/DIO_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "P:/Programs_installed/Microchip/MPLABX/v5.45/packs/Microchip/PIC18F-K_DFP/1.4.87/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "MCAL/DIO/DIO_Prog.c" 2







# 1 "MCAL/DIO/../../BIT_MATH.h" 1
# 12 "MCAL/DIO/../../BIT_MATH.h"
# 1 "./Platform_Types.h" 1
# 21 "./Platform_Types.h"
typedef unsigned char uint8;

typedef signed char sint8;

typedef uint8 Std_ReturnType;
# 66 "./Platform_Types.h"
    typedef unsigned int uint16;
    typedef unsigned long uint32;

    typedef signed int sint16;
    typedef signed long sint32;
# 91 "./Platform_Types.h"
    typedef float float24;
    typedef double float32;
# 12 "MCAL/DIO/../../BIT_MATH.h" 2
# 8 "MCAL/DIO/DIO_Prog.c" 2

# 1 "MCAL/DIO/DIO_Config.h" 1
# 9 "MCAL/DIO/DIO_Prog.c" 2

# 1 "MCAL/DIO/DIO_Private.h" 1
# 17 "MCAL/DIO/DIO_Private.h"
typedef union {
    struct{
        uint8 TRISA_BIT0 : 1;
        uint8 TRISA_BIT1 : 1;
        uint8 TRISA_BIT2 : 1;
        uint8 TRISA_BIT3 : 1;
        uint8 TRISA_BIT4 : 1;
        uint8 TRISA_BIT5 : 1;
        uint8 TRISA_BIT6 : 1;
        uint8 TRISA_BIT7 : 1;
    };
    uint8 TRISA_REGISTER;
}TRISA_t;





typedef union {
    struct{
        uint8 LATA_BIT0 : 1;
        uint8 LATA_BIT1 : 1;
        uint8 LATA_BIT2 : 1;
        uint8 LATA_BIT3 : 1;
        uint8 LATA_BIT4 : 1;
        uint8 LATA_BIT5 : 1;
        uint8 LATA_BIT6 : 1;
        uint8 LATA_BIT7 : 1;
    };
    uint8 LATA_REGISTER;
}LATA_t;





typedef union {
    struct{
        uint8 PORTA_BIT0 : 1;
        uint8 PORTA_BIT1 : 1;
        uint8 PORTA_BIT2 : 1;
        uint8 PORTA_BIT3 : 1;
        uint8 PORTA_BIT4 : 1;
        uint8 PORTA_BIT5 : 1;
        uint8 PORTA_BIT6 : 1;
        uint8 PORTA_BIT7 : 1;
    };
    uint8 PORTA_REGISTER;
}PORTA_t;
# 74 "MCAL/DIO/DIO_Private.h"
typedef union {
    struct{
        uint8 TRISB_BIT0 : 1;
        uint8 TRISB_BIT1 : 1;
        uint8 TRISB_BIT2 : 1;
        uint8 TRISB_BIT3 : 1;
        uint8 TRISB_BIT4 : 1;
        uint8 TRISB_BIT5 : 1;
        uint8 TRISB_BIT6 : 1;
        uint8 TRISB_BIT7 : 1;
    };
    uint8 TRISB_REGISTER;
}TRISB_t;





typedef union {
    struct{
        uint8 LATB_BIT0 : 1;
        uint8 LATB_BIT1 : 1;
        uint8 LATB_BIT2 : 1;
        uint8 LATB_BIT3 : 1;
        uint8 LATB_BIT4 : 1;
        uint8 LATB_BIT5 : 1;
        uint8 LATB_BIT6 : 1;
        uint8 LATB_BIT7 : 1;
    };
    uint8 LATB_REGISTER;
}LATB_t;





typedef union {
    struct{
        uint8 PORTB_BIT0 : 1;
        uint8 PORTB_BIT1 : 1;
        uint8 PORTB_BIT2 : 1;
        uint8 PORTB_BIT3 : 1;
        uint8 PORTB_BIT4 : 1;
        uint8 PORTB_BIT5 : 1;
        uint8 PORTB_BIT6 : 1;
        uint8 PORTB_BIT7 : 1;
    };
    uint8 PORTB_REGISTER;
}PORTB_t;







typedef union {
    struct{
        uint8 TRISC_BIT0 : 1;
        uint8 TRISC_BIT1 : 1;
        uint8 TRISC_BIT2 : 1;
        uint8 TRISC_BIT3 : 1;
        uint8 TRISC_BIT4 : 1;
        uint8 TRISC_BIT5 : 1;
        uint8 TRISC_BIT6 : 1;
        uint8 TRISC_BIT7 : 1;
    };
    uint8 TRISC_REGISTER;
}TRISC_t;





typedef union {
    struct{
        uint8 LATC_BIT0 : 1;
        uint8 LATC_BIT1 : 1;
        uint8 LATC_BIT2 : 1;
        uint8 LATC_BIT3 : 1;
        uint8 LATC_BIT4 : 1;
        uint8 LATC_BIT5 : 1;
        uint8 LATC_BIT6 : 1;
        uint8 LATC_BIT7 : 1;
    };
    uint8 LATC_REGISTER;
}LATC_t;





typedef union {
    struct{
        uint8 PORTC_BIT0 : 1;
        uint8 PORTC_BIT1 : 1;
        uint8 PORTC_BIT2 : 1;
        uint8 PORTC_BIT3 : 1;
        uint8 PORTC_BIT4 : 1;
        uint8 PORTC_BIT5 : 1;
        uint8 PORTC_BIT6 : 1;
        uint8 PORTC_BIT7 : 1;
    };
    uint8 PORTC_REGISTER;
}PORTC_t;







typedef union {
    struct{
        uint8 TRISD_BIT0 : 1;
        uint8 TRISD_BIT1 : 1;
        uint8 TRISD_BIT2 : 1;
        uint8 TRISD_BIT3 : 1;
        uint8 TRISD_BIT4 : 1;
        uint8 TRISD_BIT5 : 1;
        uint8 TRISD_BIT6 : 1;
        uint8 TRISD_BIT7 : 1;
    };
    uint8 TRISD_REGISTER;
}TRISD_t;





typedef union {
    struct{
        uint8 LATD_BIT0 : 1;
        uint8 LATD_BIT1 : 1;
        uint8 LATD_BIT2 : 1;
        uint8 LATD_BIT3 : 1;
        uint8 LATD_BIT4 : 1;
        uint8 LATD_BIT5 : 1;
        uint8 LATD_BIT6 : 1;
        uint8 LATD_BIT7 : 1;
    };
    uint8 LATD_REGISTER;
}LATD_t;





typedef union {
    struct{
        uint8 PORTD_BIT0 : 1;
        uint8 PORTD_BIT1 : 1;
        uint8 PORTD_BIT2 : 1;
        uint8 PORTD_BIT3 : 1;
        uint8 PORTD_BIT4 : 1;
        uint8 PORTD_BIT5 : 1;
        uint8 PORTD_BIT6 : 1;
        uint8 PORTD_BIT7 : 1;
    };
    uint8 PORTD_REGISTER;
}PORTD_t;







typedef union {
    struct{
        uint8 TRISE_BIT0 : 1;
        uint8 TRISE_BIT1 : 1;
        uint8 TRISE_BIT2 : 1;
        uint8 RESERVEE_BIT3 : 1;
        uint8 TRISE_BIT4 : 1;
        uint8 TRISE_BIT5 : 1;
        uint8 TRISE_BIT6 : 1;
        uint8 TRISE_BIT7 : 1;
    };
    struct{
        uint8 TRISE_BITS : 3;
        uint8 RESERVEE_BIT : 1;
        uint8 PSPMODE_BIT4 : 1;
        uint8 IBOV_BIT5 : 1;
        uint8 OBF_BIT6 : 1;
        uint8 IBF_BIT7 : 1;
    };
    uint8 TRISE_REGISTER;
}TRISE_t;





typedef union {
    struct{
        uint8 LATE_BIT0 : 1;
        uint8 LATE_BIT1 : 1;
        uint8 LATE_BIT2 : 1;
        uint8 RESERVED_BITS : 5;
    };
    uint8 LATE_REGISTER : 3;
}LATE_t;





typedef union {
    struct{
        uint8 PORTE_BIT0 : 1;
        uint8 PORTE_BIT1 : 1;
        uint8 PORTE_BIT2 : 1;
        uint8 PORTE_BIT3 : 1;
        uint8 RESERVED_BITS : 4;
    };
    uint8 PORTE_REGISTER : 4;
}PORTE_t;
# 10 "MCAL/DIO/DIO_Prog.c" 2

# 1 "MCAL/DIO/DIO_Interface.h" 1
# 22 "MCAL/DIO/DIO_Interface.h"
typedef enum{
    DIO_PIN0 = 0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
}DIO_PIN_t;

typedef enum{
    DIO_PORTA = 0,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD,
    DIO_PORTE
}DIO_PORT_t;

typedef enum{
    DIO_PIN_OUTPUT = 0,
    DIO_PIN_INPUT
}DIO_PIN_DIRECTION_t;

typedef enum{
    DIO_LOW = 0,
    DIO_HIGH
}DIO_PIN_VALUE_t;







typedef struct{
    uint8 PORT_ID : 3;
    uint8 Pin_Num : 3;
    uint8 Pin_Direction : 1;
    uint8 Pin_Value : 1;
}Pin_Conig_t;

typedef struct{
    uint8 PORT_ID : 3;
    uint8 Port_Value;
    uint8 Port_Direction;



}Port_Conig_t;



Std_ReturnType MCAL_DIO_SetPinDirection(const Pin_Conig_t *Copy_PinInfo);
Std_ReturnType MCAL_DIO_GetPinDirection(const Pin_Conig_t *Copy_PinInfo, DIO_PIN_DIRECTION_t *Copy_Direction);
Std_ReturnType MCAL_DIO_SetPinValue( Pin_Conig_t *Copy_PinInfo, DIO_PIN_VALUE_t Copy_PinValue);
Std_ReturnType MCAL_DIO_ReadPinValue(const Pin_Conig_t *Copy_PinInfo, DIO_PIN_VALUE_t *Copy_PinValue);
Std_ReturnType MCAL_DIO_TogglePinValue(Pin_Conig_t *Copy_PinInfo);
Std_ReturnType MCAL_DIO_InitializePinOutput(const Pin_Conig_t *Copy_PinInfo);

Std_ReturnType MCAL_DIO_SetPortDirection(const Port_Conig_t *Copy_PortInfo);
Std_ReturnType MCAL_DIO_GetPortDirection(const Port_Conig_t *Copy_PortInfo, uint8 *Copy_Direction);
Std_ReturnType MCAL_DIO_SetPortValue(Port_Conig_t *Copy_PortInfo, const uint8 Copy_PortValue);
Std_ReturnType MCAL_DIO_ReadPortValue(const Port_Conig_t *Copy_PortInfo, uint8 *Copy_PortValue);
Std_ReturnType MCAL_DIO_TogglePortValue(Port_Conig_t *Copy_PortInfo);
# 11 "MCAL/DIO/DIO_Prog.c" 2





Std_ReturnType MCAL_DIO_SetPinDirection(const Pin_Conig_t *Copy_PinInfo)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        ((*((volatile TRISA_t *)0xF92)).TRISA_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        break;
                    case DIO_PIN_OUTPUT:
                        ((*((volatile TRISA_t *)0xF92)).TRISA_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTB:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        ((*((volatile TRISB_t *)0xF93)).TRISB_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        break;
                    case DIO_PIN_OUTPUT:
                        ((*((volatile TRISB_t *)0xF93)).TRISB_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTC:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        ((*((volatile TRISC_t *)0xF94)).TRISC_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        break;
                    case DIO_PIN_OUTPUT:
                        ((*((volatile TRISC_t *)0xF94)).TRISC_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTD:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        ((*((volatile TRISD_t *)0xF95)).TRISD_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        break;
                    case DIO_PIN_OUTPUT:
                        ((*((volatile TRISD_t *)0xF95)).TRISD_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTE:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                    break;
                }
                switch(Copy_PinInfo->Pin_Direction)
                {
                    case DIO_PIN_INPUT:
                        ((*((volatile TRISE_t *)0xF96)).TRISE_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        break;
                    case DIO_PIN_OUTPUT:
                        ((*((volatile TRISE_t *)0xF96)).TRISE_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_DIO_GetPinDirection(const Pin_Conig_t *Copy_PinInfo, DIO_PIN_DIRECTION_t *Copy_Direction)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    uint8 Local_PinDirection = 6;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
         switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                Local_PinDirection = (((*((volatile TRISA_t *)0xF92)).TRISA_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTB:
                Local_PinDirection = (((*((volatile TRISB_t *)0xF93)).TRISB_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTC:
                Local_PinDirection = (((*((volatile TRISC_t *)0xF94)).TRISC_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTD:
                Local_PinDirection = (((*((volatile TRISD_t *)0xF95)).TRISD_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTE:
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                    break;
                }
                Local_PinDirection = (((*((volatile TRISE_t *)0xF96)).TRISE_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinDirection == DIO_PIN_INPUT || Local_PinDirection == DIO_PIN_OUTPUT)
                {
                    *Copy_Direction = Local_PinDirection;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_SetPinValue(Pin_Conig_t *Copy_PinInfo, DIO_PIN_VALUE_t Copy_PinValue)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_INPUT)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        ((*((volatile LATA_t *)0xF89)).LATA_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        ((*((volatile LATA_t *)0xF89)).LATA_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTB:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        ((*((volatile LATB_t *)0xF8A)).LATB_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        ((*((volatile LATB_t *)0xF8A)).LATB_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTC:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        ((*((volatile LATC_t *)0xF8B)).LATC_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        ((*((volatile LATC_t *)0xF8B)).LATC_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTD:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        ((*((volatile LATD_t *)0xF8C)).LATD_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        ((*((volatile LATD_t *)0xF8C)).LATD_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            case DIO_PORTE:
                Local_ErrorStatus = (Std_ReturnType)0x01;
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                    break;
                }
                switch(Copy_PinValue)
                {
                    case DIO_HIGH:
                        ((*((volatile LATE_t *)0xF8D)).LATE_REGISTER |= (1 << Copy_PinInfo->Pin_Num));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    case DIO_LOW:
                        ((*((volatile LATE_t *)0xF8D)).LATE_REGISTER &= (~(1 << Copy_PinInfo->Pin_Num)));
                        Copy_PinInfo->Pin_Value = Copy_PinValue;
                        break;
                    default:
                        Local_ErrorStatus = (Std_ReturnType)0x00;
                        break;
                }
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_ReadPinValue(const Pin_Conig_t *Copy_PinInfo, DIO_PIN_VALUE_t *Copy_PinValue)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    uint8 Local_PinValue = 6;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_OUTPUT)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                Local_PinValue = (((*((volatile PORTA_t *)0xF80)).PORTA_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                   Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTB:
                Local_PinValue = (((*((volatile PORTB_t *)0xF81)).PORTB_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                   Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTC:
                Local_PinValue = (((*((volatile PORTC_t *)0xF82)).PORTC_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                   Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTD:
                Local_PinValue = (((*((volatile PORTD_t *)0xF83)).PORTD_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                   Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            case DIO_PORTE:
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                    break;
                }
                Local_PinValue = (((*((volatile PORTE_t *)0xF84)).PORTE_REGISTER >> Copy_PinInfo->Pin_Num) & 1);
                if(Local_PinValue == DIO_HIGH || Local_PinValue == DIO_LOW)
                {
                    *Copy_PinValue = Local_PinValue;
                    Local_ErrorStatus = (Std_ReturnType)0x01;
                }
                else
                {
                   Local_ErrorStatus = (Std_ReturnType)0x00;
                }
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_TogglePinValue(Pin_Conig_t *Copy_PinInfo)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_INPUT)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        switch(Copy_PinInfo->PORT_ID)
        {
            case DIO_PORTA:
                ((*((volatile LATA_t *)0xF89)).LATA_REGISTER ^= (1 << Copy_PinInfo->Pin_Num));
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTB:
                ((*((volatile LATB_t *)0xF8A)).LATB_REGISTER ^= (1 << Copy_PinInfo->Pin_Num));
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTC:
                ((*((volatile LATC_t *)0xF8B)).LATC_REGISTER ^= (1 << Copy_PinInfo->Pin_Num));
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTD:
                ((*((volatile LATD_t *)0xF8C)).LATD_REGISTER ^= (1 << Copy_PinInfo->Pin_Num));
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTE:
                if(Copy_PinInfo->Pin_Num > DIO_PIN2)
                {
                    Local_ErrorStatus = (Std_ReturnType)0x00;
                    break;
                }
                ((*((volatile LATE_t *)0xF8D)).LATE_REGISTER ^= (1 << Copy_PinInfo->Pin_Num));
                Copy_PinInfo->Pin_Value = ~(Copy_PinInfo->Pin_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }
    return Local_ErrorStatus;
}

Std_ReturnType MCAL_DIO_InitializePinOutput(const Pin_Conig_t *Copy_PinInfo)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PinInfo->Pin_Num > DIO_PIN7 || Copy_PinInfo->Pin_Direction == DIO_PIN_INPUT)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        MCAL_DIO_SetPinDirection(Copy_PinInfo);
        MCAL_DIO_SetPinValue(Copy_PinInfo, DIO_LOW);
    }
    return Local_ErrorStatus;
}







Std_ReturnType MCAL_DIO_SetPortDirection(const Port_Conig_t *Copy_PortInfo)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
       switch(Copy_PortInfo->PORT_ID)
       {
           case DIO_PORTA:
               (*((volatile TRISA_t *)0xF92)).TRISA_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTB:
               (*((volatile TRISB_t *)0xF93)).TRISB_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTC:
               (*((volatile TRISC_t *)0xF94)).TRISC_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTD:
               (*((volatile TRISD_t *)0xF95)).TRISD_REGISTER = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTE:
               (*((volatile TRISE_t *)0xF96)).TRISE_BITS = Copy_PortInfo->Port_Direction;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           default:
               Local_ErrorStatus = (Std_ReturnType)0x00;
               break;
       }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_GetPortDirection(const Port_Conig_t *Copy_PortInfo, uint8 *Copy_Direction)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        switch(Copy_PortInfo->PORT_ID)
        {
            case DIO_PORTA:
                *Copy_Direction = (*((volatile TRISA_t *)0xF92)).TRISA_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTB:
                *Copy_Direction = (*((volatile TRISB_t *)0xF93)).TRISB_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTC:
                *Copy_Direction = (*((volatile TRISC_t *)0xF94)).TRISC_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTD:
                *Copy_Direction = (*((volatile TRISD_t *)0xF95)).TRISD_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTE:
                *Copy_Direction = (*((volatile TRISE_t *)0xF96)).TRISE_BITS;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_SetPortValue(Port_Conig_t *Copy_PortInfo, const uint8 Copy_PortValue)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
       switch(Copy_PortInfo->PORT_ID)
       {
           case DIO_PORTA:
               (*((volatile LATA_t *)0xF89)).LATA_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTB:
               (*((volatile LATB_t *)0xF8A)).LATB_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTC:
               (*((volatile LATC_t *)0xF8B)).LATC_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTD:
               (*((volatile LATD_t *)0xF8C)).LATD_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           case DIO_PORTE:
               (*((volatile LATE_t *)0xF8D)).LATE_REGISTER = Copy_PortValue;
               Copy_PortInfo->Port_Value = Copy_PortValue;
               Local_ErrorStatus = (Std_ReturnType)0x01;
               break;
           default:
               Local_ErrorStatus = (Std_ReturnType)0x00;
               break;
       }
    }
    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_ReadPortValue(const Port_Conig_t *Copy_PortInfo, uint8 *Copy_PortValue)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        switch(Copy_PortInfo->PORT_ID)
        {
            case DIO_PORTA:
                *Copy_PortValue = (*((volatile PORTA_t *)0xF80)).PORTA_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTB:
                *Copy_PortValue = (*((volatile PORTB_t *)0xF81)).PORTB_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTC:
                *Copy_PortValue = (*((volatile PORTC_t *)0xF82)).PORTC_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTD:
                *Copy_PortValue = (*((volatile PORTD_t *)0xF83)).PORTD_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTE:
                *Copy_PortValue = (*((volatile PORTE_t *)0xF84)).PORTE_REGISTER;
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }

    return Local_ErrorStatus;
}
Std_ReturnType MCAL_DIO_TogglePortValue(Port_Conig_t *Copy_PortInfo)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_PortInfo->PORT_ID > DIO_PORTE)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        switch(Copy_PortInfo->PORT_ID)
        {
            case DIO_PORTA:
                (*((volatile LATA_t *)0xF89)).LATA_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTB:
                (*((volatile LATB_t *)0xF8A)).LATB_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTC:
                (*((volatile LATC_t *)0xF8B)).LATC_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTD:
                (*((volatile LATD_t *)0xF8C)).LATD_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            case DIO_PORTE:
                (*((volatile LATE_t *)0xF8D)).LATE_REGISTER = ~(Copy_PortInfo->Port_Value);
                Copy_PortInfo->Port_Value = ~(Copy_PortInfo->Port_Value);
                Local_ErrorStatus = (Std_ReturnType)0x01;
                break;
            default:
                Local_ErrorStatus = (Std_ReturnType)0x00;
                break;
        }
    }
    return Local_ErrorStatus;
}
