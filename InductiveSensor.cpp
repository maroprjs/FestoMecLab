/*
 * InductiveSensor.cpp
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#include "InductiveSensor.h"
#include "Defines.h"

InductiveSensor::InductiveSensor(Deflector * deflector) {
	_deflector = deflector;
	_sensorPin = CONV_MAGN_SENSOR;
	_objectDetected = false;
	_lastDetected = false;
	_newObject = false;
	_autoModeOn = true;
	_elapsedTime = 0;

}

void InductiveSensor::begin(){
	pinMode(_sensorPin, INPUT);

}

void InductiveSensor::loop(){
	_objectDetected = (digitalRead(_sensorPin) == HIGH) ? true : false ;
	if ((_objectDetected == true) && (_lastDetected == false)){ //at LOW to HIGH
		_newObject = true;
	};
	_lastDetected = _objectDetected;
	if (_autoModeOn){
		if (millis() > _elapsedTime + DEBOUNCE_TIME){
			//_objectDetected = (digitalRead(_sensorPin) == HIGH) ? true : false ;
			if (_objectDetected){
				_deflector->activate();
				_elapsedTime = millis();
			}else{
				if (_deflector->isActive()){
					_deflector->deactivate();
				}
			}

		}
	}

}


void InductiveSensor::autoOn(){
	_autoModeOn = true;
}

void InductiveSensor::autoOff(){
	_autoModeOn = false;
}

bool InductiveSensor::isNewObjectDetected(){
	bool retVal = _newObject;
    _newObject = false;
	return retVal;
}

InductiveSensor::~InductiveSensor() {
	// TODO Auto-generated destructor stub
}

