#pragma once
#include "GameObjectPool.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "GameObjectPool.h"
#include "Container.h"

class Asteroid  : public Container {
public:
	Asteroid(SDLGame* game, int w, int h, Vector2D pos);
	virtual ~Asteroid();
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};