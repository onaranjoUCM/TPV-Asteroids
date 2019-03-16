#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "GameManager.h"

class FighterAsteroidCollisionPC : public PhysicsComponent {
private:
	GameManager* gameManager_;
	GameObject* fighter_ = nullptr;
	const vector<Asteroid*>* asteroids_ = nullptr;
public:
	FighterAsteroidCollisionPC(GameManager* gameManager);
	virtual ~FighterAsteroidCollisionPC();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};