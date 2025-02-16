#pragma once

#include <chrono>
#include <thread>

class TimeManager {
public:
    static TimeManager& getInstance();

    void tick();

    bool fixedTimeStep();
    void fixedTimeStepEnd();

    void setTargetFPS(double fps);
    double getDeltaTime() const;
    double getElapsedTime() const;
    int getFPS() const;

private:
    TimeManager();

    TimeManager(const TimeManager&) = delete;
    TimeManager& operator=(const TimeManager&) = delete;
    TimeManager(TimeManager&&) = delete;
    TimeManager& operator=(TimeManager&&) = delete;

    using Clock = std::chrono::steady_clock;
    using TimePoint = Clock::time_point;
    using Duration = std::chrono::duration<double>;

    TimePoint m_startTime;
    TimePoint m_lastTime;
    Duration m_deltaTime{0.0};
    Duration m_targetFrameTime{0.0};
    Duration m_fixedTimeStep{1.0 / 60.0};
    Duration m_accumulator{0.0};
};