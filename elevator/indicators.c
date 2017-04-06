#ifndef indicators
#define indicators

int indMode[3] = {0, 0, 0};
/* INDICATOR MODES
 * 0: off
 * 1: on
 * 2: slow blink
 * 3: fast blink
 * 4: (pwm) dim
 */



// tick used for 
int indicatorTick = 0;

// refreshes the indicator LEDs, updating them if necessary
void doIndicateTick() {

  int flashSpeed = 4096;

  for (int flr = 0; flr < 3; ++flr) {
    switch (indMode[flr]) {
      case 1:
        turnLEDOn(ind[flr]);
        break;
      case 2:
        flashSpeed *= 2;
        /* falls through */
      case 3:
        if (indicatorTick % flashSpeed > flashSpeed / 2)
          turnLEDOn(ind[flr]);
        else
          turnLEDOff(ind[flr]);
        break;
      case 4:
        if (!(indicatorTick % 4))
          turnLEDOn(ind[flr]);
        else
          turnLEDOff(ind[flr]);
        break;
      default:
        turnLEDOff(ind[flr]);
        break;
    }
  }
  indicatorTick++;
  if (indicatorTick > flashSpeed * 2) indicatorTick = 0;
}



#endif