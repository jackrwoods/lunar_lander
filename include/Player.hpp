#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Vector2.hpp"

// Size of the playerSprite array.
#define _PSSIZE 4

class Player {
	private:
		int fuel, score, lives, dir;
		// Each vector (with the exception of the
		// main vector) contains its position
		// relative to the main vector.
		Vector2* playerSprite[_PSSIZE];

	public:
		Player();

		// Getters and setters
		int getFuel();
		int getScore();
		int getLives();
		Vector2* getVector(int); // Return vector at
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
		Vector2* rotateVectors(int); // Return rotated
							// player vectors.
}


#endif
