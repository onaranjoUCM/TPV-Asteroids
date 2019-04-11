#include "BlackHoleAsteroidCollisionPC.h"
#include "Collisions.h"
#include "Messages_defs.h"
#include "GameManager.h"

BlackHoleAsteroidCollisionPC::BlackHoleAsteroidCollisionPC() { }

BlackHoleAsteroidCollisionPC::~BlackHoleAsteroidCollisionPC() { }

void BlackHoleAsteroidCollisionPC::update(Container * c, Uint32 time) {
	if (asteroids_ != nullptr && blackHoles_ != nullptr) {
		if (static_cast<GameManager*>(c)->isRunning()) {
			for (int i = 0; i < asteroids_->size(); i++) {
				for (int j = 0; j < blackHoles_->size(); j++) {
					Asteroid* asteroid = asteroids_->at(i);
					BlackHole* blackHole = blackHoles_->at(j);
					if (
						asteroid->isActive() &&
						blackHole->isActive() &&
						Collisions::collidesWithRotation(asteroid, blackHole))
					{
						c->globalSend(this, msg::BlackHoleAsteroidCollision(msg::None, msg::Broadcast, asteroid, blackHole, fighter_));
					}
				}
			}
		}
	}
}

void BlackHoleAsteroidCollisionPC::receive(Container * c, const msg::Message & msg) {
	switch (msg.type_) {
	case (msg::BLACKHOLES_INFO):
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case (msg::ASTEROIDS_INFO):
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case (msg::FIGHTER_INFO):
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}
