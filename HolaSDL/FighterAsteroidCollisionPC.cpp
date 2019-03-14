#include "FighterAsteroidCollisionPC.h"
#include "Collisions.h"

FighterAsteroidCollisionPC::FighterAsteroidCollisionPC(GameManager* gameManager) : 
gameManager_(gameManager) { }

FighterAsteroidCollisionPC::~FighterAsteroidCollisionPC() { }

void FighterAsteroidCollisionPC::update(Container * c, Uint32 time) {
	/*
	if (fighter_ != nullptr && asteroids_ != nullptr) {
		for (int i = 0; i < asteroids_->size; i++) {
			Asteroid* asteroid = asteroids_->at(i);
			if (
				gameManager_->isRunning() &&
				fighter_->isActive() &&
				asteroids_->at(i)->isActive() &&
				Collisions::collidesWithRotation(fighter_, asteroid))
			{
				cout << "ads";
				msg::FighterAsteroidCollisionMsg(msg::None, msg::Broadcast, fighter_, asteroid);
			} else {
				break;
			}
		}
	}*/
}
