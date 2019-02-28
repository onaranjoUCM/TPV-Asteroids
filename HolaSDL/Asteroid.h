#pragma once

#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "Container.h"

class Asteroid : public Container {
protected:
	int generations_;
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
public:
	Asteroid();
	Asteroid(SDLGame* game);
	virtual ~Asteroid();

	int getGenerations();
	void setGenerations(int n);
};