/*
 * main.cpp
 *
 *  Created on: 9 Jun 2022
 *      Author: jondurrant
 */

#include "Servo.h"
#include <stdio.h>

#define DELAY 1000 // in microseconds

#define SERVO_PAD 2 // GP2


int main(){

	stdio_init_all();

	Servo servo(SERVO_PAD);


	while (true){
		servo.goDegree(90.0);
		sleep_ms(DELAY);
		servo.goDegree(180.0);
		sleep_ms(DELAY);
		servo.goDegree(0.0);
		sleep_ms(DELAY);
		servo.goDegree(45.0);
		sleep_ms(DELAY);
		servo.goDegree(90.0);
		sleep_ms(DELAY);
		servo.goDegree(135.0);
		sleep_ms(DELAY);
		servo.goDegree(180.0);
		sleep_ms(DELAY);
	}
}


