#ifndef utilities
#define utilities

// get the direction in which the elevator needs to go, based on its target
// int getDirection(int currentLocation, int target) {
//   // no direction if at the floor or no target
//   if (target == -1) return 0;
//   if (target == currentLocation) return 0;

//   if (target < currentLocation) return -1;
//   if (target > currentLocation) return 1;

//   return 0; // we shouldn't ever get here
// }

// indirection: buttons
int call[3] = {call0, call1, call2};

// indirection: indicator lamps
int ind[3] = {ind0, ind1, ind2};

#endif