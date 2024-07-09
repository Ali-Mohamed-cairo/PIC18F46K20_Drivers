/* 
 * File:   Interrupt_Private.h
 * Author: Ali Mohamed
 *
 * Created on March 6, 2024, 12:48 PM
 */

#ifndef INTERRUPT_PRIVATE_H
#define	INTERRUPT_PRIVATE_H

#include "../../BIT_MATH.h"

#include "Interrupt_Config.h"

/*********************************The Driver's Registers***********************/

#if(INTERRUPT_MODE == INT_COMPATABILITY_MODE || INTERRUPT_MODE == INT_COMPATABILITY_WITHOUT_PERIPH_MODE)
    typedef union{
        struct{
            uint8 RBIF_BIT0   : 1;
            uint8 INT0IF_BIT1 : 1;
            uint8 TMR0IF_BIT2 : 1;
            uint8 RBIE_BIT3   : 1;
            uint8 INT0IE_BIT4 : 1;
            uint8 TMR0IE_BIT5 : 1;
            uint8 PEIE_BIT6   : 1;
            uint8 GIE_BIT7    : 1;
        };
        uint8 INTCON_Register;
    }INTCON_REG_t;
#elif(INTERRUPT_MODE == INT_PRIORITY_MODE || INTERRUPT_MODE == INT_PRIORITY_WITHOUT_LOW_MODE)
    typedef union{
        struct{
            uint8 RBIF_BIT0   : 1;
            uint8 INT0IF_BIT1 : 1;
            uint8 TMR0IF_BIT2 : 1;
            uint8 RBIE_BIT3   : 1;
            uint8 INT0IE_BIT4 : 1;
            uint8 TMR0IE_BIT5 : 1;
            uint8 GIEL_BIT6   : 1;
            uint8 GIEH_BIT7   : 1;
        };
        uint8 INTCON_Register;
    }INTCON_REG_t;
#endif /*INTERRUPT_MODE*/

#define INTCON_REG  (*((volatile INTCON_REG_t *)0xFF2))
    
typedef union{
    struct{
        uint8 RBIP_BIT0     : 1;
        uint8 RESERVED_BIT1 : 1;
        uint8 TMR0IP_BIT2   : 1;
        uint8 RESERVED_BIT3 : 1;
        uint8 INTEDG2_BIT4  : 1;
        uint8 INTEDG1_BIT5  : 1;
        uint8 INTEDG0_BIT6  : 1;
        uint8 RBPU_BIT7     : 1; 
    };
    uint8 INTCON2_Register;
}INTCON2_REG_t;    

#define INTCON2_REG (*((volatile INTCON2_REG_t *)0xFF1))

typedef union{
    struct{
        uint8 INT1IF_BIT0   : 1;
        uint8 INT2IF_BIT1   : 1;
        uint8 RESERVED_BIT2 : 1;
        uint8 INT1IE_BIT3   : 1;
        uint8 INT2IE_BIT4   : 1;
        uint8 RESERVED_BIT5 : 1;
        uint8 INT1IP_BIT6   : 1;    
        uint8 INT2IP_BIT7   : 1;
    };
    uint8 INTCON3_Register;
}INTCON3_REG_t;

#define INTCON3_REG (*((volatile INTCON3_REG_t *)0xFF0))

typedef union{
    struct{
        uint8 TMR1IF_BIT0  : 1;
        uint8 TMR2IF_BIT1  : 1;
        uint8 CCP1IF_BIT2  : 1;
        uint8 SSPIF_BIT3   : 1;
        uint8 TXIF_BIT4    : 1;
        uint8 RCIF_BIT5    : 1;
        uint8 ADIF_BIT6    : 1;    
        uint8 PSPIF_BIT7   : 1;
    };
    uint8 PIR1_Register;
}PIR1_REG_t;

#define PIR1_REG (*((volatile PIR1_REG_t *)0xF9E))

typedef union{
    struct{
        uint8 CCP2IF_BIT0 : 1;
        uint8 TMR3IF_BIT1 : 1;
        uint8 HLVDIF_BIT2 : 1;
        uint8 BCLIF_BIT3  : 1;
        uint8 EEIF_BIT4   : 1;
        uint8 C2IF_BIT5   : 1;
        uint8 C1IF_BIT6   : 1;    
        uint8 OSCFIF_BIT7 : 1;
    };
    uint8 PIR2_Register;
}PIR2_REG_t;

