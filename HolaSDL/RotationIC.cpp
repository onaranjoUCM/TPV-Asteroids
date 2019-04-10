#include "RotationIC.h"
#include "InputHandler.h"

RotationIC::RotationIC(SDL_Keycode kr, SDL_Keycode kl, int a) : 
	keyRight_(kr), keyLeft_(kl), angle_(a) { }

RotationIC::~RotationIC() { }

void RotationIC::handleInput(Container * c, Uint32 time) {
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(keyRight_)) {
			c->setRotation(((int)c->getRotation() + angle_) % 360);
		}
		else if (InputHandler::getInstance()->isKeyDown(keyLeft_)) {
			c->setRotation(((int)c->getRotation() + 360 - angle_) % 360);
		}
	}
}