/* 
 * File:   DIO_Interface.h
 * Author: Ali Mohamed
 *
 * Created on March 1, 2024, 6:25 PM
 */

#include <xc.h>


#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "Device_Config.h"

#include "O:\Embeded_systems_courses\AbdAlGhafar_Diploma\PICDrivers\MCAL\DIO\DIO_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/Push_Button/Push_Button_Interface.h"
#include "HAL/KeyPad/KeyPad_Interface.h"


KeyPad_t key = {
    .KeyPad_Rows_Pins[0].Pin_Num = DIO_PIN0,
    .KeyPad_Rows_Pins[0].PORT_ID = DIO_PORTB,
    
    .KeyPad_Rows_Pins[1].Pin_Num = DIO_PIN1,
    .KeyPad_Rows_Pins[1].PORT_ID = DIO_PORTB,

    .KeyPad_Rows_Pins[2].Pin_Num = DIO_PIN2,
    .KeyPad_Rows_Pins[2].PORT_ID = DIO_PORTB,

    .KeyPad_Rows_Pins[3].Pin_Num = DIO_PIN3,
    .KeyPad_Rows_Pins[3].PORT_ID = DIO_PORTB,

    .KeyPad_Cols_Pins[0].Pin_Num = DIO_PIN4,
    .KeyPad_Cols_Pins[0].PORT_ID = DIO_PORTB,
    
    .KeyPad_Cols_Pins[1].Pin_Num = DIO_PIN5,
    .KeyPad_Cols_Pins[1].PORT_ID = DIO_PORTB,
    
    .KeyPad_Cols_Pins[2].Pin_Num = DIO_PIN6,
    .KeyPad_Cols_Pins[2].PORT_ID = DIO_PORTB,
    
    .KeyPad_Cols_Pins[3].Pin_Num = DIO_PIN7,
    .KeyPad_Cols_Pins[3].PORT_ID = DIO_PORTB
};


#define _XTAL_FREQ 16000000

LED_t led1 = {
.PORT_ID = LED_PORTC,
.Pin_Num = LED_PIN0,
.LED_Status = LED_OFF
};

PushBtn_t Btn = {
.PORT_ID = Btn_PORTD,
.Pin_Num = Btn_PIN0,
.Connection_Meth = PULL_DOWN_Connection,
.Last_Status = Btn_D_Released
};


uint8 Global_BtnRead = E_OK;
Std_ReturnType ReturnStatus = E_NOT_OK;

int main()
{
    HAL_LED_LEDConfig(&led1);
    HAL_Push_Button_BtnConfig(&Btn);
    
    /*1 -  ReturnStatus = MCAL_DIO_SetPinDirection(&Btn_1);
    ReturnStatus = MCAL_DIO_InitializePinOutput(&LED_1);
    ReturnStatus = MCAL_DIO_InitializePinOutput(&LED_2);
    ReturnStatus = MCAL_DIO_InitializePinOutput(&LED_3);  */
    
    /*2 -  ReturnStatus = MCAL_DIO_SetPortDirection(&portd);
    ReturnStatus = MCAL_DIO_SetPortDirection(&portc);
    ReturnStatus = MCAL_DIO_SetPortValue(&portc, portc.Port_Value);*/
   
    
    while(1)
    {
        HAL_Push_Button_ReadBtn(&Btn, &Global_BtnRead);
        if(Global_BtnRead == Btn_D_Pressed)
        {
            HAL_LED_LEDBlink(&led1);
        }
        
        /*2 -  while(Global_BtnRead == 0x00)
        {
            ReturnStatus = MCAL_DIO_ReadPortValue(&portd, &Global_BtnRead);
        }
        Global_BtnRead = E_OK;
        ReturnStatus = MCAL_DIO_TogglePortValue(&portc);*/
        
        /*1 -  while(Global_BtnRead == E_OK)
        {
            ReturnStatus = MCAL_DIO_ReadPinValue(&Btn_1, &Global_BtnRead);
        }
        Global_BtnRead = E_OK;
        ReturnStatus = MCAL_DIO_SetPinValue(&LED_1, DIO_HIGH);
        while(Global_BtnRead == E_OK)
        {
            ReturnStatus = MCAL_DIO_ReadPinValue(&Btn_1, &Global_BtnRead);
        }       
        Global_BtnRead = E_OK;
        ReturnStatus = MCAL_DIO_SetPinValue(&LED_2, DIO_HIGH);
        while(Global_BtnRead == E_OK)
        {
            ReturnStatus = MCAL_DIO_ReadPinValue(&Btn_1, &Global_BtnRead);
        }       
        Global_BtnRead = E_OK;
        ReturnStatus = MCAL_DIO_SetPinValue(&LED_3, DIO_HIGH);
        while(Global_BtnRead == E_OK)
        {
            ReturnStatus = MCAL_DIO_ReadPinValue(&Btn_1, &Global_BtnRead);
        }       
        Global_BtnRead = E_OK;
        ReturnStatus = MCAL_DIO_SetPinValue(&LED_1, DIO_LOW);
        ReturnStatus = MCAL_DIO_SetPinValue(&LED_2, DIO_LOW);
        ReturnStatus = MCAL_DIO_SetPinValue(&LED_3, DIO_LOW);*/   
    }
    
    return 0;
}
