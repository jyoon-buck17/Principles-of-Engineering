#ifndef indicators
#define indicators

int indMode[3] = {0, 0, 0};
/* various modes for indicators, might not all be used
 * 0: off
 * 1: on
 * 2: slow blink
 * 3: fast blink
 * 4: dim (PWM, i.e., very very fast blink)
 */

// counter used for indicator timing
int indicatorTick = 0;

// refreshes the indicator LEDs, updating them if necessary
void doIndicateTick() {
  // speed of flashing (in ticks)
  int flashSpeed = 4096;
  // iterate through each LED
  for (int flr = 0; flr < 3; ++flr) {
    switch (indMode[flr]) {
      case 1:
        // led is on
        turnLEDOn(ind[flr]);
        break;
      case 2:
        // led is flashing slowly
        flashSpeed *= 2;
        /* falls through */
      case 3:
        // led is flashing quickly
        if ((indicatorTick % flashSpeed) > (flashSpeed / 2))
          turnLEDOn(ind[flr]);
        else
          turnLEDOff(ind[flr]);
        break;
      case 4:
        // led is dim
        if (!(indicatorTick % 4))
          turnLEDOn(ind[flr]);
        else
          turnLEDOff(ind[flr]);
        break;
      default:
        // led is off
        turnLEDOff(ind[flr]);
        break;
    }
  }
  // increment the tick, and loop around if appropriate.
  indicatorTick++;
  if (indicatorTick > flashSpeed * 2) indicatorTick = 0;
}

#endif