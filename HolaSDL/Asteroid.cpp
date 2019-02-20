#include "Asteroid.h"

Asteroid::Asteroid() { }

Asteroid::Asteroid(int w, int h, Vector2D pos, double angle) {
	setWidth(w);
	setHeight(h);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
	setRotation(angle);
}

Asteroid::~Asteroid() {}

void Asteroid::update(Uint32 time) {
	naturalMove.update(this, 1);
	showUpAtOppositeSide.update(this, 1);
}

void Asteroid::render(Uint32 time) {
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(), getHeight());
	asteroidImage.render(this, 1);
}

int Asteroid::getGenerations() {
	return generations_;
}

void Asteroid::setGenerations(int n) {
	generations_ = n;
}
