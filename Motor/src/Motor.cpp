/*
 * Motor.cpp
 *
 *  Created on: 1 Jun 2023
 *      Author: jondurrant
 */

#include "Motor.h"
#include "hardware/pwm.h"

Motor::Motor(uint8_t gpA, uint8_t gpB) {
	xGPA = gpA;
	xGPB = gpB;

	gpio_init(xGPA);
	gpio_set_function(xGPA, GPIO_FUNC_PWM);
	pwm_set_gpio_level(xGPA, 0);
	uint slice_num = pwm_gpio_to_slice_num(xGPA);
	pwm_set_enabled(slice_num, true);

	gpio_init(xGPB);
	gpio_set_function(xGPB, GPIO_FUNC_PWM);
	pwm_set_gpio_level(xGPB, 0);
	slice_num = pwm_gpio_to_slice_num(xGPB);
	pwm_set_enabled(slice_num, true);
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}


void Motor::setThrottle(float throttle, bool forward){
	if (throttle < 0.0){
		return;
	}
	if (throttle > 1.0) {
		return;
	}

	uint16_t duty = ((float)(0xFFFF) * throttle);
	if (forward){
		pwm_set_gpio_level(xGPB, 0.0);
		pwm_set_gpio_level(xGPA, duty);
	} else {
		pwm_set_gpio_level(xGPA, 0.0);
		pwm_set_gpio_level(xGPB, duty);
	}
}

