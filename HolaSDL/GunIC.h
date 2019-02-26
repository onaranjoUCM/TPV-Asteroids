#pragma once

#include "InputComponent.h"
#include "Bullet.h"
#include "Messages_defs.h"

class GunIC : public InputComponent {
protected:
	SDL_Keycode key_;
public:
	GunIC(SDL_Keycode key);
	virtual ~GunIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};