#pragma once

#include <iostream>
#include <functional>

#include "glad/glad.h"

#include "TimeManager.h"
// #include "EventManager.h"

class Engine {
public:
    Engine();

    void init();
    void run();
    void terminate();

    void setSwapBuffersCallback(std::function<void()> callback);

private:
    void update();
    void draw();

    TimeManager Time;
    // EventManager Event;

    bool m_isRunning = false;
    std::function<void()> m_swapBuffersCallback;
};
