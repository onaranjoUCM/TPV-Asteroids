#pragma once
#include "AsteroidsGame.h"
#include "Destructor.h"

class Logger {
public:
	inline static void initInstance(string filename);
	inline static Logger* instance();
	void log(string info);
	//void log(function<string()> f);
	static Destructor<Logger> loggerManager_;
	virtual ~Logger() { };

	//Esto dice la teoria que es para evitar que se hagan copias del singleton
	//pero no entiendo (c++11)
	Logger(Logger&) = delete;
	Logger& operator = (const Logger&) = delete;
private:
	static Logger* logger_;
	Logger() { };
	//Worker worker_;
	//ofstream log_;
};

