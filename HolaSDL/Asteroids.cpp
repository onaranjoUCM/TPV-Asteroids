#include "Asteroids.h"
#include "Messages_defs.h"
#include "Logger.h"
#include <sstream>

Asteroids::Asteroids(SDLGame* game) :
		GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(10), showUpAtOppositeSide_() 
{
	for (Asteroid* asteroid : getAllObjects()) {
		asteroid->setGenerations(3);
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
	switch (msg.type_) {
	case (msg::GAME_START):
		globalSend(this, msg::AsteroidsInfo(msg::Asteroids, msg::Broadcast, &getAllObjects()));
		break;

	case (msg::ROUND_START):
		RoundStart(msg);
		break;

	case (msg::ROUND_OVER):
		deactiveAllObjects();
		activeAsteroids = 0;
		setActive(false);
		break;

	case (msg::BULLET_ASTEROID_COLLISION):
		BulletAsteroidCollision(msg);
		break;

	case (msg::BLACKHOLE_ASTEROID_COLLISION):
		BlackHoleAsteroidCollision(msg);
		break;
	}
}

void Asteroids::RoundStart(const msg::Message & msg) {
	RandomNumberGenerator* r = getGame()->getServiceLocator()->getRandomGenerator();
	setActive(true);
	for (int i = 0; i < 10; i++) {
		Asteroid* a = getUnusedObject();
		a->setWidth(20);
		a->setHeight(20);
		a->setGenerations(3);

		int x, y;
		int lado = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
		switch (lado)
		{
		case 0: // 0 es lado izquierdo
			x = 0;
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			break;
		case 1: // 1 es arriba
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth());
			y = 0;
			break;
		case 2: // 2 es abajo
			x = getGame()->getWindowWidth();
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			break;
		case 3: // 3 es lado derecho
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth());
			y = getGame()->getWindowHeight();
			break;
		default:
			break;
		}

		Vector2D p = Vector2D(x, y);
		a->setPosition(p);

		Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
		Vector2D v = (c - p).normalize() * (r->nextInt(1, 10) / 10.0);
		a->setVelocity(v);

		a->setActive(true);
		activeAsteroids++;
	}
}

void Asteroids::BulletAsteroidCollision(const msg::Message & msg) {
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
}

void Asteroids::BlackHoleAsteroidCollision(const msg::Message & msg) {
	Asteroid* asteroid = static_cast<const msg::BlackHoleAsteroidCollision&>(msg).asteroid_;
	GameObject* fighter = static_cast<const msg::BlackHoleAsteroidCollision&>(msg).fighter_;

	int x, y;
	do {
		x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth());
		y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
	} while (
		abs(fighter->getPosition().getX() - x) < 100 ||
		abs(fighter->getPosition().getY() - y) < 100
	);

	Vector2D p = Vector2D(x, y);
	asteroid->setPosition(p);
}
