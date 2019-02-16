#pragma once
#include "SDLGame.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "GameObjectPool.h"
#include "Asteroid.h"

class Asteroids {//: public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game, double angle);
	virtual ~Asteroids();

protected:
	double angle;
private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

