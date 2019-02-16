#include "Asteroids.h"



/*Asteroids::Asteroids(SDLGame* game, int w, int h, Vector2D pos, double a) : Container(game, w, h, pos), 	angle(a), 
	asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(a), showUpAtOppositeSide_() {
	//Vacio
}*/

Asteroids::~Asteroids() {}

void Asteroids::update(Uint32 time) {
	naturalMove_.update(this, 1);
	showUpAtOppositeSide_.update(this, 1);
}

void Asteroids::render(Uint32 time) {
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(), getHeight());
	asteroidImage_.render(this, 1);
}