#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           motorRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motorLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           motorServo,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Project Title: Activity 3.1.2 Basic Outputs Programming
Team Members: DeShawn Turner, Jordan Yoon-Buck
Date: February 21, 2017
Section: POE B1


Task Description:


Pseudocode:

*/

void stopMotors() {
	motor[motorLeft] = motor[motorRight] = 0;
	wait(0.5);
}

task main() {

	motor[motorRight] = 128 / 2;
	wait(5);
	stopMotors();
	motor[motorLeft] = -128 * 3 / 4;
	wait(2.5);
	stopMotors();
	motor[motorRight] = motor[motorLeft] = 256;
	wait(7.25);
	stopMotors();

  /*
	int target = 0;
	while (1) {
		motor[motorLeft] = SensorValue[potentiometer] / 32 * sinDegrees( target++ / 512 );
		if (target == 512 * 360) target = 0;
		if (SensorValue[bumpSwitch] == true) {
			motor[motorLeft] = 0;
			waitUntil(SensorValue[bumpSwitch] == false);
			target = 0;
		}
		if (SensorValue[limitSwitch] == true) {
			motor[motorLeft] = 0;
			target -= 512 * 128;
			waitUntil(SensorValue[limitSwitch] == false);
		}
	}
	*/
}