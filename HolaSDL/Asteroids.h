#pragma once
#include "GameObjectPool.h"
#include "Asteroid.h"
#include <vector>

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();

private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

