#pragma once

#include <iostream>
#include <functional>

#include "glad/glad.h"

#include "TimeManager.h"
// #include "EventManager.h"

class Engine {
public:
    Engine();

    void init( GLADloadproc gladLoadProc );
    void run();
    void terminate();

    void setSwapBuffersCallback(std::function<void()> callback);
    void setPollEventsCallback(std::function<void()> callback);
    void setWindowShouldCloseCallback(std::function<int()> callback);

private:
    void update();
    void draw();

    TimeManager Time;
    // EventManager Event;

    std::function<void()> m_swapBuffersCallback;
    std::function<void()> m_pollEventsCallback;
    std::function<int()> m_windowShouldCloseCallback;
};
