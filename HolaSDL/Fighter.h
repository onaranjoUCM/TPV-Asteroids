#ifndef _AA
#define _AA

#include "BulletsShooter.h"
#include "ImageGC.h"
#include "Container.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOppositeSidePC.h"

class Fighter : public Container {
public:
	Fighter(SDLGame* game, int w, int h, Vector2D pos/*, BulletsShooter* bs*/);
	virtual ~Fighter();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

private:
	//BulletsShooter* bs_;
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	//RotationIC rotation_;
	//ThrustIC thrust_;
	//ReduceSpeedPC reduceSpeed_;
	//GunIC normalGun_;
};

#endif _AA
