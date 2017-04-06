#ifndef motion
#define motion

int speedSlow = 55;
int speedFast = 90;

int up = -1;
int down = 1;

void go(int speed) {
  motor[driver] = speed;
}

int where() {
  return SensorValue[count];
}

// return to the bottom, realign
void resetOnly() {
  indMode[0] = indMode[1] = indMode[2] = 4;
  go(speedSlow * down);
  while (!SensorValue[resetSw]) {
    doIndicateTick();
  }
  go(0);
  go((speedSlow + 5) * up);
  while (SensorValue[resetSw]) {
    doIndicateTick();
    SensorValue[count] = 0;
  }
  go(0);
}

// return to the bottom, realign, and then return to floor one.
void doReset() {
  resetOnly();
  
  go((speedSlow + 5) * up);
  indMode[0] = 3;
  while (where() < floors[0] - 5) {
    doIndicateTick();
  }
  go(0);

  indMode[0] = 1;
  indMode[1] = indMode[2] = 0;
}

void calibrate() {
  resetOnly();
  // until the reset switch is pressed, allow calibration
  while (!SensorValue[resetSw]) {
      if (SensorValue[call0]) {
        floors[0] = where();
        ind[0] = 1;
      }
      if (SensorValue[call1]) {
        floors[1] = where();
        ind[1] = 1;
      }
      if (SensorValue[call2]) {
        floors[2] = where();
        ind[2] = 1;
      }
  }
  while (SensorValue[resetSw]) {
    doIndicateTick();
  }
}

void goToFloor(int target) {
  int targetCount = floors[target];
  bool goingUp = where() < targetCount;

  indMode[target] = 3;

  go(speedSlow * (goingUp ? up : down));
  while (goingUp ? (where() < targetCount - 5) : (where() > targetCount - 5)) {
    lifecycle(true);
  }
  go(0);

  indMode[target] = 1;
  dequeue(target);
}



#endif
