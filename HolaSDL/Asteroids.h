#pragma once
#include "GameObjectPool.h"
#include "Asteroid.h"
#include <vector>

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();

	virtual void receive(const void* senderObj, const msg::Message& msg);

private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

