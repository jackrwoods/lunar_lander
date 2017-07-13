#include "../include/Player.h"

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

void addToScore(int x) {
	score += x;
}