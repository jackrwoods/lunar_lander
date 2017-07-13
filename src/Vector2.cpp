#include "../include/Vector2.h"

Vector2::Vector2 (int x, int y) {
	this.x = x;
	this.y = y;
}

int Vector2::getX() {
	return x;
}

int Vector2::getY() {
	return y;
}

void Vector2::addToX(int x) {
	this.x += x;
}

void Vector2::addToX(int y) {
	this.y += y;
}
