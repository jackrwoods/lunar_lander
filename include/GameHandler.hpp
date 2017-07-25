#ifndef GAMEHANDLER_HPP
#define GAMEHANDLER_HPP

#include "SDL2/SDL.h"
#include "Player.hpp"
#include "Terrain.hpp"
#include <cmath>

class GameHandler {
  private:
    Player p;
    Terrain t;
  public:
    GameHandler();

    /* Change the thrust currently being applied to the player. */
    void UpdateThrust(int, int);

    /* Change the player's direction based on keyboard input. */
    void UpdateRotation(SDL_Keysym, int);

    /* Check for collisions and update player/terrain locations. */
    void CollisionsCheck();

    /* Uses the SDL window surface buffer to render the current frame. */
    void renderFrame(SDL_Surface);
};

#endif
