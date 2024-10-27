#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

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

#endif