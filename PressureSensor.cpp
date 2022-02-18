/*
 * PressureSensor.cpp
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#include "PressureSensor.h"
#include "Defines.h"

PressureSensor::PressureSensor() {
	_sensorPin = PRESSURE_SENSOR;

}

void PressureSensor::begin(){
	pinMode(_sensorPin, INPUT);
}


bool PressureSensor::isTooLittlePressure(){
	return !digitalRead(_sensorPin);
}

PressureSensor::~PressureSensor() {
	// TODO Auto-generated destructor stub
}

