#pragma once

#include <vector>

#include "GameManager.h"
#include "SDLGame.h"
#include "GameObject.h"
#include "Fighter.h"
#include "Asteroids.h"
#include "Bullets.h"
#include "BlackHoles.h"
#include "Logger.h"

class AsteroidsGame: public SDLGame {

public:
	AsteroidsGame();
	virtual ~AsteroidsGame();

	// from SDLGame
	void start();
	void stop();

private:
	void initGame();
	void closeGame();
	void handleInput(Uint32 time);
	void update(Uint32 time);
	void render(Uint32 time);

	const static int _WINDOW_WIDTH_ = 800;
	const static int _WINDOW_HEIGHT_ = 600;
	bool exit_;
	std::vector<GameObject*> actors_;

	GameManager gameManager_;
	Fighter fighter_;
	Asteroids asteroids_;
	Bullets bullets_;
	BlackHoles blackHoles_;
};
