#include "BulletsAsteroidCollisionPC.h"
#include "Collisions.h"

BulletsAsteroidCollisionPC::BulletsAsteroidCollisionPC(GameManager* gameManager) :
	gameManager_(gameManager) { }

BulletsAsteroidCollisionPC::~BulletsAsteroidCollisionPC() { }

void BulletsAsteroidCollisionPC::update(Container * c, Uint32 time) {
	/*
	if (bullets_ != nullptr && asteroids_ != nullptr) {
		for (int i = 0; i < bullets_->size; i++) {
			for (int j = 0; j < asteroids_->size; j++) {
			Bullet* bullet = bullets_->at(i);
			Asteroid* asteroid = asteroids_->at(i);
			if (
				gameManager_->isRunning() &&
				bullet->isActive() &&
				asteroid->isActive() &&
				Collisions::collidesWithRotation(bullet, asteroid))
			{
				msg::BulletAsteroidCollision(msg::None, msg::Broadcast, bullet, asteroid);
			} else {
				break;
			}
		}
	}*/
}
