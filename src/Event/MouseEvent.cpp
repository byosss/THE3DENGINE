#include "Event/MouseEvent.h"

InputState MouseEvent::mouseButtonState[GLFW_MOUSE_BUTTON_LAST];
MouseButtonCallback MouseEvent::mouseButtonCallbacks[GLFW_MOUSE_BUTTON_LAST];

double MouseEvent::mouseX;
double MouseEvent::mouseY;
MousePositionCallback MouseEvent::mousePositionCallbacks;

double MouseEvent::scrollX;
double MouseEvent::scrollY;
MouseScrollCallback MouseEvent::mouseScrollCallbacks;

MouseEvent::MouseEvent(GLFWwindow* window) { 

    glfwSetMouseButtonCallback(window, this->mouseButtonCallback);
    glfwSetCursorPosCallback(window, this->mousePositionCallback);
    glfwSetScrollCallback(window, this->mouseScrollCallback);

    for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++) {
        mouseButtonState[i] = InputState::RELEASED;
        mouseButtonCallbacks[i] = nullptr;
    }

    mouseX = 0.0;
    mouseY = 0.0;

    scrollX = 0.0;
    scrollY = 0.0;
}

void MouseEvent::setMouseButtonCallback(int button, MouseButtonCallback callback) {
    mouseButtonCallbacks[button] = callback;
}

void MouseEvent::setMousePositionCallback(MousePositionCallback callback) {
    mousePositionCallbacks = callback;
}

void MouseEvent::setMouseScrollCallback(MouseScrollCallback callback) {
    mouseScrollCallbacks = callback;
}

bool MouseEvent::isButtonPressed(int button) const {
    return mouseButtonState[button] == InputState::PRESSED;
}

bool MouseEvent::isButtonReleased(int button) const {
    return mouseButtonState[button] == InputState::RELEASED;
}

double MouseEvent::getXpos() const { return mouseX; }
double MouseEvent::getYpos() const { return mouseY; }

double MouseEvent::getScrollX() const { return scrollX; }
double MouseEvent::getScrollY() const { return scrollY; }



void MouseEvent::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        mouseButtonState[button] = InputState::PRESSED;
    } else if (action == GLFW_RELEASE) {
        mouseButtonState[button] = InputState::RELEASED;
    }

    if (mouseButtonCallbacks[button] != nullptr) {
        mouseButtonCallbacks[button](button, action, mods);
    }
}

void MouseEvent::mousePositionCallback(GLFWwindow* window, double x, double y) {

    mouseX = x;
    mouseY = y;

    if (mousePositionCallbacks != nullptr) {
        mousePositionCallbacks(x, y);
    }
}

void MouseEvent::mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    scrollX = xoffset;
    scrollY = yoffset;

    if (mouseScrollCallbacks != nullptr) {
        mouseScrollCallbacks(xoffset, yoffset);
    }
}

