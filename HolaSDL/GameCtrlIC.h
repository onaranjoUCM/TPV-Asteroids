#pragma once
#include "InputComponent.h"
#include "Messages_defs.h"

class GameManager;

class GameCtrlIC : public InputComponent {
protected:
	GameManager * gameManager_;
public:
	GameCtrlIC(GameManager * gameManager);
	virtual ~GameCtrlIC();
	virtual void handleInput(Container* c, Uint32 time);
};