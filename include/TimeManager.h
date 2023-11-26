#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class TimeManager
{
private:
    GLFWwindow* window;

    double previousTime;
    double currentTime;
    double deltaTime;

    bool showFPS;
    unsigned int fpsRefreshRate;

public:

    TimeManager(GLFWwindow* window);

    void update();
    void updateFPS();

    double getDeltaTime();
};