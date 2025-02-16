#include "Logger.h"

#include <iostream>

Logger::~Logger()
{
    flush();
}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::log(Level level, const std::string& message)
{
    std::cout << getPrefix(level) << message << "\n";
    if (level == Level::ERROR)
    {
        flush();
    }
}

void Logger::flush()
{
    std::cout << std::flush;
}

std::string Logger::getPrefix(Level level)
{
    switch (level){
        case Level::INFO:
            return "[INFO] ";
        case Level::WARNING:
            return "[WARNING] ";
        case Level::ERROR:
            return "[ERROR] ";
        default:
            return "";
    }
}