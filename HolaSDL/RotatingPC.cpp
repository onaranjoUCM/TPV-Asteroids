#include "RotatingPC.h"

RotatingPC::RotatingPC(double a) : angle(a) { }

RotatingPC::~RotatingPC() { }

void RotatingPC::update(Container* c, Uint32 time) {
	c->getRotation();
}