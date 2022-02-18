/*
 * Magazine.h
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#ifndef MAGAZINE_H_
#define MAGAZINE_H_
#include "Arduino.h"

#define HIGH_TIME 100

class Magazine {
public:
	Magazine();
	void begin();
	void loop();
	void forward();
	void backward();
	bool isCharged(){ return _charged;}; // in rvs
	virtual ~Magazine();
private:
	uint8_t _fwdPin;
	uint8_t _rvsPin;
	unsigned long _elapsedTime;
	bool _initRequired;
	bool _charged;

	void initialize();
};

#endif /* MAGAZINE_H_ */
