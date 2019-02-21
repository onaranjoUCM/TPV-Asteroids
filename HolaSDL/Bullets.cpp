#include "Bullets.h"

Bullets::Bullets(SDLGame * game) : 
	GameObjectPool(game), naturalMove_(), deactivate_(),
	bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect))
{ 
	for (Bullet* bullet : getAllObjects()) {
		bullet->addOC(&(Component)bulletImage_);
		bullet->addOC(&(Component)naturalMove_);
		bullet->addOC(&(Component)deactivate_);
	}
}

Bullets::~Bullets() { }

void Bullets::fireBullet() {
	Bullet *b = getUnusedObject();
	b->setActive(true);
}
