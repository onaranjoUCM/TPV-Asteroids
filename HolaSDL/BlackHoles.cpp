#include "BlackHoles.h"
#include "Messages_defs.h"

BlackHoles::BlackHoles(SDLGame* game) :
	GameObjectPool(game), blackHoleImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BlackHole)), rotating_(5)
{
	for (BlackHole* blackHole : getAllObjects()) {
		blackHole->addC(&blackHoleImage_);
		blackHole->addC(&rotating_);
	}

	//setId(msg::Asteroids);
	setActive(false);
}

BlackHoles::~BlackHoles() {}

void BlackHoles::receive(const void * senderObj, const msg::Message & msg) {
	switch (msg.type_) {
	case (msg::GAME_START):
		globalSend(this, msg::BlackHolesInfo(msg::BlackHoles, msg::Broadcast, &getAllObjects()));
		break;

	case (msg::GAME_OVER):
		round = 0;
		break;

	case (msg::ROUND_START):
		RoundStart(msg);
		break;

	case (msg::ROUND_OVER):
		deactiveAllObjects();
		setActive(false);
		break;

	case (msg::BULLET_ASTEROID_COLLISION):
		//BulletAsteroidCollision(msg);
		break;
	}
}

void BlackHoles::RoundStart(const msg::Message & msg) {
	round++;
	RandomNumberGenerator* r = getGame()->getServiceLocator()->getRandomGenerator();
	setActive(true);
	for (int i = 0; i < 2 * round; i++) {
		BlackHole* blackHole = getUnusedObject();
		blackHole->setWidth(50);
		blackHole->setHeight(50);
		int x, y;
		int lado = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
		switch (lado)
		{
		case 0: // 0 es lado izquierdo
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth() * 0.25);
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			break;
		case 1: // 1 es arriba
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight() * 0.25);
			break;
		case 2: // 2 es lado derecho
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(getGame()->getWindowWidth() * 0.75, getGame()->getWindowWidth());
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			break;
		case 3: // 3 es abajo
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(getGame()->getWindowHeight() * 0.75, getGame()->getWindowHeight());
			break;
		default:
			break;
		}

		Vector2D p = Vector2D(x, y);
		blackHole->setPosition(p);

		//Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
		//Vector2D v = (c - p).normalize() * (r->nextInt(1, 10) / 10.0);
		//blackHole->setVelocity(v);

		blackHole->setActive(true);
	}
}
/*
void BlackHoles::BulletAsteroidCollision(const msg::Message & msg) {
	Asteroid* X = static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_;

	int points = 4 - X->getGenerations();
	globalSend(this, msg::AsteroidDestroyed(msg::Asteroids, msg::Broadcast, points));

	if (X->getGenerations() > 1) {
		RandomNumberGenerator* r = getGame()->getServiceLocator()->getRandomGenerator();
		for (int i = 1; i <= 2; i++) {
			Asteroid* a = getUnusedObject();
			if (a != nullptr) {
				a->setWidth(X->getWidth() * 0.75);
				a->setHeight(X->getHeight() * 0.75);
				a->setGenerations(X->getGenerations() - 1);

				Vector2D v = X->getVelocity() * 1.1;
				v = v.rotate(i * 30);
				a->setVelocity(v);
				Vector2D p = X->getPosition() + v;
				a->setPosition(p);

				a->setActive(true);
				activeAsteroids++;

				Logger::getInstance()->log([p, v]() {
					stringstream s;
					s << "New asteroid: " << p << " " << v;
					return s.str();
				});
			}
		}
	}
	X->setActive(false);
	activeAsteroids--;

	if (activeAsteroids == 0) {
		globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, msg::Asteroids, msg::Broadcast));
	}

	getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, -1);
}*/