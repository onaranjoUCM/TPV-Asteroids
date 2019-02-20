#include "Asteroids.h"

Asteroids::Asteroids(SDLGame* game) :
		GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
		naturalMove_(), rotating_(90), showUpAtOppositeSide_() 
{
	Asteroid *a = getUnusedObject();
	a->setActive(true);

	for (Asteroid* asteroid : getAllObjects()) {
		asteroid->addOC(&(Component) asteroidImage_);
		asteroid->addOC(&(Component) naturalMove_);
		asteroid->addOC(&(Component) rotating_);
		asteroid->addOC(&(Component) showUpAtOppositeSide_);
	}
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