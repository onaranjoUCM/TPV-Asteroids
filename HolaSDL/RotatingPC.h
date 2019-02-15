#pragma once
#include "PhysicsComponent.h"

class RotatingPC : 	public PhysicsComponent {
protected:
	double grados;
public:
	RotatingPC(double grados);
	~RotatingPC();
	virtual void update(Container* c);
};

