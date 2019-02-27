#include "Bullet.h"

Bullet::Bullet() { }

Bullet::Bullet(SDLGame* game) { }

Bullet::~Bullet() { }

int Bullet::getPower() {
	return power_;
}

void Bullet::setPower(int p) {
	power_ = p;
}