// Physics Calculations

#include "../include/GameHandler.hpp"
#include <cmath>

#define PI 3.14159265

GameHandler::GameHandler(){
  p = new Player();
  t = new Terrain(100); // Integer passed into Terrain determines size
}

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
  p.setVelocity(thrust * cos(dir * PI / 180), thrust * sin(dir * PI/180));
}

void GameHandler::UpdateRotation(SDL_Keysym k, int delta) {
    int currentDir = p.getDir();
    if (k.sym == SDLK_a) {
      currentDir += delta * 90 / 1000; // Turn the ship 90 degrees max every second.
    } else if (k.sym == SDLK_d) {
      currentDir += delta * 90 * -1 / 1000;
    }
}

void GameHandler::CollisionsCheck(int delta) {
  // Calculate new position of Player
  Vector2* v = p.getVector(0);
  int x = v.getX();
  int y = v.getY();
  x += p.getXVel();
  y += p.getYVel();
  p.setMainVector(x, y);


  // Rotate the player vectors
  Vector2* pv = p.rotateVectors(p.getDir());
  // Get the list of terrain vectors
  LinkedList* vectors = t.getVectors();
  // Find the terrain vectors below the player
  Vector2* current = getLinkedList(vectors, x);

  // PlatformVectors perform differently than normal TerrainVectors
  // but both calculations require the line
  float m = current->data->getY() - current->next->data->getY() /
            current->data->getX() - current->next->data->getX();
  
  if (current->data->type == 1 && current->next->type == 1) {
    // if both vectors below the player are platforms, then test for landing
    if () {

    }
  } else {
    // if the ground below is not a platform, all collisions result in death
  }
}
