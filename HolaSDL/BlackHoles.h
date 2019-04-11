#pragma once
#include "GameObjectPool.h"
#include "BlackHole.h"
#include <vector>

class BlackHoles : public GameObjectPool<BlackHole, 10> {
public:
	BlackHoles(SDLGame* game);
	virtual ~BlackHoles();

	virtual void receive(const void* senderObj, const msg::Message& msg);
	void RoundStart(const msg::Message & msg);
	//void BulletAsteroidCollision(const msg::Message & msg);

private:
	ImageGC blackHoleImage_;
	RotatingPC rotating_;
	int round = 0;
};