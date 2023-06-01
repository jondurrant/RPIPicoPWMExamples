/*
 * Motor.h
 *
 *  Created on: 1 Jun 2023
 *      Author: jondurrant
 */

#ifndef MOTOR_SRC_MOTOR_H_
#define MOTOR_SRC_MOTOR_H_

#include "pico/stdlib.h"

class Motor {
public:
	Motor(uint8_t gpA, uint8_t gpB);
	virtual ~Motor();

	/***
	 * Set Throttle
	 * @param throttle 0 to 1.0
	 * @param forward - true if forward, otherwise motor run in reverse
	 */
	void setThrottle(float throttle, bool forward);

private:

	uint8_t xGPA;
	uint8_t xGPB;
};

#endif /* MOTOR_SRC_MOTOR_H_ */
