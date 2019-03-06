#pragma once
#include "GameObject.h"

template<typename T, int SIZE>
class ObjectPoll : public GameObject {
public:
	ObjectPoll(SDLGame* game);
	virtual ~ObjectPoll();

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual void addItem(Vector2D pos, Vector2D vel, Vector2D acc);

private:
	T * getUnusedItem();
	T items_[SIZE];
};

template<typename T, int SIZE>
inline ObjectPoll<T, SIZE>::ObjectPoll(SDLGame* game) : GameObject(game){
	for (int i = 0; i < SIZE; i++) {
		items_[i].setActive(false);
		items_[i].setGame(game);
	}
}

template<typename T, int SIZE>
inline ObjectPoll<T, SIZE>::~ObjectPoll() {
}

template<typename T, int SIZE>
inline void ObjectPoll<T, SIZE>::handleInput(Uint32 time, const SDL_Event & event) {
	for (int i = 0; i < SIZE; i++) {
		if (items_[i].isActive()) {
			items_[i].handleInput(time, event);
		}
	}
}

template<typename T, int SIZE>
inline void ObjectPoll<T, SIZE>::update(Uint32 time) {
	for (int i = 0; i < SIZE; i++) {
		if (items_[i].isActive()) {
			items_[i].update(time);
		}
	}
}

template<typename T, int SIZE>
inline void ObjectPoll<T, SIZE>::render(Uint32 time) {
	for (int i = 0; i < SIZE; i++) {
		if (items_[i].isActive()) {
			items_[i].render(time);
		}
	}
}

template<typename T, int SIZE>
inline void ObjectPoll<T, SIZE>::addItem(Vector2D pos, Vector2D vel, Vector2D acc) {
	T* e = getUnusedItem();
	if (e != nullptr) {
		int h = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 5);
		e->setWidth(24 + h * 0.8);
		e->setHeight(30 + h);
		e->setVelocity(vel);
		e->setAcceleration(acc);
		e->setPosition(pos);
		e->setActive(true);
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);

	}
}

template<typename T, int SIZE>
inline T * ObjectPoll<T, SIZE>::getUnusedItem() {
	for (int i = 0; i < SIZE; i++)
		if (!items_[i].isActive()) {
			return &items_[i];
		}

	return nullptr;
}
