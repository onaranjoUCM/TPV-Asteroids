#include "RotatingPC.h"

RotatingPC::RotatingPC() {}

RotatingPC::RotatingPC(double a) {
	angle = a;
}

RotatingPC::~RotatingPC() {}

void RotatingPC::update(Container* c, Uint32 time) {
	c->setRotation(c->getRotation() + angle);
}