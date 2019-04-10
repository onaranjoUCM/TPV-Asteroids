#pragma once
#include "AsteroidsGame.h"
#include "Worker.h"
#include <functional>
#include <fstream>

class Logger {
private:
	static Logger* instance_;
	Logger(string filename_);
	Worker worker_;
	ofstream log_;

public:
	inline static void initInstance(string filename) {
		if (instance_ == nullptr) {
			instance_ = new Logger(filename);
		}
	}

	inline static Logger* getInstance() {
		return instance_;
	}

	void log(string info);
	void log(function<string()> f);
	virtual ~Logger();

	Logger(Logger&) = delete;
	Logger& operator = (const Logger&) = delete;
};

