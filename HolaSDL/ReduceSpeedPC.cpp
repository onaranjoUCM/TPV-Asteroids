#include "ReduceSpeedPC.h"

ReduceSpeedPC::ReduceSpeedPC(double f) : factor(f) { }

ReduceSpeedPC::~ReduceSpeedPC() { }

void ReduceSpeedPC::update(Container * c, Uint32 time) {
	c->setVelocity(c->getVelocity() * factor);
}
