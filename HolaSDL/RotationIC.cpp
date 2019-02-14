#include "RotationIC.h"

RotationIC::RotationIC(SDL_Keycode kr, SDL_Keycode kl, int a) : 
	keyRight_(kr), keyLeft_(kl), angle_(a) { }

RotationIC::~RotationIC() { }

void RotationIC::handleInput(Container * c, Uint32 time, const SDL_Event & event) {
	if (event.key.keysym.sym == keyRight_) {
		c->setRotation(((int)c->getRotation() + angle_) % 360);
	}
	else if (event.key.keysym.sym == keyLeft_) {
		c->setRotation(((int)c->getRotation() + 360 - angle_) % 360);
	}
}