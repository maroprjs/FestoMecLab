/**
 *  @file		FestoConveyor.ino
 *
 *  @author		maro
 *  @date		mm/dd/yyyy
 *  @version	x.y
 *
 *  @brief 		Main
 *
 *  @section DESCRIPTION
 *
 *  Instantiation and control of objects integrated in Conveyor IND21
 *
 */

/////////// Includes /////////////////
#include "Arduino.h"
#include <Controllino.h>
#include "Modem.h"
#include "Conveyor.h"
#include "OptoSensor.h"
#include "InductiveSensor.h"
#include "Deflector.h"
#include "Magazine.h"
#include "PressureSensor.h"
#include "ConveyorUI.h"
#include "Defines.h"


/////////defines //////////////////////

//defines moved to Defines.h

////////// Object Instantiation //////////////////
/*************************************************************
 * modem - local MMI represented by serial interface, WebUI by server IP and port
 */
IPAddress udpServerIP(UDP_SERVER_IP);
IPAddress ownIP(OWN_IP);
uint16_t udpServerPort = UDP_SERVER_PORT;

Modem modem(&Serial, udpServerIP, udpServerPort, ownIP);

/*************************************************************
 * Conveyor
 */
Conveyor conveyor;

/*************************************************************
 * Infrared Sensor
 */
OptoSensor optoSensor(&conveyor); //need to tell  conveyor to start

/*************************************************************
 * Solenoid Deflector
 */
Deflector deflector;
/*************************************************************
 * Inductive Sensor
 */
InductiveSensor inductiveSensor(&deflector); //need to tell deflector to to act

/*************************************************************
 * Magazine
 */
Magazine magazine;

/*************************************************************
 * Pressuer sensor
 */
PressureSensor pressureSensor;

/*************************************************************
 * UI
 */
ConveyorUI conveyorUI(&modem, &conveyor, &optoSensor, &inductiveSensor, &deflector, &magazine, &pressureSensor);

void setup()
{
	Serial.begin(9600);
	delay(100);
	modem.begin();
	conveyor.begin();
	optoSensor.begin();
	inductiveSensor.begin();
	magazine.begin();
	pressureSensor.begin();
	conveyorUI.begin();
}

// The loop function is called in an endless loop
void loop()
{
	modem.loop();
	conveyor.loop();
	optoSensor.loop();
	inductiveSensor.loop();
	magazine.loop();
	conveyorUI.loop();
}
