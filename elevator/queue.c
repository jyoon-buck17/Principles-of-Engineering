#ifndef _queue
#define _queue

// stores the currently queued requests as an array of boolean values.
// [floor 1?, floor 2?, floor 3?]
bool queue[3] = {false, false, false};

// gets the most efficient next target, based on the current location and the queue.
int getNextTarget(int currentLocation) {
  if (currentLocation == 0) {
    if (queue[1]) return 1;
    if (queue[2]) return 2;
    // if already at the floor, there's nowhere to go
    return -1;
  }
  if (currentLocation == 1) {
    if (queue[0]) return 0;
    if (queue[2]) return 2;
    return -1;
  }
  if (currentLocation == 2) {
    if (queue[1]) return 1;
    if (queue[0]) return 0;
    return -1;
  }

  return -1; // we shouldn't ever get here
}

// remove a location from the queue. returns true iff that location was already queued.
bool dequeue(int location) {
  if (!queue[location]) return false;
  queue[location] = false;
  return true;
}

#endif