#include "Event/WindowEvent.h"

WindowEvent::WindowEvent(GLFWwindow* window) { 

    glfwSetWindowSizeCallback(window, this->windowResizeCallback);

}

void WindowEvent::windowResizeCallback(GLFWwindow* window, int width, int height) {

    // glViewport(0, 0, width, height);

    // glMatrixMode(GL_PROJECTION);
}
