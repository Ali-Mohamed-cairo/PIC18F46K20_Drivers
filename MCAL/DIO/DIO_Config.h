/* 
 * File:   DIO_Config.h
 * Author: Ali Mohamed
 *
 * Created on March 1, 2024, 6:26 PM
 */

#ifndef DIO_CONFIG_H
#define	DIO_CONFIG_H


#define PIN_APIs_CONFIG               0x00
#define PORT_APIs_CONFIG              0x01
#define PORT_PIN_APIs_CONFIG          0x03

#define APIs_CONFIG                   PORT_PIN_APIs_CONFIG
/*Configure the avaliable APIs for usage.
 * Options are: 1- PIN_APIs_CONFIG
 *              2- PORT_APIs_CONFIG
 *              3- PORT_PIN_APIs_CONFIG
 */

#endif	/* DIO_CONFIG_H */

