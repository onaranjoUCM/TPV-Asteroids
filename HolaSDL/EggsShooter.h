#pragma once

#include "ObjectPoll.h"
#include "Egg.h"

class EggsShooter: public ObjectPoll<Egg, 20> {
public:
	EggsShooter(SDLGame* game);
	virtual ~EggsShooter();

	virtual void addEgg(Vector2D pos, Vector2D vel, Vector2D acc);
private:

};

