#include "GunIC.h"

GunIC::GunIC(SDL_Keycode k) : key_(k) { }

GunIC::~GunIC(){ }

void GunIC::handleInput(Container * c, Uint32 time) {
	/* TODO
	if (event.key.keysym.sym == key_) {
		Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) +
			Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
		Vector2D d = Vector2D(0, -1).rotate(c->getRotation());

		c->globalSend(this, msg::Shoot(msg::FighterGun, msg::Broadcast, p, d, 0));
	}
	*/
}