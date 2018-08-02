#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include "LinkedList.hpp"

class Terrain {
	private:
		LinkedList* vectors;
	public:
		Terrain(int); // Pass in terrain size

		void _generateTerrain(int);

		LinkedList* getVectors();
};

#endif
