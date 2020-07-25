#include "../include/Player.hpp"
#include <cmath>
#include <cstddef>

#define M_PI 3.14159265358979323846  /* pi */

Player::Player() {
	this->fuel = 1000;
	this->score = 0;
	this->lives = 3;
	this->dir = 0;
	this->thrust = 0;

	this->playerSprite[0]->setX(960); // 960 is 1/2 of our target resolution.
	this->playerSprite[0]->setY(100); // Player should spawn on-screen.

	// The following locations are relative to the center.
	this->playerSprite[1]->setX(0);
	this->playerSprite[1]->setY(-3);
	this->playerSprite[2]->setX(-5);
	this->playerSprite[2]->setY(-2);
	this->playerSprite[3]->setX(5);
	this->playerSprite[3]->setY(-2);
}

int Player::getFuel() {
	return fuel;
}

int Player::getScore() {
	return score;
}

int Player::getLives() {
	return lives;
}

int Player::getDir() {
	return dir;
}

int Player::getXVel() {
	return xVel;
}

int Player::getYVel() {
	return yVel;
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}

void Player::removeFuel(int x) {
	fuel -= x;
}

void Player::removeLife() {
	lives -= 1;
}

void Player::addToScore(int x) {
	score += x;
}

void Player::setThrust(int thrust) {
	this->thrust = thrust;
}

void Player::setVelocity(int x, int y) {
	xVel = x;
	yVel = y;
}

Vector2* Player::getVector(int pos) {
	if (pos >= 0 && pos < _PSSIZE) {
		return this->playerSprite[pos];
	} else {
		return NULL;
	}
}

void Player::setMainVector(int x, int y) {

	this->playerSprite[0]->setX(x);
	this->playerSprite[0]->setY(y);
}

Vector2* Player::rotateVectors(int deg) {
	Vector2* newPlayerSprite[_PSSIZE - 1]; // Return an array without main vector.
	for(int i = 0; i < _PSSIZE - 1; i++) { // _PSSIZE is declared in Player.hpp
		// Distance formula. i + 1 ensures we skip the main vector.
		float r = sqrt(pow(this->playerSprite[0]->getX() + this->playerSprite[i+1]->getX(), 2)
								 + pow(this->playerSprite[0]->getY() + this->playerSprite[i+1]->getY(), 2));
		newPlayerSprite[i]->setX((int) r * cos(deg * M_PI / 180.0));
		newPlayerSprite[i]->setY((int) r * sin(deg * M_PI / 180.0));
	}
}
