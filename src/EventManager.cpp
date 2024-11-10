#include "EventManager.h"

EventManager::EventManager(GLFWwindow* window) : window(window),
                                                 Key(window),
                                                 Mouse(window),
                                                 Window(window)
{ 
    
}

EventManager::~EventManager() { 
    glfwSetKeyCallback(window, NULL);
    glfwSetMouseButtonCallback(window, NULL);
    glfwSetCursorPosCallback(window, NULL);
    glfwSetScrollCallback(window, NULL);
    glfwSetWindowSizeCallback(window, NULL); 
}

void EventManager::update() {
    glfwPollEvents();
}
