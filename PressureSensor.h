/*
 * PressureSensor.h
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_
#include "Arduino.h"

class PressureSensor {
public:
	PressureSensor();
	void begin();
	bool isTooLittlePressure();
	virtual ~PressureSensor();
private:
	uint8_t _sensorPin;
};

#endif /* PRESSURESENSOR_H_ */
