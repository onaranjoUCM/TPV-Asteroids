#include "GameManager.h"

GameManager::GameManager(SDLGame * game) : Container(game),
	running_(false), gameOver_(true), score_(0), lives_(maxLives_), winner_(0),
	gameCtrl_(this), scoreView_(this), livesViewer_(this), gameStatusView_(this)
	//, fighterAsteroidCollision_(this), bulletsAsteroidsCollision_(this)
{
	addC(&gameCtrl_);
	addC(&scoreView_);
	addC(&livesViewer_);
	addC(&gameStatusView_);
	//addC(&fighterAsteroidCollision_);
	//addC(&bulletsAsteroidsCollision_);
}

GameManager::~GameManager() { }