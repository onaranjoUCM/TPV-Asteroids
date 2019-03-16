#include "Bullets.h"

Bullets::Bullets(SDLGame * game) : 
	GameObjectPool(game), naturalMove_(), deactivate_(),
	bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect))
{
	setId(msg::BulletsShooter);

	for (Bullet* bullet : getAllObjects()) {
		bullet->addC(&bulletImage_);
		bullet->addC(&naturalMove_);
		bullet->addC(&deactivate_);
	}
	setActive(false);
}

Bullets::~Bullets() { }

void Bullets::fireBullet() {
	Bullet *b = getUnusedObject();
	b->setWidth(2);
	b->setHeight(10);
	b->setPosition({ 400, 300 });
	b->setVelocity({ 0, -10 });
	b->setActive(true);
}
