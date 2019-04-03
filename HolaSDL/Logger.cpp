#include "Logger.h"

Logger::Logger() {
	// TODO: cambiar a log_.open(filename_);
	log_.open("log.txt");
	worker_.start();
}

Logger::~Logger() { 
	log_.close();
}

inline void Logger::initInstance(string filename) {
	filename_ = filename;
}

inline Logger * Logger::instance() {
	if (instance_ == nullptr) {
		instance_ = new Logger();
	}
	return instance_;
}

void Logger::log(string info) {
	worker_.execute([info, this]() { log_ << info << endl; });
}

void Logger::log(function<string()> f) {
	worker_.execute([f, this]() { log_ << f() << endl; });
}