#include "Asteroid.h"

Asteroid::Asteroid(int w, int h, Vector2D pos, double angle) {
	setWidth(w);
	setHeight(h);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
	setRotation(angle);
}

Asteroid::~Asteroid() {}

void Asteroid::update(Uint32 time) {
	naturalMove_.update(this, 1);
	showUpAtOppositeSide_.update(this, 1);
}

void Asteroid::render(Uint32 time) {
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(), getHeight());
	asteroidImage_.render(this, 1);
}
