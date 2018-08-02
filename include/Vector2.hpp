#ifndef VECTOR2_HPP
#define VECTOR2_HPP


class Vector2 {
	private:
		// Store x and y coordinates
		int x, y;
		int type;
	public:
		Vector2(int, int);

		// Getters and setters
		int getX();
		int getY();
		void setX(int);
		void setY(int);

		// Returns type
		int getType();

		// Helpful functions
		void addToX(int); // Adds integer parameter
				  // to current x value
		void addToY(int); // Adds integer parameter
				  // to current y value
		/* NOTE: To subtract from x or y, pass  a
			 negative value into the function.*/
};


#endif