#define PIR2_REG (*((volatile PIR2_REG_t *)0xFA1))


typedef union{
    struct{
        uint8 TMR1IE_BIT0 : 1;
        uint8 TMR2IE_BIT1 : 1;
        uint8 CCP1IE_BIT2 : 1;
        uint8 SSPIE_BIT3  : 1;
        uint8 TXIE_BIT4   : 1;
        uint8 RCIE_BIT5   : 1;
        uint8 ADIE_BIT6   : 1;    
        uint8 PSPIE_BIT7  : 1;
    };
    uint8 PIE1_Register;
}PIE1_REG_t;

#define PIE1_REG (*((volatile PIE1_REG_t *)0xF9D))


typedef union{
    struct{
        uint8 CCP2IE_BIT0 : 1;
        uint8 TMR3IE_BIT1 : 1;
        uint8 HLVDIE_BIT2 : 1;
        uint8 BCLIE_BIT3  : 1;
        uint8 EEIE_BIT4   : 1;
        uint8 C2IE_BIT5   : 1;
        uint8 C1IE_BIT6   : 1;    
        uint8 OSCFIE_BIT7 : 1;
    };
    uint8 PIE2_Register;
}PIE2_REG_t;

#define PIE2_REG (*((volatile PIE2_REG_t *)0xFA0))    


typedef union{
    struct{
        uint8 TMR1IP_BIT0 : 1;
        uint8 TMR2IP_BIT1 : 1;
        uint8 CCP1IP_BIT2 : 1;
        uint8 SSPIP_BIT3  : 1;
        uint8 TXIP_BIT4   : 1;
        uint8 RCIP_BIT5   : 1;
        uint8 ADIP_BIT6   : 1;    
        uint8 PSPIP_BIT7  : 1;
    };
    uint8 IPR1_Register;
}IPR1_REG_t;

#define IPR1_REG (*((volatile IPR1_REG_t *)0xF9F))
typedef union{
    struct{
        uint8 CCP2IP_BIT0 : 1;
        uint8 TMR3IP_BIT1 : 1;
        uint8 HLVDIP_BIT2 : 1;
        uint8 BCLIP_BIT3  : 1;
        uint8 EEIP_BIT4   : 1;
        uint8 C2IP_BIT5   : 1;
        uint8 C1IP_BIT6   : 1;    
        uint8 OSCFIP_BIT7 : 1;
    };
    uint8 IPR2_Register;
}IPR2_REG_t;

#define IPR2_REG (*((volatile IPR2_REG_t *)0xFA2))

typedef union{
    struct{
            uint8 BOR_BIT0      : 1;
            uint8 POR_BIT1      : 1;
            uint8 PD_BIT2       : 1;
            uint8 TO_BIT3       : 1;
            uint8 RI_BIT4       : 1;
            uint8 RESERVED_BIT5 : 1;
            uint8 SBOREN_BIT6   : 1;  
            uint8 IPEN_BIT7     : 1;
    };
    uint8 RCON_Register;
}RCON_REG_t;

#define RCON_REG (*((volatile RCON_REG_t *)0xFD0))


#define IOCB_REG (*((volatile uint8 *) 0xF7D))


/**************************Needed Macros For code readability******************/
#define INTCON_M       0
#define INTCON2_M      0
#define PIR1_M         1
#define PIE1_M         1
#define IPR1_M         1
#define PIR2_M         2
#define PIE2_M         2
#define IPR2_M         2



/*Interrupts flags polling to be used in building the ISR*/
#define NOTHING     0;

#define EXTINT1_P   {                                   \
    if(INTCON3_REG.INT1IF_BIT0)                         \
    {                                                   \
        EXTINT1_CallBack();                             \
        INTCON3_REG.INT1IF_BIT0 = CLEAR;                \
    }                                                   \
}                          

#define EXTINT2_P  {                                    \
    if(INTCON3_REG.INT2IF_BIT1)                         \
    {                                                   \
        EXTINT2_CallBack();                             \
        INTCON3_REG.INT2IF_BIT1 = CLEAR;                \
    }                                                   \
}

#define IOCB_P     {                                    \
    if(INTCON_REG.RBIF_BIT0)                            \
    {                                                   \
        IOCB_CallBack();                                \
        INTCON_REG.RBIF_BIT0 = CLEAR;                   \
    }                                                   \
}

