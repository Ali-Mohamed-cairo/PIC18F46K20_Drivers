/* 
 * File:   DIO_Private.h
 * Author: Ali Mohamed
 *
 * Created on March 1, 2024, 6:26 PM
 */

#ifndef DIO_PRIVATE_H
#define	DIO_PRIVATE_H

#include "../../Platform_Types.h"

/*********************************PORTA******************************************/

/*TRISA REGISTER : IT'S THE REGISTER RESPONSIBLE FOR DETERMINING PORT DIRECTION*/
 
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

#define TRISA_REG (*((volatile TRISA_t *)0xF92))

/*LATA REGISTER : IT'S THE REGISTER RESPONSIBLE FOR PIN VALUE @OUTPUT STATE****/

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

#define LATA_REG (*((volatile LATA_t *)0xF89))

/*PORTA REGISTER : IT'S THE REGISTER WHICH CONTAINS THE PIN VALUE @INPUT STATE*/

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

#define PORTA_REG (*((volatile PORTA_t *)0xF80))


/*********************************PORTB******************************************/

/*TRISB REGISTER : IT'S THE REGISTER RESPONSIBLE FOR DETERMINING PORT DIRECTION*/
 
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

#define TRISB_REG (*((volatile TRISB_t *)0xF93))

/*LATB REGISTER : IT'S THE REGISTER RESPONSIBLE FOR PIN VALUE @OUTPUT STATE****/

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

#define LATB_REG (*((volatile LATB_t *)0xF8A))

/*PORTB REGISTER : IT'S THE REGISTER WHICH CONTAINS THE PIN VALUE @INPUT STATE*/

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

#define PORTB_REG (*((volatile PORTB_t *)0xF81))

/*********************************PORTC******************************************/

/*TRISC REGISTER : IT'S THE REGISTER RESPONSIBLE FOR DETERMINING PORT DIRECTION*/
 
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

#define TRISC_REG (*((volatile TRISC_t *)0xF94))

/*LATC REGISTER : IT'S THE REGISTER RESPONSIBLE FOR PIN VALUE @OUTPUT STATE****/

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

#define LATC_REG (*((volatile LATC_t *)0xF8B))

/*PORTC REGISTER : IT'S THE REGISTER WHICH CONTAINS THE PIN VALUE @INPUT STATE*/

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

#define PORTC_REG (*((volatile PORTC_t *)0xF82))

/*********************************PORTD******************************************/

/*TRISD REGISTER : IT'S THE REGISTER RESPONSIBLE FOR DETERMINING PORT DIRECTION*/
 
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

#define TRISD_REG (*((volatile TRISD_t *)0xF95))

/*LATD REGISTER : IT'S THE REGISTER RESPONSIBLE FOR PIN VALUE @OUTPUT STATE****/

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

#define LATD_REG (*((volatile LATD_t *)0xF8C))

/*PORTD REGISTER : IT'S THE REGISTER WHICH CONTAINS THE PIN VALUE @INPUT STATE*/

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

#define PORTD_REG (*((volatile PORTD_t *)0xF83))

/*********************************PORTE******************************************/

/*TRISE REGISTER : IT'S THE REGISTER RESPONSIBLE FOR DETERMINING PORT DIRECTION*/
 
typedef union {
    struct{
        uint8 TRISE_BIT0    : 1;
        uint8 TRISE_BIT1    : 1;
        uint8 TRISE_BIT2    : 1;
        uint8 RESERVEE_BIT3 : 1;
        uint8 TRISE_BIT4    : 1;
        uint8 TRISE_BIT5    : 1;
        uint8 TRISE_BIT6    : 1;
        uint8 TRISE_BIT7    : 1;        
    };
    struct{
        uint8 TRISE_BITS   : 3;
        uint8 RESERVEE_BIT : 1;
        uint8 PSPMODE_BIT4 : 1;
        uint8 IBOV_BIT5    : 1;
        uint8 OBF_BIT6     : 1;
        uint8 IBF_BIT7     : 1;        
    };
    uint8 TRISE_REGISTER;
}TRISE_t;

#define TRISE_REG (*((volatile TRISE_t *)0xF96))

/*LATE REGISTER : IT'S THE REGISTER RESPONSIBLE FOR PIN VALUE @OUTPUT STATE****/

typedef union {
    struct{
        uint8 LATE_BIT0 : 1;
        uint8 LATE_BIT1 : 1;
        uint8 LATE_BIT2 : 1;
        uint8 RESERVED_BITS : 5;        
    };
    uint8 LATE_REGISTER : 3;
}LATE_t;

#define LATE_REG (*((volatile LATE_t *)0xF8D))

/*PORTE REGISTER : IT'S THE REGISTER WHICH CONTAINS THE PIN VALUE @INPUT STATE*/

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

#define PORTE_REG (*((volatile PORTE_t *)0xF84))



#endif	/* DIO_PRIVATE_H */

