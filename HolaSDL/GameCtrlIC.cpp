#include "GameCtrlIC.h"
#include "GameManager.h"
#include "InputHandler.h"

GameCtrlIC::GameCtrlIC(GameManager* gameManager) : gameManager_(gameManager) {}

GameCtrlIC::~GameCtrlIC() {}

void GameCtrlIC::handleInput(Container* c, Uint32 time) {
	GameManager* gm = static_cast<GameManager*>(c);

	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(SDLK_RETURN) && !gm->isRunning()) {
			if (gameManager_->getLives() == gameManager_->getMaxLives() ||
			gameManager_->getWinner() != 0) {
				c->globalSend(this, msg::Message(msg::GAME_START, msg::None, msg::Broadcast));
			}
			c->globalSend(this, msg::Message(msg::ROUND_START, msg::None, msg::Broadcast));
		}
	}
}
