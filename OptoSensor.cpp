/*
 * OptoSensor.cpp
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#include "OptoSensor.h"
#include "Defines.h"

OptoSensor::OptoSensor(Conveyor * conveyor) {
	_conveyor = conveyor;
	_sensorPin = CONV_OPT_SENSOR;
	_objectDetected = false;
	_lastDetected = false;
	_newObject = false;
	_autoModeOn = true;
	_elapsedTime = 0;
}

void OptoSensor::begin(){
	pinMode(_sensorPin, INPUT);

}

void OptoSensor::loop(){
	_objectDetected = (digitalRead(_sensorPin) == HIGH) ? true : false ;
	if ((_objectDetected == true) && (_lastDetected == false)){ //at LOW to HIGH
		_newObject = true;
	};
	_lastDetected = _objectDetected;
	if (_autoModeOn){
		if (millis() > _elapsedTime + DEBOUNCE_TIME){
			//_objectDetected = (digitalRead(_sensorPin) == HIGH) ? true : false ;
			if (_objectDetected){
				_conveyor->start();
				_conveyor->delayedStop();
				_elapsedTime = millis();
			}

		}
	}

}

void OptoSensor::autoOn(){
	_autoModeOn = true;
}

void OptoSensor::autoOff(){
	_autoModeOn = false;
}

bool OptoSensor::isNewObjectDetected(){
	bool retVal = _newObject;
    _newObject = false;
	return retVal;
}


OptoSensor::~OptoSensor() {
	// TODO Auto-generated destructor stub
}

