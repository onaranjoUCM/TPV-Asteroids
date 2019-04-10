#include "Logger.h"

Logger* Logger::instance_;

Logger::Logger(string filename) {
	log_.open(filename);
	worker_.start();
}

Logger::~Logger() { 
	log_.close();
}

void Logger::log(string info) {
	worker_.execute([info, this]() { log_ << info << endl; });
}

void Logger::log(function<string()> f) {
	worker_.execute([f, this]() { log_ << f() << endl; });
}