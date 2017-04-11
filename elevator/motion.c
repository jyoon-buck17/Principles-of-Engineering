#ifndef motion
#define motion

// speed settings. fast speed is not currently used.
int speedSlow = 55;
int speedFast = 90;

// constants for direction control.
int up = -1;
int down = 1;

// correct for lag in motor stopping by stopping early.
// higher = more correction, for faster speeds. (encoder units - degrees?)
int motionCorrection = 8;

// helper for motion.
void go(int speed) {
  motor[driver] = speed;
}

// helper for determining position.
int where() {
  return SensorValue[count];
}

// return to the bottom, realign
void resetOnly() {
  // dim all leds
  indMode[0] = indMode[1] = indMode[2] = 4;
  // go down until reset limit switch is pressed
  go(speedSlow * down);
  while (!SensorValue[resetSw]) {
    doIndicateTick();
  }
  // stop, go up until switch is released.
  go(0);
  go((speedSlow + 5) * up);
  while (SensorValue[resetSw]) {
    doIndicateTick();
    SensorValue[count] = 0;
  }
  // stop.
  go(0);
}

// return to the bottom, realign, and then return to floor one.
void doReset() {
  // return to top of limit switch
  resetOnly();

  // go slowly up. flash the first floor indicator.
  go((speedSlow + 5) * up);
  indMode[0] = 3;
  // move until at the correct location, then stop
  while (where() < floors[0] - motionCorrection) {
    doIndicateTick();
  }
  go(0);

  // turn lights off,
  indMode[0] = 1;
  indMode[1] = indMode[2] = 0;
}

// this isn't currently called from the loop, but it is useful to have.
// allows the system to be calibrated as needed.
// directions for calibration:
//  - use the gear on the main shaft to adjust the height of the motor.
//  - when the cart is at the correct height for each floor, press that
//    floor's call button. that floor's indicator light should turn on.
//  - press the reset limit switch to complete calibration.
//  - important: to persist the calibration, use the global variables panel
//    to find the value of floors[]. change the literals on elevator.c:23.
void calibrate() {
  resetOnly();
  go(speedSlow * up);

  while (SensorValue[resetSw]) {}

  delay(0.25);
  go(0);
  // until the reset switch is pressed, perform manual calibration
  while (!SensorValue[resetSw]) {
      if (SensorValue[call0]) {
        floors[0] = where();
        indMode[0] = 1;
      }
      if (SensorValue[call1]) {
        floors[1] = where();
        indMode[1] = 1;
      }
      if (SensorValue[call2]) {
        floors[2] = where();
        indMode[2] = 1;
      }
  }
  // wait until the reset switch is unpressed
  while (SensorValue[resetSw]) {
    doIndicateTick();
  }
}

// move to a floor.
void goToFloor(int target) {
  // determine the necessary encoder value and direction of motion.
  int targetCount = floors[target];
  bool goingUp = where() < targetCount;

  indMode[target] = 3;

  // move, and then stop.
  go(speedSlow * (goingUp ? up : down));
  while (goingUp
          ? (where() < (targetCount - motionCorrection))
          : (where() > (targetCount + motionCorrection))
        ) {
    lifecycle(true);
  }
  go(0);

  // stop and dequeue.
  indMode[target] = 1;
  dequeue(target);
}



#endif
