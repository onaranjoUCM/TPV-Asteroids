#include "Asteroids.h"
#include "Messages_defs.h"

Asteroids::Asteroids(SDLGame* game) :
		GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(10), showUpAtOppositeSide_() 
{
	for (Asteroid* asteroid : getAllObjects()) {
		asteroid->addC(&asteroidImage_);
		asteroid->addC(&naturalMove_);
		asteroid->addC(&rotating_);
		asteroid->addC(&showUpAtOppositeSide_);
	}

	setId(msg::Asteroids);
	setActive(false);
}

Asteroids::~Asteroids() {}

void Asteroids::receive(const void * senderObj, const msg::Message & msg) {
	RandomNumberGenerator* r = getGame()->getServiceLocator()->getRandomGenerator();
	switch (msg.type_) {
	case (msg::GAME_START):
		globalSend(this, msg::AsteroidsInfo(msg::Asteroids, msg::Broadcast, &getAllObjects()));
		break;

	case (msg::ROUND_START):
		setActive(true);
		for (int i = 0; i < 10; i++) {
			Asteroid* a = getUnusedObject();
			a->setWidth(20);
			a->setHeight(20);

			Vector2D p = Vector2D((double)r->nextInt(0, getGame()->getWindowWidth()), (double)r->nextInt(0, getGame()->getWindowHeight()));
			a->setPosition(p);

			Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
			Vector2D v = (c - p).normalize() * (r->nextInt(1, 10) / 10.0);
			a->setVelocity(v);

			a->setActive(true);
		}
		break;

	case (msg::ROUND_OVER):
		deactiveAllObjects();
		setActive(false);
		break;

	// TODO: Pendiente de testeo tras arreglar BulletAsteroidCollisionPC
	case (msg::BULLET_ASTEROID_COLLISION):
		Asteroid* X = static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_;
		X->setActive(false);

		int points = 4 - X->getGenerations();
		globalSend(this, msg::AsteroidDestroyed(msg::Asteroids, msg::Broadcast, points));

		if (X->getGenerations() > 1) {
			RandomNumberGenerator* r = getGame()->getServiceLocator()->getRandomGenerator();
			for (int i = 0; i < 2; i++) {
				Asteroid* a = getUnusedObject();
				a->setWidth(X->getWidth() * 0.75);
				a->setHeight(X->getHeight() * 0.75);
				a->setGenerations(X->getGenerations() - 1);

				Vector2D v = X->getVelocity() * 1.1;
				// TODO: Girar vector en i*30 grados
				a->setVelocity(v);

				a->setPosition(X->getPosition() + v);

				a->setActive(true);
			}
		}

		int remainingAsteroids = 0;
		for (Asteroid* a : getAllObjects()) {
			if (a->isActive()) { remainingAsteroids++; }
		}
		if (remainingAsteroids == 0) {
			globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, msg::Asteroids, msg::Broadcast));
		}

		// TODO: Reproducir sonido de explosion
		break;
	}
}