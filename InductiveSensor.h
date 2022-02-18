/*
 * InductiveSensor.h
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#ifndef INDUCTIVESENSOR_H_
#define INDUCTIVESENSOR_H_
#include "Deflector.h"

#define DEBOUNCE_TIME 5000 //ignores state changes for this time

class InductiveSensor {
public:
	InductiveSensor(Deflector * deflector);
	void begin();
	void loop();
	void autoOn();
	void autoOff();
	bool isNewObjectDetected();
	bool isAutoMode(){ return _autoModeOn;};
	bool objectDetected(){ return _objectDetected;};
	virtual ~InductiveSensor();
private:
	Deflector * _deflector;
	uint8_t _sensorPin;
	bool _objectDetected;
	bool _lastDetected;
	bool _autoModeOn;
	bool _newObject;
	unsigned long _elapsedTime;
};

#endif /* INDUCTIVESENSOR_H_ */
