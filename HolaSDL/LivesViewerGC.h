#pragma once
#include "GraphicsComponent.h"

class GameManager;

class LivesViewerGC : public GraphicsComponent {
protected:
	GameManager * gameManager_;
public:
	LivesViewerGC(GameManager * gameManager);
	virtual ~LivesViewerGC();
	virtual void render(Container* c, Uint32 time);
};