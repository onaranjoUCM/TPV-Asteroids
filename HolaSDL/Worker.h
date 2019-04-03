#pragma once

#include "../SDL2-2.0.7/include/SDL.h"
#include "BlockingQueue.h"
#include <functional>

/*
 *
 */
class Worker {
public:
	Worker();
	virtual ~Worker();
	void start();
	void stop();
	void execute(std::function<void()> f);
private:
	static int start(void* o);
	void process();

	BlockingQueue<std::function<void()>> tasks_;
	SDL_Thread *t_;
	bool running_;
};

