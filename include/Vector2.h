#ifndef VECTOR2_CPP
#define VECTOR2_CPP


class Vector2 {
	private:
		// Store x and y coordinates
		int x, y;
	public:
		Vector2(int, int);		

		// Getters and setters
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		
		// Helpful functions
		void addToX(int); // Adds integer parameter 
				  // to current x value
		void addToY(int); // Adds integer parameter
				  // to current y value
		/* NOTE: To subtract from x or y, pass  a
			 negative value into the function.
}


#endif
