#pragma once

#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "Container.h"

class Asteroid  : public Container {
private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
public:
	Asteroid(int w, int h, Vector2D pos, double angle);
	virtual ~Asteroid();

	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};