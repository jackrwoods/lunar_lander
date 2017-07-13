#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Vector2.h"


class Player {
	private:
		int fuel, score, lives;
	public:
		Player();
		
		// Getters and setters
		int getFuel();
		int getScore();
		int getLives();

		// Manipulators
		void removeFuel(int); // Pass in the amount
				      // of fuel to use.
		void removeLife();    // Remove 1 life.
		void addToScore(int); // Add parameter to
				      // to score.
}


#endif