#define TMR0_P     {                                    \
    if(INTCON_REG.TMR0IF_BIT2)                          \
    {                                                   \
        TMR0_CallBack();                                \
        INTCON_REG.TMR0IF_BIT2 = CLEAR;                 \
    }                                                   \
}

#define TMR1_P     {                                    \
    if(PIR1_REG.TMR1IF_BIT0)                            \
    {                                                   \
        TMR1_CallBack();                                \
        PIR1_REG.TMR1IF_BIT0 = CLEAR;                   \
    }                                                   \
}

#define TMR2_P     {                                    \
    if(PIR1_REG.TMR2IF_BIT1)                            \
    {                                                   \
        TMR2_CallBack();                                \
        PIR1_REG.TMR2IF_BIT1 = CLEAR;                   \
    }                                                   \
}

#define CCP1_P     {                                    \
    if(PIR1_REG.CCP1IF_BIT2)                            \
    {                                                   \
        CCP1_CallBack();                                \
        PIR1_REG.CCP1IF_BIT2 = CLEAR;                   \
    }                                                   \
}


#define SSP_P     {                                     \
    if(PIR1_REG.SSPIF_BIT3)                             \
    {                                                   \
        SSP_CallBack();                                 \
        PIR1_REG.SSPIF_BIT3 = CLEAR;                    \
    }                                                   \
}

#define TX_P     {                                      \
    if(PIR1_REG.TXIF_BIT4)                              \
    {                                                   \
        TX_CallBack();                                  \
        PIR1_REG.TXIF_BIT4 = CLEAR;                     \
    }                                                   \
}

#define RC_P     {                                      \
    if(PIR1_REG.RCIF_BIT5)                              \
    {                                                   \
        RC_CallBack();                                  \
        PIR1_REG.RCIF_BIT5 = CLEAR;                     \
    }                                                   \
}

#define AD_P     {                                      \
    if(PIR1_REG.ADIF_BIT6)                              \
    {                                                   \
        AD_CallBack();                                  \
        PIR1_REG.ADIF_BIT6 = CLEAR;                     \
    }                                                   \
}


#define PSP_P     {                                     \
    if(PIR1_REG.PSPIF_BIT7)                             \
    {                                                   \
        PSP_CallBack();                                 \
        PIR1_REG.PSPIF_BIT7 = CLEAR;                    \
    }                                                   \
}

#define CCP2_P     {                                    \
    if(PIR2_REG.CCP2IF_BIT0)                            \
    {                                                   \
        CCP2_CallBack();                                \
        PIR2_REG.CCP2IF_BIT0 = CLEAR;                   \
    }                                                   \
}

#define TMR3_P     {                                    \
    if(PIR2_REG.TMR3IF_BIT1)                            \
    {                                                   \
        TMR3_CallBack();                                \
        PIR2_REG.TMR3IF_BIT1 = CLEAR;                   \
    }                                                   \
}

#define HLVD_P     {                                    \
    if(PIR2_REG.HLVDIF_BIT2)                            \
    {                                                   \
        HLVD_CallBack();                                \
        PIR2_REG.HLVDIF_BIT2 = CLEAR;                   \
    }                                                   \
}

#define BCL_P     {                                     \
    if(PIR2_REG.BCLIF_BIT3)                             \
    {                                                   \
        BCL_CallBack();                                 \
        PIR2_REG.BCLIF_BIT3 = CLEAR;                    \
    }                                                   \
}

#define EE_P     {                                      \
    if(PIR2_REG.EEIF_BIT4)                              \
    {                                                   \
        EE_CallBack();                                  \
        PIR2_REG.EEIF_BIT4 = CLEAR;                     \
    }                                                   \
}

#define C2_P     {                                      \
    if(PIR2_REG.C2IF_BIT5)                              \
    {                                                   \
        C2_CallBack();                                  \
        PIR2_REG.C2IF_BIT5 = CLEAR;                     \
    }                                                   \
}

#define C1_P     {                                      \
    if(PIR2_REG.C1IF_BIT6)                              \
    {                                                   \
        C1_CallBack();                                  \
        PIR2_REG.C1IF_BIT6 = CLEAR;                     \
    }                                                   \
}

#define OSCF_P     {                                    \
    if(PIR2_REG.OSCFIF_BIT7)                            \
    {                                                   \
        OSCF_CallBack();                                \
        PIR2_REG.OSCFIF_BIT7 = CLEAR;                   \
    }                                                   \
}


#endif	/* INTERRUPT_PRIVATE_H */

