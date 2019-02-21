#pragma once
#include "Container.h"

class Bullet : public Container {
protected:
	int power_;
public:
	Bullet();
	Bullet(SDLGame* game);
	virtual ~Bullet();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

	int getPower();
	void setPower(int p);
};