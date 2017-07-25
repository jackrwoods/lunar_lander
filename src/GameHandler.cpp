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
