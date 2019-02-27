#pragma once
#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "DeactivateOnBorderExit.h"

class Bullet : public Container {
protected:
	int power_;
	ImageGC bulletImage_;
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
public:
	Bullet();
	Bullet(SDLGame* game);
	virtual ~Bullet();

	int getPower();
	void setPower(int p);
};