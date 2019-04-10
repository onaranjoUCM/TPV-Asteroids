#include "GameManager.h"
#include "Logger.h"

GameManager::GameManager(SDLGame * game) : Container(game),
	running_(false), gameOver_(true), score_(0), lives_(maxLives_), winner_(0),
	gameCtrl_(this), scoreView_(this), livesViewer_(this), gameStatusView_(this)
	, fighterAsteroidCollision_(), bulletsAsteroidsCollision_()
{
	addC(&gameCtrl_);
	addC(&scoreView_);
	addC(&livesViewer_);
	addC(&gameStatusView_);
	addC(&fighterAsteroidCollision_);
	addC(&bulletsAsteroidsCollision_);
}

GameManager::~GameManager() { }

void GameManager::receive(const void * senderObj, const msg::Message & msg) {
	Container::receive(senderObj, msg);
	int p;
	switch (msg.type_) {
	case (msg::GAME_START):
		gameOver_ = false;
		winner_ = 0;
		score_ = 0;
		lives_ = maxLives_;
		break;
	case (msg::ROUND_START):
		running_ = true;
		getGame()->getServiceLocator()->getAudios()->playMusic(Resources::ImperialMarch, -1);
		Logger::getInstance()->log("Round Start");
		break;
	case (msg::ASTEROID_DESTROYED):
		p = static_cast<const msg::AsteroidDestroyed&>(msg).points_;
		score_ += p;
		break;
	case (msg::NO_MORE_ASTEROIDS):
		running_ = false;
		gameOver_ = true;
		winner_ = 2;
		getGame()->getServiceLocator()->getAudios()->haltMusic();
		globalSend(this, msg::Message(msg::ROUND_OVER, msg::None, msg::Broadcast));
		globalSend(this, msg::Message(msg::GAME_OVER, msg::None, msg::Broadcast));
		Logger::getInstance()->log("Round End");
		break;
	case (msg::FIGHTER_ASTEROID_COLLISION):
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, -1);
		getGame()->getServiceLocator()->getAudios()->haltMusic();

		running_ = false;
		lives_ -= 1;
		globalSend(this, msg::Message(msg::ROUND_OVER, msg::None, msg::Broadcast));

		if (lives_ == 0) {
			gameOver_ = true;
			winner_ = 1;
			globalSend(this, msg::Message(msg::GAME_OVER, msg::None, msg::Broadcast));
		}
		Logger::getInstance()->log("Round End");
		break;
	}
}