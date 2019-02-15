#include "RotatingPC.h"



RotatingPC::RotatingPC(double g) :	grados(g) {}


RotatingPC::~RotatingPC() { }

void RotatingPC::update(Container* c) {
	c->getRotation();
}