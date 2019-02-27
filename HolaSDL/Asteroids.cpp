#include "Asteroids.h"

Asteroids::Asteroids(SDLGame* game) :
		GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(10), showUpAtOppositeSide_() 
{
	for (Asteroid* asteroid : getAllObjects()) {
		setWidth(20);
		setHeight(20);
		Vector2D vel = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5) };
		Vector2D pos = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth()),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowHeight()) };

		asteroid->setComponents(vel, pos, getWidth(), getHeight(), asteroidImage_, naturalMove_, rotating_, showUpAtOppositeSide_);
	}

	getUnusedObject()->setActive(true);
	getUnusedObject()->setActive(true);
}

Asteroids::~Asteroids() {}

void Asteroids::update(Uint32 time) {
	
	vector<Asteroid*> asteroids = getAllObjects();
	for (int i = 0; i < asteroids.size(); i++) {
		if (asteroids[i]->isActive()) {
			asteroids[i]->update(time);
		}
	}
}

void Asteroids::render(Uint32 time) {
	vector<Asteroid*> asteroids = getAllObjects();
	for (int i = 0; i < asteroids.size(); i++)
		if (asteroids[i]->isActive())
			asteroids[i]->render(time);
}