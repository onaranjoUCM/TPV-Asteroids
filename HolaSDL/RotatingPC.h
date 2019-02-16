#pragma once
#include "PhysicsComponent.h"

class RotatingPC : 	public PhysicsComponent {
protected:
	double angle;
public:
	RotatingPC(double angle);
	virtual ~RotatingPC();
	virtual void update(Container* c, Uint32 time);
};

