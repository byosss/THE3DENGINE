#include "TimeManager.h"

TimeManager& TimeManager::getInstance()
{
    static TimeManager instance;
    return instance;
}

TimeManager::TimeManager() : m_startTime(Clock::now()), 
                             m_lastTime(Clock::now()),
                             m_deltaTime(Duration(0.0)),
                             m_targetFrameTime(Duration(0.0))
{
}

void TimeManager::tick()
{
    // Get current time
    TimePoint currentTime = Clock::now();

    // Frame cap
    if (m_targetFrameTime.count() > 0.0)
    {
        while(currentTime - m_lastTime < m_targetFrameTime)
        {
            std::this_thread::yield();
            currentTime = Clock::now();
        }
    }

    // Calculate delta time
    m_deltaTime = currentTime - m_lastTime;
    m_lastTime = currentTime;
}

void TimeManager::setTargetFPS(double fps) {
    m_targetFrameTime = fps > 0.0 ? Duration(1.0 / fps) : Duration(0.0);
}

double TimeManager::getDeltaTime() const {
    return m_deltaTime.count();
}

double TimeManager::getElapsedTime() const {
    return Duration(Clock::now() - m_startTime).count();
}

int TimeManager::getFPS() const {
    return static_cast<int>(std::round(1.0 / m_deltaTime.count()));
}