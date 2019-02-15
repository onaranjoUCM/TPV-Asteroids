#pragma once
#include "SDLGame.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"

class Asteroids { //: public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();
private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

