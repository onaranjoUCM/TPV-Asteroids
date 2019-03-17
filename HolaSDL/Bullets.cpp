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

		// TODO: Pendiente de testeo tras arreglar BulletAsteroidCollisionPC
	case (msg::BULLET_ASTEROID_COLLISION):
		/*Bullet* b = static_cast<const msg::BulletAsteroidCollision&>(msg).bullet_;
		b->setActive(false);*/

		// TODO: Reproducir sonido de explosion
		break;

	case (msg::FIGHTER_SHOOT):
		for (int i = 0; i < 10; i++) {
			Bullet* b = getUnusedObject();
			b->setWidth(5);
			b->setHeight(15);

			Vector2D p = Vector2D(0, 0); // Tiene que recivir las coordenadas de la nave
			b->setPosition(p);

			Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
			Vector2D v = (c - p).normalize() * (r->nextInt(1, 10) / 10.0);
			b->setVelocity(v);

			b->setActive(true);
		}
		break;
	}
}

void Bullets::fireBullet() {
	Bullet *b = getUnusedObject();
	b->setWidth(2);
	b->setHeight(10);
	b->setPosition({ 400, 300 });
	b->setVelocity({ 0, -10 });
	b->setActive(true);
}
