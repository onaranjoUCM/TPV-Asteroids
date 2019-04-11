#include "FighterBlackHoleCollisionPC.h"
#include "Collisions.h"
#include "Messages_defs.h"
#include "GameManager.h"

FighterBlackHoleCollisionPC::FighterBlackHoleCollisionPC() { }

FighterBlackHoleCollisionPC::~FighterBlackHoleCollisionPC() { }

void FighterBlackHoleCollisionPC::update(Container * c, Uint32 time) {
	if (fighter_ != nullptr && blackHoles_ != nullptr) {
		if (static_cast<GameManager*>(c)->isRunning()) {
			for (int i = 0; i < blackHoles_->size(); i++) {
				BlackHole* blackHole = blackHoles_->at(i);
				if (
					fighter_->isActive() &&
					blackHoles_->at(i)->isActive() &&
					Collisions::collidesWithRotation(fighter_, blackHole))
				{
					c->globalSend(this, msg::FighterBlackHoleCollisionMsg(msg::None, msg::Broadcast, fighter_, blackHole));
				}
			}
		}
	}
}

void FighterBlackHoleCollisionPC::receive(Container * c, const msg::Message & msg) {
	switch (msg.type_) {
	case (msg::BLACKHOLES_INFO):
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case (msg::FIGHTER_INFO):
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}