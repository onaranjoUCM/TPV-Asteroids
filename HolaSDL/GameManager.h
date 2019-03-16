#pragma once

#include "Container.h"
#include "GameCtrlIc.h"
#include "ScoreViewerGC.h"
#include "GameStatusViewGC.h"
#include "LivesViewerGC.h"
#include "FighterAsteroidCollisionPC.h"
#include "BulletsAsteroidCollisionPC.h"

class GameManager : public Container {
public:
	GameManager(SDLGame* game);
	virtual ~GameManager();

	int getMaxLives() { return maxLives_; }
	bool isRunning() { return running_; };
	bool isGameOver() { return gameOver_; };
	int getScore() { return score_; };
	int getLives() { return lives_; };
	int getWinner() { return winner_; };

	virtual void receive(const void* senderObj, const msg::Message& msg);

private:
	static int const maxLives_ = 3;
	bool running_;
	bool gameOver_;
	int score_;
	int lives_;
	int winner_; // 0=none, 1=asteroids, 2=fighter

	GameCtrlIC gameCtrl_;
	ScoreViewerGC scoreView_;
	GameStatusViewGC gameStatusView_;
	LivesViewerGC livesViewer_;
	//FighterAsteroidCollisionPC fighterAsteroidCollision_;
	//BulletsAsteroidCollisionPC bulletsAsteroidsCollision_;
};