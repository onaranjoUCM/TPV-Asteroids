#pragma once
#include "GameObjectPool.h"
#include "Asteroid.h"
#include <vector>

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

protected:

private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOpposideSide_;
};

