#include "Asteroid.h"

Asteroid::Asteroid() { }

Asteroid::Asteroid(SDLGame* game) { }

Asteroid::~Asteroid() {}

int Asteroid::getGenerations() {
	return generations_;
}

void Asteroid::setGenerations(int n) {
	generations_ = n;
}
