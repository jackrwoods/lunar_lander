#include "../include/Player.hpp"

Player::Player() {
	this.fuel = 1000;
	this.score = 0;
	this.lives = 3;
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

void Player::removeFuel(int x) {
	fuel -= x;
}

void Player::removeLife() {
	lives -= 1;
}

void Player::addToScore(int x) {
	score += x;
}

Vector2* Player::getVector(int pos) {
	if (pos >= 0 && pos < _PSSIZE) {
		return playerSprite[pos];
	} else {
		return NULL;
	}	
}

void Player::setMainVector(int x, int y) {
	
	playerSprite[0].setX(x);
	playerSprite[0].setY(y);
}
