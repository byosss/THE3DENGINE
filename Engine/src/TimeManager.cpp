#include "TimeManager.h"

TimeManager::TimeManager() {
    m_startTime = std::chrono::high_resolution_clock::now();
    m_lastTime = std::chrono::high_resolution_clock::now();
    m_deltaTime = std::chrono::duration<float>::zero();
}

void TimeManager::tick() 
{
    m_deltaTime = std::chrono::high_resolution_clock::now() - m_lastTime;
    m_lastTime = std::chrono::high_resolution_clock::now();
}

float TimeManager::getDeltaTime() const {
    return m_deltaTime.count();
}

float TimeManager::getElapsedTime() const {
    return std::chrono::duration<float, std::chrono::seconds::period>(std::chrono::high_resolution_clock::now() - m_startTime).count();
}

float TimeManager::getFPS() const {
    return 1.0f / this->getDeltaTime();
}