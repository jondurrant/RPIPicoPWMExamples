/*
 * main.cpp
 *
 *  Created on: 9 Jun 2022
 *      Author: jondurrant
 */

#include "Motor.h"
#include <stdio.h>

#define DELAY 1000 // in microseconds

#define MOTOR_A_PAD 6 // GP6
#define MOTOR_B_PAD 7 // GP7


int main(){

	stdio_init_all();

	Motor m(MOTOR_A_PAD, MOTOR_B_PAD);


	while (true){

		m.setThrottle(0.0, true);
		sleep_ms(DELAY);
		for (float t=0.3; t < 1.0; t=t+0.1){
			m.setThrottle(t, true);
			sleep_ms(DELAY);
		}

		m.setThrottle(0.0, false);
		sleep_ms(DELAY);
		for (float t=0.3; t < 1.0; t=t+0.1){
			m.setThrottle(t, false);
			sleep_ms(DELAY);
		}

	}
}


