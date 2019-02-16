#pragma once
#include "SDLGame.h"
#include "Asteroid.h"

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	//Asteroids(SDLGame* game, int w, int h, Vector2D pos, double angle);
	virtual ~Asteroids();
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

protected:
	double angle;
private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

