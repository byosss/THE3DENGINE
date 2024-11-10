#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class TimeManager {
public:
    TimeManager();

    void update();        // update time values

    float getTime();      // elapsed time since the start of the application
    float getDeltaTime(); // time between the current frame and the last frame
    float getFPS();       // frames per second

private:
    float deltaTime;
    float lastFrame;
};