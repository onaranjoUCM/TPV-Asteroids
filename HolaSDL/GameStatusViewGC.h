#pragma once
#include "GraphicsComponent.h"

class GameManager;

class GameStatusViewGC : public GraphicsComponent {
protected:
	GameManager * gameManager_;
public:
	GameStatusViewGC(GameManager * gameManager);
	virtual ~GameStatusViewGC();
	virtual void render(Container* c, Uint32 time);
};