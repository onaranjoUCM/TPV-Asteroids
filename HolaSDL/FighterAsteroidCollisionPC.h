#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"

class FighterAsteroidCollisionPC : public PhysicsComponent {
private:
	GameObject* fighter_ = nullptr;
	const vector<Asteroid*>* asteroids_ = nullptr;
public:
	FighterAsteroidCollisionPC();
	virtual ~FighterAsteroidCollisionPC();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};