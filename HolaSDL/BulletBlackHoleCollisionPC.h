#pragma once

#include "PhysicsComponent.h"
#include "BlackHole.h"
#include "Bullet.h"

class BulletsBlackHoleCollisionPC : public PhysicsComponent {
private:
	const vector<BlackHole*>* blackHoles_;
	const vector<Bullet*>* bullets_;
public:
	BulletsBlackHoleCollisionPC();
	virtual ~BulletsBlackHoleCollisionPC();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};