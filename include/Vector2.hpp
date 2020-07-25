#ifndef VECTOR2_HPP
#define VECTOR2_HPP

enum VectorType { TERRAIN, PLATFORM };

class Vector2 {
	private:
		// Store x and y coordinates
		int x, y;
		VectorType type;
	public:
		Vector2(int, int);
		Vector2(int, int, VectorType);

		// Getters and setters
		int getX();
		int getY();
		void setX(int);
		void setY(int);

		// Returns type
		VectorType getType();

		// Helpful functions
		void addToX(int); // Adds integer parameter
				  // to current x value
		void addToY(int); // Adds integer parameter
				  // to current y value
		/* NOTE: To subtract from x or y, pass  a
			 negative value into the function.*/
};


#endif
