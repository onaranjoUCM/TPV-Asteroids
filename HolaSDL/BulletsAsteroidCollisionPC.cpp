#include "BulletsAsteroidCollisionPC.h"
#include "Collisions.h"
#include "Messages_defs.h"
#include "GameManager.h"

BulletsAsteroidCollisionPC::BulletsAsteroidCollisionPC() { }

BulletsAsteroidCollisionPC::~BulletsAsteroidCollisionPC() { }

void BulletsAsteroidCollisionPC::update(Container * c, Uint32 time) {
	if (bullets_ != nullptr && asteroids_ != nullptr) {
		for (int i = 0; i < bullets_->size(); i++) {
			for (int j = 0; j < asteroids_->size(); j++) {
				Bullet* bullet = bullets_->at(i);
				Asteroid* asteroid = asteroids_->at(i);
				if (
					static_cast<GameManager*>(c)->isRunning() &&
					bullet->isActive() &&
					asteroid->isActive() &&
					Collisions::collidesWithRotation(bullet, asteroid))
				{
					c->globalSend(this, msg::BulletAsteroidCollision(msg::None, msg::Broadcast, bullet, asteroid));
				}
				else {
					break;
				}
			}
		}
	}
}

void BulletsAsteroidCollisionPC::receive(Container * c, const msg::Message & msg) {
	switch (msg.type_) {
	case (msg::ASTEROIDS_INFO):
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case (msg::BULLETS_INFO):
		bullets_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;
		break;
	}
}
