#pragma once

#include <GLFW/glfw3.h>

class WindowEvent {
public:
    WindowEvent(GLFWwindow* window);

private:
    static void windowResizeCallback(GLFWwindow* window, int width, int height);
};