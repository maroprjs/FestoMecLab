/*
 * Magazine.cpp
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#include "Magazine.h"
#include "Defines.h"

Magazine::Magazine() {
	_fwdPin = MAG_FWD_PIN;
    _rvsPin = MAG_RVS_PIN;
    _elapsedTime = 0;
    _initRequired = false;
    _charged = true; //in reverse(back)

}

void Magazine::begin(){
	pinMode(_fwdPin, OUTPUT);
	pinMode(_rvsPin, OUTPUT);
	backward();
}

void Magazine::loop(){
	if (millis() > _elapsedTime + HIGH_TIME){
		if (_initRequired == true){
			initialize();

		}
	}

}

void Magazine::forward(){
	digitalWrite(_fwdPin, HIGH);
	_initRequired = true;
	_charged = false; //is forward
	_elapsedTime = millis();

}

void Magazine::backward(){
	digitalWrite(_rvsPin, HIGH);
	_initRequired = true;
	_charged = true;
	_elapsedTime = millis();
}


//private
void Magazine::initialize(){
    digitalWrite(_fwdPin, LOW);
    digitalWrite(_rvsPin, LOW);
    _initRequired = false;
}

Magazine::~Magazine() {
	// TODO Auto-generated destructor stub
}

