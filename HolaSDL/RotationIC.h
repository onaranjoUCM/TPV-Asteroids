#pragma once

#include "InputComponent.h"

class RotationIC : public InputComponent {
protected:
	SDL_Keycode keyRight_;
	SDL_Keycode keyLeft_;
	int angle_;
public:
	RotationIC(SDL_Keycode keyRight, SDL_Keycode keyLeft, int angle);
	virtual ~RotationIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

