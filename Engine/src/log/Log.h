
#define LOG_INFO(msg) Log::getInstance().log(Log::Level::INFO, msg)
#define LOG_WARN(msg) Log::getInstance().log(Log::Level::WARNING, msg)
#define LOG_ERROR(msg) Log::getInstance().log(Log::Level::ERROR, msg)

#include <string>

class Log
{
public:
    enum class Level { INFO, WARNING, ERROR };

    static Log& getInstance();

    void log(Level level, const std::string& message);
    void flush();

private:
    Log() = default;
    ~Log();

    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;
    Log(Log&&) = delete;
    Log& operator=(Log&&) = delete;

    std::string getPrefix(Level level);
};