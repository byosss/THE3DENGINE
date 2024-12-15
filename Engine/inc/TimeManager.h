#pragma once

#include <chrono>

class TimeManager {
public:
    TimeManager();

    void update();
    
    float getDeltaTime() const;
    float getElapsedTime() const;
    float getFPS() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_lastTime;
    std::chrono::duration<float> m_deltaTime;
};