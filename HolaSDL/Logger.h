#pragma once
#include "AsteroidsGame.h"
#include "Worker.h"
#include <functional>
#include <fstream>

class Logger {
private:
	static string filename_;
	static Logger* instance_;
	Logger();
	Worker worker_;
	ofstream log_;

public:
	inline static void initInstance(string filename);
	inline static Logger* instance();
	void log(string info);
	void log(function<string()> f);
	virtual ~Logger();

	Logger(Logger&) = delete;
	Logger& operator = (const Logger&) = delete;
};

