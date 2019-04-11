#pragma once

#include "PhysicsComponent.h"
#include "BlackHole.h"

class FighterBlackHoleCollisionPC : public PhysicsComponent {
private:
	GameObject* fighter_ = nullptr;
	const vector<BlackHole*>* blackHoles_ = nullptr;
public:
	FighterBlackHoleCollisionPC();
	virtual ~FighterBlackHoleCollisionPC();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};