/*
 * Defines.h
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#ifndef DEFINES_H_
#define DEFINES_H_
#include "Controllino.h"

//Conveyor claas:
#define CONV_PWR_PIN CONTROLLINO_D3
#define CONV_DIR_PIN CONTROLLINO_D4

//Deflector
#define DEFLECTOR_PIN CONTROLLINO_D2

//InductiveSensor class
#define CONV_MAGN_SENSOR CONTROLLINO_A0 //triggers the Solenoid as stopper/deflector

//OptoSensor call:
#define CONV_OPT_SENSOR CONTROLLINO_A1 //triggers converyor start in automatic mode

//Magazine:
#define MAG_FWD_PIN  CONTROLLINO_D0
#define MAG_RVS_PIN   CONTROLLINO_D1

//PressureSensor class:
#define PRESSURE_SENSOR  CONTROLLINO_A2

//IP related
#define OWN_IP 10, 200, 20, 192
#define UDP_SERVER_IP 10, 200, 20, 190 //application server f�r e.g. GUI to send status information
#define UDP_SERVER_PORT 5555
#define MAC_ADDRESS { 0xCA, 0xFE, 0xBE, 0xEF, 0xFE, 0xED }
#define LOCAL_UDP_PORT 3333



#endif /* DEFINES_H_ */
