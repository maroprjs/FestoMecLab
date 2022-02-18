/*
 * OptoSensor.h
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#ifndef OPTOSENSOR_H_
#define OPTOSENSOR_H_
#include "Conveyor.h"
#include "Arduino.h"

#define DEBOUNCE_TIME 2000 //ignores state changes for this time

class OptoSensor {
public:
	OptoSensor(Conveyor * conveyor);
	void begin();
	void loop();
	void autoOn();
	void autoOff();
	bool isNewObjectDetected();
	bool isAutoMode(){ return _autoModeOn;};
	bool objectDetected(){ return _objectDetected;};
	virtual ~OptoSensor();
private:
	Conveyor * _conveyor;
	uint8_t _sensorPin;
	bool _objectDetected;
	bool _autoModeOn;
	bool _lastDetected;
	bool _newObject;
	unsigned long _elapsedTime;
};

#endif /* OPTOSENSOR_H_ */
