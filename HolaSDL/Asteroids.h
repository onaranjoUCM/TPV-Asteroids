#pragma once
#include "GameObjectPool.h"
#include "Asteroid.h"
#include <vector>

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();

	virtual void receive(const void* senderObj, const msg::Message& msg);
	void RoundStart(const msg::Message & msg);
	void BulletAsteroidCollision(const msg::Message & msg);
	void BlackHoleAsteroidCollision(const msg::Message & msg);

private:
	int activeAsteroids = 0;
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

