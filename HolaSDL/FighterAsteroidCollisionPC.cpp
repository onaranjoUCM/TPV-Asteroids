#include "FighterAsteroidCollisionPC.h"
#include "Collisions.h"
#include "Messages_defs.h"
#include "GameManager.h"

FighterAsteroidCollisionPC::FighterAsteroidCollisionPC() { }

FighterAsteroidCollisionPC::~FighterAsteroidCollisionPC() { }

void FighterAsteroidCollisionPC::update(Container * c, Uint32 time) {
	if (fighter_ != nullptr && asteroids_ != nullptr) {
		if (static_cast<GameManager*>(c)->isRunning()) {
			for (int i = 0; i < asteroids_->size(); i++) {
				Asteroid* asteroid = asteroids_->at(i);
				if (
					fighter_->isActive() &&
					asteroids_->at(i)->isActive() &&
					Collisions::collidesWithRotation(fighter_, asteroid))
				{
					c->globalSend(this, msg::FighterAsteroidCollisionMsg(msg::None, msg::Broadcast, fighter_, asteroid));
				}
			}
		}
	}
}

void FighterAsteroidCollisionPC::receive(Container * c, const msg::Message & msg) {
	switch (msg.type_) {
	case (msg::ASTEROIDS_INFO):
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case (msg::FIGHTER_INFO):
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}