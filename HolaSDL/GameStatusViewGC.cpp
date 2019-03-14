#include "GameStatusViewGC.h"
#include "GameManager.h"

GameStatusViewGC::GameStatusViewGC(GameManager * gameManager) : gameManager_(gameManager) { }

GameStatusViewGC::~GameStatusViewGC() { }

void GameStatusViewGC::render(Container* c, Uint32 time) {
	string msg, winnerMsg;

	if (!gameManager_->isRunning()) {
		if (gameManager_->isGameOver()) {
			msg = "Press ENTER to Start a new game";
			if (gameManager_->getWinner() == 0) { winnerMsg = "GAME OVER (Winner: None)"; } 
			else if (gameManager_->getWinner() == 1) { winnerMsg = "GAME OVER (Winner: Asteroids)"; } 
			else if (gameManager_->getWinner() == 2) { winnerMsg = "GAME OVER (Winner: Fighter)"; }

			Texture msg1(c->getGame()->getRenderer(), winnerMsg,
				*(c->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x00000000) });
			msg1.render(c->getGame()->getRenderer(),
				c->getGame()->getWindowWidth() / 2 - msg1.getWidth() / 2, c->getGame()->getWindowHeight() - 420);
		} else {
			msg = "Press ENTER to continue";
		}

		Texture msg0(c->getGame()->getRenderer(), msg,
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x00000000) });
		msg0.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg0.getWidth() / 2, c->getGame()->getWindowHeight() - 400);
	}
}