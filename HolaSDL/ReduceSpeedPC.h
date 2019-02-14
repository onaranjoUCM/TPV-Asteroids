#pragma once

#include "PhysicsComponent.h"

class ReduceSpeedPC : public PhysicsComponent {
protected:
	double factor;
public:
	ReduceSpeedPC(double factor);
	virtual ~ReduceSpeedPC();
	virtual void update(Container* c, Uint32 time);
};

