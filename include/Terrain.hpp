#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include "LinkedList.h"

class Terrain {
	private:
		LinkedList* vectors;
	public:
		Terrain(int); // Pass in terrain size
		void _generateTerrain(int);
}

#endif
