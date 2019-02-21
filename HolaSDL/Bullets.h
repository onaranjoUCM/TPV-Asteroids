#pragma once
#include "GameObjectPool.h"
#include "Bullet.h"
#include "NaturalMovePC.h"
#include "DeactivateOnBorderExit.h"
#include "ImageGC.h"

class Bullets : public GameObjectPool<Bullet, 10> {
private:
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;
public:
	Bullets(SDLGame* game);
	virtual ~Bullets();

	void fireBullet();
};