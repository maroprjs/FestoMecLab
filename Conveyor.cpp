/*
 * Conveyor.cpp
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#include "Conveyor.h"
#include "Defines.h"
//#include "Arduino.h"

Conveyor::Conveyor() {
 _pwrPin = CONV_PWR_PIN;
 _dirPin = CONV_DIR_PIN;
 _isForwardDir = true;
 _isMoving = false;
 _elapsedTime = 0;
 _delayedStopRequested = false;

}

void Conveyor::begin(){
	pinMode(_pwrPin, OUTPUT);
	pinMode(_dirPin, OUTPUT);
	digitalWrite(_pwrPin, LOW);
	digitalWrite(_dirPin, LOW);

}

void Conveyor::loop(){
	if (_delayedStopRequested == true){
		if (millis() > _elapsedTime + DELAY_TO_STOP_BELT){
			stop();
		}
	}


}

void Conveyor::start(){
	digitalWrite(_pwrPin, HIGH);
	_isMoving = true;
}

void Conveyor::stop(){
	digitalWrite(_pwrPin, LOW);
	_isMoving = false;
	_delayedStopRequested = false;

}
void Conveyor::delayedStop(){
	_delayedStopRequested = true;
	_elapsedTime = millis();
}

void Conveyor::forward(){
	bool isMoving = _isMoving;
	if (isMoving) stop();
	digitalWrite(_dirPin, LOW);
	_isForwardDir = true;
	if (isMoving) start();
}

void Conveyor::reverse(){
	bool isMoving = _isMoving;
	if (isMoving) stop();
	digitalWrite(_dirPin, HIGH);
	_isForwardDir = false;
	if (isMoving) start();
}

Conveyor::~Conveyor() {
	// TODO Auto-generated destructor stub
}

