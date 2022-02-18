/*
 * Deflector.h
 *
 *  Created on: 11 Feb 2022
 *      Author: pionet
 */

#ifndef DEFLECTOR_H_
#define DEFLECTOR_H_
#include "Arduino.h"

class Deflector {
public:
	Deflector();
	void begin();
	void activate();
	void deactivate();
	bool isActive(){ return _deflectorActive;};
	virtual ~Deflector();
private:
	uint8_t _deflectorPin;
	bool _deflectorActive;
};

#endif /* DEFLECTOR_H_ */
