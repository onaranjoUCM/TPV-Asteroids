#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "Bullet.h"

class BulletsAsteroidCollisionPC : public PhysicsComponent {
private:
	const vector<Asteroid*>* asteroids_;
	const vector<Bullet*>* bullets_;
public:
	BulletsAsteroidCollisionPC();
	virtual ~BulletsAsteroidCollisionPC();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};