#include "GameManager.h"

GameManager::GameManager(SDLGame * game) :
	running_(false), gameOver_(true), score_(0), lives_(maxLives_), winner_(0),
	gameCtrl_(this)/*, scoreView_(this), livesViewer_(this), gameStatusView_(this)*/
{ }

GameManager::~GameManager() { }

int GameManager::getMaxLives() {
	return maxLives_;
}

bool GameManager::isRunning() {
	return gameOver_;
}

bool GameManager::isGameOver() {
	return gameOver_;
}

int GameManager::getScore() {
	return score_;
}

int GameManager::getLives() {
	return lives_;
}

int GameManager::getWinner() {
	return winner_;
}
