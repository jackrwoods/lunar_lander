#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Vector2.h"


class Player {
	private:
		int fuel, score, lives;
		Vector2 playerSprite[4];
	public:
		Player();
		
		// Getters and setters
		int getFuel();
		int getScore();
		int getLives();
		void getVector(int); // Return vector at
				     // specified location
				     // in the array
		// Modify the location of the main vector.
		int setMainVector(int, int);

		// Manipulators
		void removeFuel(int); // Pass in the amount
				      // of fuel to use.
		void removeLife();    // Remove 1 life.
		void addToScore(int); // Add parameter to
				      // to score.
}


#endif
