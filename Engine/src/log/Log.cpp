#include "Log.h"

#include <iostream>

Log::~Log()
{
    flush();
}

Log& Log::getInstance()
{
    static Log instance;
    return instance;
}

void Log::log(Level level, const std::string& message)
{
    std::cout << getPrefix(level) << message << "\n";
    if (level == Level::ERROR)
    {
        flush();
    }
}

void Log::flush()
{
    std::cout << std::flush;
}

std::string Log::getPrefix(Level level)
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