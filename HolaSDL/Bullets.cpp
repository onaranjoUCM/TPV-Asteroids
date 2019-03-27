#include "Bullets.h"
#include "Messages_defs.h"

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

void Bullets::receive(const void * senderObj, const msg::Message & msg) {
	RandomNumberGenerator* r = getGame()->getServiceLocator()->getRandomGenerator();
	Bullet* b;
	switch (msg.type_) {
	case (msg::GAME_START):
		globalSend(this, msg::BulletsInfoMsg(msg::BulletsShooter, msg::Broadcast, &getAllObjects()));
		break;

	case (msg::ROUND_START):
		setActive(true);
		break;

	case (msg::ROUND_OVER):
		deactiveAllObjects();
		setActive(false);
		break;

	case (msg::BULLET_ASTEROID_COLLISION):
		b = static_cast<const msg::BulletAsteroidCollision&>(msg).bullet_;
		b->setActive(false);

		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, -1);
		break;

	case (msg::FIGHTER_SHOOT):
		b = getUnusedObject();
		if (b != nullptr) {
			b->setWidth(1);
			b->setHeight(5);

			Vector2D p = static_cast<const msg::Shoot&>(msg).pos_;
			b->setPosition(p - Vector2D(width_ / 2, height_));

			Vector2D d = static_cast<const msg::Shoot&>(msg).dir_;
			b->setVelocity(d * 5);

			b->setRotation(Vector2D(0, -1).angle(d));

			b->setActive(true);

			getGame()->getServiceLocator()->getAudios()->playChannel(Resources::GunShot, 0, -1);
		}
		break;
	}
}