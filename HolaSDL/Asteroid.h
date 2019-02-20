#pragma once

#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "Container.h"

class Asteroid : public Container {
protected:
	int generations_;
public:
	Asteroid();
	Asteroid(int w, int h, Vector2D pos, double angle);
	virtual ~Asteroid();

	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

	int getGenerations();
	void setGenerations(int n);

	ImageGC asteroidImage;
	NaturalMovePC naturalMove;
	RotatingPC rotating;
	ShowUpAtOppositeSidePC showUpAtOppositeSide;
};