#pragma once

#include "Container.h"
//#include "GameCtrlIc.h"
//#include "ScoreViewerGC.h"
//#include "GameStatusViewGC.h"
//#include "LivesViewerGC"
//#include "FighterAsteroidCollision.h"
//#include "BulletsAsteroidsCollision.h"

class GameManager : public Container {
public:
	GameManager(SDLGame* game);
	virtual ~GameManager();
private:
	static int const maxLives_ = 3;
	bool running_;
	bool gameOver_;
	int score_;
	int lives_;
	int winner_; // 0=none, 1=asteroids, 2=fighter

	// components of GameManager
	//GameCtrlIC gameCtrl_;
	//ScoreViewerGC scoreView_;
	//GameStatusViewGC gameStatusView_;
	//LivesViewer livesViewer_;
	//FighterAsteroidCollision fighterAsteroidCollision_;
	//BulletsAsteroidsCollision bulletsAsteroidsCollision_;
};