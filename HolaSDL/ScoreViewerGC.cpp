#include "ScoreViewerGC.h"
#include "GameManager.h"

ScoreViewerGC::ScoreViewerGC(GameManager * gameManager) : gameManager_(gameManager) { }

ScoreViewerGC::~ScoreViewerGC() { }

void ScoreViewerGC::render(Container* c, Uint32 time) {
	Texture msg0(c->getGame()->getRenderer(),
		"Score: " + std::to_string(gameManager_->getScore()),
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x00000000) });
	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 2 - msg0.getWidth() / 2, c->getGame()->getWindowHeight() - 150);
}