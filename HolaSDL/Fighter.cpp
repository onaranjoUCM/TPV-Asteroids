#include "Fighter.h"

Fighter::Fighter(SDLGame* game, int w, int h, Vector2D pos) : Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes),
	{ 47, 90, 207, 250 }), rotation_(SDLK_RIGHT, SDLK_LEFT, 5), thrust_(SDLK_UP, 0.5, 2.0)
{
	setWidth(w);
	setHeight(h);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
	setRotation(90);
}

Fighter::~Fighter() { }

void Fighter::handleInput(Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		rotation_.handleInput(this, 1, event);
		thrust_.handleInput(this, 1, event);
		switch (event.key.keysym.sym) {
		case SDLK_DOWN:
			// decrease velocity
			velocity_ = velocity_ * 0.9;
			break;
		/*case SDLK_SPACE: {
			Vector2D bulletPosition = getPosition()
					+ Vector2D(getWidth() / 2, getHeight() / 2)
					+ Vector2D(0, -1).rotate(getRotation())*(getHeight() /2+10);
			Vector2D bulletVelocity = getVelocity()
					+ Vector2D(0, -1).rotate(getRotation()).normalize() * 3;
			//bs_->addBullet(bulletPosition, bulletVelocity);
			break;
		}*/
		default:
			break;
		}
	}
}

void Fighter::update(Uint32 time) {
	naturalMove_.update(this, 1);
	oppositeSide_.update(this, 1);
}

void Fighter::render(Uint32 time) {
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(), getHeight());
	fighterImage_.render(this, 1);
}
