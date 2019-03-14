#include "LivesViewerGC.h"
#include "GameManager.h"

LivesViewerGC::LivesViewerGC(GameManager * gameManager) : gameManager_(gameManager) { }

LivesViewerGC::~LivesViewerGC() { }

void LivesViewerGC::render(Container* c, Uint32 time) {
	Texture msg0(c->getGame()->getRenderer(),
		"Lives: " + std::to_string(gameManager_->getLives()),
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x00000000) });
	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 2 - msg0.getWidth() / 2, c->getGame()->getWindowHeight() - 130);
}