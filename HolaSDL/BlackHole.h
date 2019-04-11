#pragma once

#include "ImageGC.h"
#include "RotatingPC.h"
#include "Container.h"

class BlackHole : public Container {
public:
	BlackHole();
	BlackHole(SDLGame* game);
	virtual ~BlackHole();
};