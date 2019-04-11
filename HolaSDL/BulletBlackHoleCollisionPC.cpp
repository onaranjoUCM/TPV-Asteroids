#include "BulletBlackHoleCollisionPC.h"
#include "Collisions.h"
#include "Messages_defs.h"
#include "GameManager.h"

BulletsBlackHoleCollisionPC::BulletsBlackHoleCollisionPC() { }

BulletsBlackHoleCollisionPC::~BulletsBlackHoleCollisionPC() { }

void BulletsBlackHoleCollisionPC::update(Container * c, Uint32 time) {
	if (bullets_ != nullptr && blackHoles_ != nullptr) {
		if (static_cast<GameManager*>(c)->isRunning()) {
			for (int i = 0; i < bullets_->size(); i++) {
				for (int j = 0; j < blackHoles_->size(); j++) {
					Bullet* bullet = bullets_->at(i);
					BlackHole* blackHole = blackHoles_->at(j);
					if (
						bullet->isActive() &&
						blackHole->isActive() &&
						Collisions::collidesWithRotation(bullet, blackHole))
					{
						c->globalSend(this, msg::BulletBlackHoleCollision(msg::None, msg::Broadcast, bullet, blackHole));
					}
				}
			}
		}
	}
}

void BulletsBlackHoleCollisionPC::receive(Container * c, const msg::Message & msg) {
	switch (msg.type_) {
	case (msg::BLACKHOLES_INFO):
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case (msg::BULLETS_INFO):
		bullets_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;
		break;
	}
}
