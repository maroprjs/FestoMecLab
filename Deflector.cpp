/*
 * Deflector.cpp
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#include "Deflector.h"
#include "Defines.h"

Deflector::Deflector() {
	_deflectorPin = DEFLECTOR_PIN;
	_deflectorActive = false;

}

void Deflector::begin(){
	pinMode(_deflectorPin, OUTPUT);
	digitalWrite(_deflectorPin, LOW);

}

void Deflector::activate(){
	digitalWrite(_deflectorPin, HIGH);
	_deflectorActive = true;

}

void Deflector::deactivate(){
	digitalWrite(_deflectorPin, LOW);
	_deflectorActive = false;
}
Deflector::~Deflector() {
	// TODO Auto-generated destructor stub
}

