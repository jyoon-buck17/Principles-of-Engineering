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
Project Title: Activity 3.1.3 Basic Inputs Programming
Team Members: DeShawn Turner, Jordan Yoon-Buck
Date: February 21, 2017
Section: POE B1
*/


task main() {
	motor[motorLeft] = motor[motorRight] = 63;	// turn both motors on
	untilEncoderCounts(480, quad);						  // until the encoder counts 480
	motor[motorLeft] = motor[motorRight] = -63; // change the direction of both motors
	untilEncoderCounts(360 * 3.5, quad);				// until the encoder counts another 3.5 rotations
	motor[motorLeft] = motor[motorRight] = 0;   // stop both motors
}