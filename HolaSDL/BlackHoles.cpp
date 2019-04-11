#include "BlackHoles.h"
#include "Messages_defs.h"

BlackHoles::BlackHoles(SDLGame* game) :
	GameObjectPool(game), blackHoleImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BlackHole)), rotating_(5)
{
	for (BlackHole* blackHole : getAllObjects()) {
		blackHole->addC(&blackHoleImage_);
		blackHole->addC(&rotating_);
	}

	setId(msg::BlackHoles);
	setActive(false);
}

BlackHoles::~BlackHoles() {}

void BlackHoles::receive(const void * senderObj, const msg::Message & msg) {
	switch (msg.type_) {
	case (msg::GAME_START):
		globalSend(this, msg::BlackHolesInfo(msg::BlackHoles, msg::Broadcast, &getAllObjects()));
		break;

	case (msg::GAME_OVER):
		round = 0;
		break;

	case (msg::ROUND_START):
		RoundStart(msg);
		break;

	case (msg::ROUND_OVER):
		deactiveAllObjects();
		setActive(false);
		break;
	}
}

void BlackHoles::RoundStart(const msg::Message & msg) {
	round++;
	RandomNumberGenerator* r = getGame()->getServiceLocator()->getRandomGenerator();
	setActive(true);
	for (int i = 0; i < 2 * round; i++) {
		BlackHole* blackHole = getUnusedObject();
		blackHole->setWidth(50);
		blackHole->setHeight(50);
		int x, y;
		int lado = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
		switch (lado)
		{
		case 0: // 0 es lado izquierdo
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth() * 0.25);
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			break;
		case 1: // 1 es arriba
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight() * 0.25);
			break;
		case 2: // 2 es lado derecho
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(getGame()->getWindowWidth() * 0.75, getGame()->getWindowWidth());
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			break;
		case 3: // 3 es abajo
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(getGame()->getWindowHeight() * 0.75, getGame()->getWindowHeight());
			break;
		default:
			break;
		}

		Vector2D p = Vector2D(x, y);
		blackHole->setPosition(p);

		blackHole->setActive(true);
	}
}