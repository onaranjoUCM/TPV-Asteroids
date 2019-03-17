#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "GameManager.h"
#include "Bullet.h"

class BulletsAsteroidCollisionPC : public PhysicsComponent {
private:
	GameManager* gameManager_;
	const vector<Asteroid*>* asteroids_;
	const vector<Bullet*>* bullets_;
public:
	BulletsAsteroidCollisionPC(GameManager* gameManager);
	virtual ~BulletsAsteroidCollisionPC();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};