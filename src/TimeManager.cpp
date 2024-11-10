#include "TimeManager.h"

TimeManager::TimeManager() : deltaTime(0.0f), lastFrame(0.0f) { }

void TimeManager::update() 
{
    deltaTime = glfwGetTime() - lastFrame;
    lastFrame += deltaTime;
}

float TimeManager::getTime() 
{
    return glfwGetTime();
}

float TimeManager::getDeltaTime() 
{
    return deltaTime;
}

float TimeManager::getFPS() 
{
    return 1.0f / deltaTime;
}
