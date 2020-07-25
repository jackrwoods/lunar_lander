#include "../include/Terrain.hpp"
#include "../include/Vector2.hpp"
#include <cstdlib>
#include <time.h>

Terrain::Terrain(int size) {
	_generateTerrain(size);
}


void Terrain::_generateTerrain(int size) {
	/* Generate random terrain by calculating heights for each
	 * x location, then randomly replace vector pairs with 3 to
	 * 5 pairs of PlatformVectors.
	 * For more info, please reference doc/tAlg.txt.
	 */
	srand(time(NULL)); //Seed rand
	vectors = newLinkedList(); // Create new LL for terrain vectors

	// Calculate heights using averages
	for (int i = 0; i < size; i++) {
		int height = 0;
		for (int j = 0; j < 5; j++) {
			height += rand() % 50 + 540;
		}
		height /= 5; // height is the average of 5 rand() calls for terrain smoothing

		// 1920X1080 is the target resolution. Anything rendered is scaled from that.
		addLinkedList(vectors, new Vector2(1920/size, height, VectorType::TERRAIN)); // Equallly spaced-out vectors
	}

	// Overwrite TerrainVectors with PlatformVectors
	int numOfPlatforms = rand() % 3 + 5;
	for (int i = 0; i < numOfPlatforms; i++) {
		// Iterate through LL with current until the randomly generated location is found.
		do {
			int loc = rand() % 1 + size;
			for (int j = 0; j <= loc; j++) {
				vectors->current = vectors->current->next;
			}
		} while (vectors->current->data->getType() != VectorType::PLATFORM); // Ensure current is not a platform.

		// Get x and y for new vectors
		int y = vectors->current->data->getY();
		int x1 = vectors->current->data->getX();
		int x2 = vectors->current->data->getY();

		// Delete old vectors
		delete (vectors->current->data);
		delete (vectors->current->next->data);

		// Create two new PlatformVectors
		vectors->current->data = new Vector2(x1, y, VectorType::PLATFORM);
		vectors->current->next->data = new Vector2(x2, y, VectorType::PLATFORM);
	}
}

LinkedList* Terrain::getVectors() {
	return vectors;
}
