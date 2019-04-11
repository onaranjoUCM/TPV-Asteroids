#pragma once

#include "PhysicsComponent.h"
#include "BlackHole.h"
#include "Asteroid.h"
#include "Fighter.h"

class BlackHoleAsteroidCollisionPC : public PhysicsComponent {
private:
	const vector<BlackHole*>* blackHoles_;
	const vector<Asteroid*>* asteroids_;
	GameObject* fighter_;
public:
	BlackHoleAsteroidCollisionPC();
	virtual ~BlackHoleAsteroidCollisionPC();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};