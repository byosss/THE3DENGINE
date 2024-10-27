#include "TimeManager.h"

TimeManager::TimeManager(GLFWwindow* window) : window(window)  {

    this->previousTime = 0.0;
    this->currentTime = 0.0;
    this->fpsRefreshRate = 0;

    this->showFPS = true;

}

void TimeManager::update(){
    
    currentTime = glfwGetTime();
    deltaTime = currentTime - previousTime;
    previousTime = currentTime;
    fpsRefreshRate++;

    if (showFPS)
    {
        updateFPS();
    }
}

void TimeManager::updateFPS(){
    
    if (fpsRefreshRate >= 500)  // update the FPS counter each 500 frames
    {
        glfwSetWindowTitle(window, ("OpenGL - " + std::to_string(1.0 / deltaTime) + 
                                    "FPS / " + std::to_string((deltaTime) * 1000) + "ms").c_str());

        fpsRefreshRate = 0;
    }
}

double TimeManager::getDeltaTime(){
    return deltaTime;
}