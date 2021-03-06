#include "ThrustIC.h"
#include "InputHandler.h"

ThrustIC::ThrustIC(SDL_Keycode k, float t, float sl) :
	key_(k), thrust_(t), speedLimit_(sl) { }

ThrustIC::~ThrustIC() { }

void ThrustIC::handleInput(Container * c, Uint32 time) {
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(key_)) {
			if (c->getVelocity().magnitude() < speedLimit_) {
				c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation()) * thrust_));
			}
			else {
				c->setVelocity(c->getVelocity().normalize() * speedLimit_);
			}
		}
	}
}
