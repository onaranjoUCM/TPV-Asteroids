#include "GameCtrlIC.h"
#include "GameManager.h"

GameCtrlIC::GameCtrlIC(GameManager * gameManager) : gameManager_(gameManager) { }

GameCtrlIC::~GameCtrlIC() { }

void GameCtrlIC::handleInput(Container * c, Uint32 time, const SDL_Event & event) {
	if (event.key.keysym.sym == SDLK_RETURN && !gameManager_->isRunning()) {
		if (gameManager_->getLives() == gameManager_->getMaxLives() ||
			gameManager_->getLives() == 0) {
			c->globalSend(this, msg::Message(msg::GAME_START, msg::None, msg::Broadcast));
		}
		c->globalSend(this, msg::Message(msg::ROUND_START, msg::None, msg::Broadcast));
	}
}