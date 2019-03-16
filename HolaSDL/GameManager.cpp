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

void GameManager::receive(const void * senderObj, const msg::Message & msg) {
	int p;
	switch (msg.type_) {
	case (msg::GAME_START):
		gameOver_ = false;
		winner_ = 0;
		lives_ = maxLives_;
		break;
	case (msg::ROUND_START):
		running_ = true;
		// TODO: Reproducir  musica de fondo
		break;
	case (msg::ASTEROID_DESTROYED):
		p = static_cast<const msg::AsteroidDestroyed&>(msg).points_;
		score_ += p;
		break;
	case (msg::NO_MORE_ASTEROIDS):
		running_ = false;
		gameOver_ = true;
		winner_ = 1;
		// TODO: Parar música
		globalSend(this, msg::Message(msg::ROUND_OVER, msg::None, msg::Broadcast));
		globalSend(this, msg::Message(msg::GAME_OVER, msg::None, msg::Broadcast));
		break;
	case (msg::FIGHTER_ASTEROID_COLLISION):
		// TODO: Reproduce sonido de explosion
		// TODO: Para la musica de fondo
		running_ = false;
		lives_ -= 1;
		globalSend(this, msg::Message(msg::ROUND_OVER, msg::None, msg::Broadcast));

		if (lives_ == 0) {
			gameOver_ = true;
			winner_ = 2;
			globalSend(this, msg::Message(msg::GAME_OVER, msg::None, msg::Broadcast));
		}
		break;
	}
}