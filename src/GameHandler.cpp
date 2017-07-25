// Physics Calculations

#include "../include/GameHandler.hpp"


void GameHandler::UpdateThrust(int y, int delta) {
  int thrust;
  if (y > 100) {
    thrust = 100;
  } else if (y < 0) {
    thrust = 0;
  } else {
    thrust = y;
  }
  p.setThrust(thrust);
}

void GameHandler::UpdateRotation(SDL_Keysym k, int delta) {
    int currentDir = p.getDir();
    if (k.sym == SDLK_a) {
      currentDir += delta * 90 / 1000; // Turn the ship 90 degrees max every second.
    } else if (k.sym == SDLK_d) {
      currentDir += delta * 90 * -1 / 1000;
    }
}
