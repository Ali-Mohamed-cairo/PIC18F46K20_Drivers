# 1 "HAL/Push_Button/Push_Button.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "P:/Programs_installed/Microchip/MPLABX/v5.45/packs/Microchip/PIC18F-K_DFP/1.4.87/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "HAL/Push_Button/Push_Button.c" 2
# 10 "HAL/Push_Button/Push_Button.c"
# 1 "HAL/Push_Button/Push_Button_Interface.h" 1
# 13 "HAL/Push_Button/Push_Button_Interface.h"
# 1 "HAL/Push_Button/../../Platform_Types.h" 1
# 21 "HAL/Push_Button/../../Platform_Types.h"
typedef unsigned char uint8;

typedef signed char sint8;

typedef uint8 Std_ReturnType;
# 66 "HAL/Push_Button/../../Platform_Types.h"
    typedef unsigned int uint16;
    typedef unsigned long uint32;

    typedef signed int sint16;
    typedef signed long sint32;
# 91 "HAL/Push_Button/../../Platform_Types.h"
    typedef float float24;
    typedef double float32;
# 13 "HAL/Push_Button/Push_Button_Interface.h" 2

# 1 "HAL/Push_Button/../../MCAL/DIO/DIO_Interface.h" 1
# 22 "HAL/Push_Button/../../MCAL/DIO/DIO_Interface.h"
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
# 14 "HAL/Push_Button/Push_Button_Interface.h" 2

# 1 "HAL/Push_Button/Push_Button_Config.h" 1
# 15 "HAL/Push_Button/Push_Button_Interface.h" 2
# 28 "HAL/Push_Button/Push_Button_Interface.h"
typedef enum{
    Btn_PIN0 = 0,
    Btn_PIN1,
    Btn_PIN2,
    Btn_PIN3,
    Btn_PIN4,
    Btn_PIN5,
    Btn_PIN6,
    Btn_PIN7
}PushBtnPIN_t;

typedef enum{
    Btn_PORTA = 0,
    Btn_PORTB,
    Btn_PORTC,
    Btn_PORTD,
    Btn_PORTE
}PushBtnPORT_t;

typedef enum{
    Btn_D_Released = 0,
    Btn_D_Pressed
}Btn_Pull_Down_Status;

typedef enum{
    Btn_U_Pressed = 0,
    Btn_U_Released
}Btn_Pull_Up_Status;



typedef struct{
    uint8 PORT_ID : 3;
    uint8 Pin_Num : 3;
    uint8 Connection_Meth : 1;
    uint8 Last_Status : 1;
}PushBtn_t;
# 76 "HAL/Push_Button/Push_Button_Interface.h"
Std_ReturnType HAL_Push_Button_BtnConfig(const PushBtn_t *Copy_Btn);
Std_ReturnType HAL_Push_Button_ReadBtn(PushBtn_t *Copy_Btn, uint8 *Copy_BtnStatus);
# 10 "HAL/Push_Button/Push_Button.c" 2




Std_ReturnType HAL_Push_Button_BtnConfig(const PushBtn_t *Copy_Btn)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    if(Copy_Btn->PORT_ID > Btn_PORTE || Copy_Btn->Pin_Num > Btn_PIN7)
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        Pin_Conig_t Btn = {
            .PORT_ID = Copy_Btn->PORT_ID,
            .Pin_Num = Copy_Btn->Pin_Num,
            .Pin_Direction = DIO_PIN_INPUT,
            .Pin_Value = Copy_Btn->Last_Status
        };
        if(!MCAL_DIO_SetPinDirection(&Btn))
        {
            Local_ErrorStatus = (Std_ReturnType)0x00;
        }
        else
        {
            Local_ErrorStatus = (Std_ReturnType)0x01;
        }
    }
    return Local_ErrorStatus;
}
Std_ReturnType HAL_Push_Button_ReadBtn(PushBtn_t *Copy_Btn, uint8 *Copy_BtnStatus)
{
    Std_ReturnType Local_ErrorStatus = (Std_ReturnType)0x00;
    uint8 Local_BtnStatus = Btn_D_Released;
    Pin_Conig_t Btn = {
            .PORT_ID = Copy_Btn->PORT_ID,
            .Pin_Num = Copy_Btn->Pin_Num,
            .Pin_Direction = DIO_PIN_INPUT,
            .Pin_Value = Copy_Btn->Last_Status
    };
    if(!MCAL_DIO_ReadPinValue(&Btn, &Local_BtnStatus))
    {
        Local_ErrorStatus = (Std_ReturnType)0x00;
    }
    else
    {
        if(Copy_Btn->Connection_Meth == 0)
        {
            if(Local_BtnStatus == Btn_D_Pressed)
            {
                while(Local_BtnStatus != Btn_D_Released)
                {
                    MCAL_DIO_ReadPinValue(&Btn, &Local_BtnStatus);
                }
                *Copy_BtnStatus = Btn_D_Pressed;
                Copy_Btn->Last_Status = Btn_D_Pressed;
            }
            else
            {
                *Copy_BtnStatus = Btn_D_Released;
                Copy_Btn->Last_Status = Btn_D_Released;
            }
        }
        else if(Copy_Btn->Connection_Meth == 1)
        {
            if(Local_BtnStatus == Btn_U_Pressed)
            {
                while(Local_BtnStatus != Btn_U_Released)
                {
                    MCAL_DIO_ReadPinValue(&Btn, &Local_BtnStatus);
                }
                *Copy_BtnStatus = Btn_U_Pressed;
                Copy_Btn->Last_Status = Btn_U_Pressed;
            }
            else
            {
                *Copy_BtnStatus = Btn_U_Released;
                Copy_Btn->Last_Status = Btn_U_Released;
            }
        }
        Local_ErrorStatus = (Std_ReturnType)0x01;
    }
    return Local_ErrorStatus;
}
