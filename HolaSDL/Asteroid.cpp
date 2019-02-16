#include "Asteroid.h"

Asteroid::Asteroid(SDLGame * game, int w, int h, Vector2D pos) : Container(game) {
	setWidth(w);
	setHeight(h);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
	setRotation(90);
}

Asteroid::~Asteroid() {}

void Asteroid::update(Uint32 time) {}

void Asteroid::render(Uint32 time) {}
