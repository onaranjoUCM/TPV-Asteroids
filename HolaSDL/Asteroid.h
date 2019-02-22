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

	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual void setComponents(Vector2D vel, Vector2D pos, double width, double height, ImageGC asteroidImage, NaturalMovePC naturalMove, RotatingPC rotating, ShowUpAtOppositeSidePC showUpAtOppositeSide);

	int getGenerations();
	void setGenerations(int n);
};