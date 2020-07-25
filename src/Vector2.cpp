#include "../include/Vector2.hpp"

Vector2::Vector2 (int x, int y) {
	this->x = x;
	this->y = y;
}

Vector2::Vector2 (int x, int y, VectorType type) {
	this->x = x;
	this->y = y;
	this->type = type;
}

int Vector2::getX() {
	return x;
}

int Vector2::getY() {
	return y;
}

VectorType Vector2::getType() {
	return type;
}

void Vector2::addToX(int x) {
	this->x += x;
}

void Vector2::addToY(int y) {
	this->y += y;
}
