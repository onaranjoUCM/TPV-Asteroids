#include "Fighter.h"

Fighter::Fighter(SDLGame* game, int w, int h, Vector2D pos) : Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes),
	{ 47, 90, 207, 250 }), rotation_(SDLK_RIGHT, SDLK_LEFT, 5), 
	thrust_(SDLK_UP, 0.5, 2.0), reduceSpeed_(0.995), normalGun_(SDLK_SPACE)
{
	setId(msg::Fighter);

	setWidth(w);
	setHeight(h);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
	setRotation(90);
	setActive(false);
}

Fighter::~Fighter() { }

void Fighter::handleInput(Uint32 time) {
	/* TODO
	if (event.type == SDL_KEYDOWN) {
		rotation_.handleInput(this, 1, event);
		thrust_.handleInput(this, 1, event);
		normalGun_.handleInput(this, 1, event);
	}
	*/
}

void Fighter::update(Uint32 time) {
	naturalMove_.update(this, 1);
	oppositeSide_.update(this, 1);
	reduceSpeed_.update(this, 1);
}

void Fighter::render(Uint32 time) {
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(), getHeight());
	fighterImage_.render(this, 1);
}

void Fighter::receive(const void * senderObj, const msg::Message & msg) {
	Container::receive(senderObj, msg);
	switch (msg.type_) {
	case (msg::GAME_START):
		globalSend(this, msg::FighterInfo(msg::Fighter, msg::Broadcast, this));
		break;
	case (msg::ROUND_START):
		setPosition({ 400, 300 });
		setVelocity(Vector2D(0, 0));
		setRotation(90);
		setActive(true);
		break;
	case (msg::ROUND_OVER):
		setActive(false);
		break;
	}
}
