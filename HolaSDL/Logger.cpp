#include "Logger.h"

Logger* Logger::logger_ = nullptr;

inline void Logger::initInstance(string filename)
{
}

inline Logger * Logger::instance() {
	if (logger_ == nullptr) {
		logger_ = new Logger();
		loggerManager_.setObject(logger_);
	}
	return logger_;
}

void Logger::log(string info)
{
}

Logger::~Logger() {
	delete Logger::instance();
}
