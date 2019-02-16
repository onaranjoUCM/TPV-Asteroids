#include "Asteroids.h"



Asteroids::Asteroids(SDLGame* game, double a) : /*GameObjectPool(game),*/ angle(a), asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(), rotating_(a), showUpAtOppositeSide_() {}

Asteroids::~Asteroids() {

}
