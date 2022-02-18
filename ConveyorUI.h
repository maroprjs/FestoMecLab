/*
 * ConveyorUI.h
 *
 *  Created on: 14 Feb 2021
 *      Author: pionet
 */

#ifndef CONVEYORUI_H_
#define CONVEYORUI_H_
#include "Modem.h"
#include "Conveyor.h"
#include "OptoSensor.h"
#include "Deflector.h"
#include "InductiveSensor.h"
#include "PressureSensor.h"
#include "Magazine.h"


#define PUBLISH_TIME_INTERVAL_MS 1000
#define PUBLISH_MSG_ID 4

class ConveyorUI {
public:
	ConveyorUI(Modem* modem, Conveyor* conveyor, OptoSensor* optoSensor, InductiveSensor* inductiveSensor, Deflector* deflector, Magazine* magazine,PressureSensor* pressureSensor);
	void begin();
	void loop();
	bool serialMMI(char command);
	virtual ~ConveyorUI();

private:
	void publishStatus();

private:
	Modem* _modem;
	Conveyor* _conveyor;
	OptoSensor* _optoSensor;
	InductiveSensor* _inductiveSensor;
	Magazine* _magazine;
	Deflector* _deflector;
	PressureSensor* _pressureSensor;
	char* _rxMsg;
	char* _txMsg;
	uint32_t _elapsedPublishTime;
	uint32_t _publishInterval;
};

#endif /* CONVEYORUI_H_ */
