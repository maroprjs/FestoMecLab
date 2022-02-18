/*
 * Conveyor.h
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#ifndef CONVEYOR_H_
#define CONVEYOR_H_
#include "Arduino.h"

#define DELAY_TO_STOP_BELT 7000

class Conveyor {
public:
	Conveyor();
	void begin();
	void loop();
	void start();
	void stop();
	void delayedStop();
	void forward();
	void reverse();
	bool isMoving(){return _isMoving;};
	bool isFowardDir(){return _isForwardDir;};
	virtual ~Conveyor();
private:
	uint8_t _pwrPin;
	uint8_t _dirPin;
	bool _isForwardDir;
	bool _isMoving;
	unsigned long _elapsedTime;
	bool _delayedStopRequested;
};

#endif /* CONVEYOR_H_ */
