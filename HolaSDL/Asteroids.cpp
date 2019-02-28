#include "Asteroids.h"

Asteroids::Asteroids(SDLGame* game) :
		GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(10), showUpAtOppositeSide_() 
{
	Asteroid* a = getUnusedObject();
	a->setWidth(20);
	a->setHeight(20);
	a->setPosition({ (double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth()),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowHeight()) });
	a->setVelocity({ (double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5) });

	for (Asteroid* asteroid : getAllObjects()) {
		asteroid->addC(&asteroidImage_);
		asteroid->addC(&naturalMove_);
		asteroid->addC(&rotating_);
		asteroid->addC(&showUpAtOppositeSide_);
	}

	a->setActive(true);

	//getUnusedObject()->setActive(true);
	//getUnusedObject()->setActive(true);
}

Asteroids::~Asteroids() {}