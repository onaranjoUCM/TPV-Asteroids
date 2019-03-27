#pragma once

#include "InputComponent.h"

class ThrustIC : public InputComponent {
protected:
	SDL_Keycode key_;
	float thrust_;
	float speedLimit_;
public:
	ThrustIC(SDL_Keycode key, float thrust, float speedLimit);
	virtual ~ThrustIC();
	virtual void handleInput(Container* c, Uint32 time);
};

