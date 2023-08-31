#include "TimeManager.h"



TimeManager::TimeManager(GLFWwindow* window) {

    this->window = window;

    this->previousTime = 0.0;
    this->currentTime = 0.0;
    this->counter = 0;

    this->showFPS = true;

}


void TimeManager::update(){
    
    currentTime = glfwGetTime();
    deltaTime = currentTime - previousTime;
    counter++;

    if (showFPS)
    {
        updateFPS();
    }
}

void TimeManager::updateFPS(){
    
    if (deltaTime >= 0.1)
    {
        newTitle = "OpenGL - " + std::to_string((1.0 / deltaTime) * counter) + "FPS / " + std::to_string((deltaTime / counter) * 1000) + "ms";
        glfwSetWindowTitle(window, newTitle.c_str());
        previousTime = currentTime;
        counter = 0;
    }
}

double TimeManager::getDeltaTime(){
    return deltaTime;
}