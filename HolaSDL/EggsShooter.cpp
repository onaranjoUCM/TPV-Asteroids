#include "EggsShooter.h"

EggsShooter::EggsShooter(SDLGame* game) : ObjectPoll(game) {

}

EggsShooter::~EggsShooter() {
}

void EggsShooter::addEgg(Vector2D pos, Vector2D vel, Vector2D acc) {
	ObjectPoll::addItem(pos, vel, acc);
}