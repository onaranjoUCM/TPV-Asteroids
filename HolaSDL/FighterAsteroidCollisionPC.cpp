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
				c->globalSend(this, msg::FighterAsteroidCollisionMsg(msg::None, msg::Broadcast, fighter_, asteroid));
			} else {
				break;
			}
		}
	}*/
}

void FighterAsteroidCollisionPC::receive(Container * c, const msg::Message & msg) {
	const std::vector<Asteroid*>* asteroids;
	switch (msg.type_) {
	case (msg::ASTEROIDS_INFO):
		asteroids = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		// TODO: Preguntar
		break;
	case (msg::FIGHTER_INFO):
		GameObject* fighter = static_cast<const msg::FighterInfo&>(msg).fighter_;
		// TODO: Preguntar
		break;
	}
}