#include "Asteroids.h"

Asteroids::Asteroids(SDLGame* game) :
		GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(10), showUpAtOppositeSide_() 
{
	for (Asteroid* asteroid : getAllObjects()) {		
		/*asteroid->addOC(&(Component) asteroidImage_);		asteroid->addOC(&(Component) naturalMove_); asteroid->addOC(&(Component) rotating_);		asteroid->addOC(&(Component) showUpAtOppositeSide_);*/	
		asteroid->setActive(true);
		setWidth(20);
		setHeight(20);
		Vector2D vel = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5) };
		setVelocity(vel);
		Vector2D pos = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth()),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowHeight()) };
		setPosition(pos);
		asteroid->setComponents(getVelocity(), getPosition(), getWidth(), getHeight(), asteroidImage_, naturalMove_, rotating_, showUpAtOppositeSide_);
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