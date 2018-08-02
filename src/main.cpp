//USing SDL and standard IO
#include "../lib/include/SDL.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "../include/GameHandler.hpp"

int main(int argc, char* argv[]) {
	// Create empty pointer to SDL objects
	SDL_Window* w = NULL; // The window we render to
	SDL_Surface* s = NULL; // The surface contained in the window

	// Get current display mode (resolution and refresh rate)
	SDL_DisplayMode d;
	int SCREEN_WIDTH, SCREEN_HEIGHT;

	/* Initialize SDL
	 * Note that we only initialized SDL's video subsystem by passing
	 * the SDL_INIT_VIDEO flag. */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized! SDL_Error: "
			  << SDL_GetError() << std::endl;
	} else {
		// Get current native screen resolution
		SDL_GetCurrentDisplayMode(0, &d); // Get display mode for
						  // primary monitor
		SCREEN_WIDTH = d.w;
		SCREEN_HEIGHT = d.h;

		// Create a window
		w = SDL_CreateWindow("Lunar Lander", 0, 0, SCREEN_WIDTH,
				     SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (w == NULL) {
			std::cout << "Window could not be created! SDL_Error: n"
				  << SDL_GetError() << std::endl;
		} else {
			// Get window surface
			s = SDL_GetWindowSurface(w);

			// Main loop flag
			bool quit = false;

			// Event handler
			SDL_Event e;

			// Initialize Game
			GameHandler* gh = new GameHandler();

			// Begin time
			time_t oldT;
			time(&oldT);

			// Main loop
			while (!quit) {

				// Calculate delta
				time_t newT;
				time(&newT);
				int delta = newT - oldT;
				oldT = newT;

				// Handle events in event queue
				while (SDL_PollEvent(&e) != 0) {
					// User requests quit
					if(e.type == SDL_QUIT) {
						quit = true;
					}

					// Update player thrust if the user scrolls.
					if (e.type == SDL_MOUSEWHEEL) {
						gh->UpdateThrust(e.wheel.y, delta);
					}

					// Update player rotation/direction
					if (e.type == SDL_KEYDOWN) {
						gh->UpdateRotation(e.key.keysym, delta);
					}
				}

				// Check for collisions & update positions.
				gh->CollisionsCheck(delta);

				// Fill the surface with black as the background
				SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 0x00, 0x00, 0x00));

				// Render the next frame above the black surface
				gh->renderFrame(s);

				// Update the surface
				SDL_UpdateWindowSurface(w);
			}

			// Destroy SDL Window
			SDL_DestroyWindow(w);
		}

		// Quit SDL subsystems
		SDL_Quit();
	}
}
