#include "GameManager.h"

GameManager::GameManager(SDLGame * game) : running_(false), gameOver_(true), score_(0), lives_(maxLives_), winner_(0) {
	// TODO Inicializar los componentes
}

GameManager::~GameManager() { }
