/*
 * ConveyorUI.cpp
 *
 *  Created on: 14 Feb 2021
 *      Author: pionet
 */

#include "ConveyorUI.h"

ConveyorUI::ConveyorUI(Modem* modem, Conveyor* conveyor, OptoSensor* optoSensor, InductiveSensor* inductiveSensor, Deflector* deflector, Magazine* magazine, PressureSensor* pressureSensor) {
	_modem = modem;
	_conveyor = conveyor;
	_optoSensor = optoSensor;
	_inductiveSensor = inductiveSensor;
	_deflector = deflector;
	_magazine = magazine;
	_pressureSensor =  pressureSensor;
	_rxMsg = new char[UDP_TX_PACKET_MAX_SIZE];
	_txMsg = new char[UDP_TX_PACKET_MAX_SIZE];
	_elapsedPublishTime = 0;
	_publishInterval = PUBLISH_TIME_INTERVAL_MS;

}

void ConveyorUI::begin(){
	_elapsedPublishTime = millis();
}

void ConveyorUI::loop(){
	if (_modem->msgArrived()){
		_modem->readMsg(_rxMsg);
		//Serial.println(_rxMsg);
		serialMMI(_rxMsg[0]);
	}
	while(_modem->mmiPort()->available()){
		char cmd = _modem->mmiPort()->read();
		_modem->mmiPort()->flush();
		serialMMI(cmd);
	}
	publishStatus();
}


/****************************
 *
 *
 *  a - (a)utomatic mode on (starts driving when IR sensor detects object)
 *  m - (m)manual mode on (ignores IR sensor)
 *  f - (f)orward flag (conveyor drives forward when start is called)
 *  r - (r)everse flag (conveyor drives backward when start is called)
 *  s - (s)start/stop
 *  d - (deflector) active/inactive (on/off)
 *  v - magazine forward
 *  z - magazin backward (charged)
 *
 */
bool ConveyorUI::serialMMI(char command){
	bool retVal = false;
	_modem->mmiPort()->print(command);
	switch (command){
	case 'a':{
			serialMMI('f');
			_optoSensor->autoOn(); //sensor armed - turns on motor for some time
			_inductiveSensor->autoOn(); //turns on deflector for some time
		}
		retVal = true;
		break;
	case 'm':{
			_optoSensor->autoOff(); //sensor disarmed
			_inductiveSensor->autoOff();
		}
		retVal = true;
		break;
	case 'f':{
	    	_conveyor->forward();
		}
		retVal = true;
		break;
	case 'r':{
	    	_conveyor->reverse();
		}
		retVal = true;
		break;
	case 's':{
			if (_conveyor->isMoving()){
				_conveyor->stop();
			}else{
				_conveyor->start();
			}
		}
		retVal = true;
		break;
	case 'd':{
			if (_deflector->isActive()){
				_deflector->deactivate();
			}else{
				_deflector->activate();
			}
		}
		retVal = true;
		break;
	case 'v':{
			_magazine->forward();
		}
		retVal = true;
		break;
	case 'z':{
			_magazine->backward();
		}
		retVal = true;
		break;
	}
	return retVal;
}

/*
 * this must be called in loop function
 *
 * protocol fields:
 *
 */
void ConveyorUI::publishStatus(){

	if (_optoSensor->isNewObjectDetected() || _inductiveSensor->isNewObjectDetected()){
		_elapsedPublishTime = 0; //that will make next if condition true immediately
	};

	if (millis() >= (_elapsedPublishTime + _publishInterval)){
		//build message
		sprintf((char*)_txMsg,"%u,%u,%u,%u,%u,%u,%u,%u,%u,%u", (unsigned int)PUBLISH_MSG_ID, \
				                            (unsigned int)_conveyor->isMoving(), \
											(unsigned int)_conveyor->isFowardDir(), \
											(unsigned int)_optoSensor->isAutoMode(), \
											(unsigned int)_optoSensor->objectDetected(), \
											(unsigned int)_deflector->isActive(), \
											(unsigned int)_inductiveSensor->isAutoMode(), \
											(unsigned int)_inductiveSensor->objectDetected(), \
											(unsigned int)_magazine->isCharged(), \
											(unsigned int)_pressureSensor->isTooLittlePressure());
		_modem->sendUdpMsg(_txMsg);
		_elapsedPublishTime = millis();
	}
}

ConveyorUI::~ConveyorUI() {
	// TODO Auto-generated destructor stub
}

