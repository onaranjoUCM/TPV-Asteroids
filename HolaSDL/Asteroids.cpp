#include "Asteroids.h"

/*Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(), rotating_(90), showUpAtOpposideSide_() {
	
}*/

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