#include "Event/KeyEvent.h"

InputState KeyEvent::keyState[GLFW_KEY_LAST];
KeyCallback KeyEvent::keyCallbacks[GLFW_KEY_LAST];

KeyEvent::KeyEvent(GLFWwindow* window) {

    glfwSetKeyCallback(window, this->keyCallback);

    for (int i = 0; i < GLFW_KEY_LAST; i++) {
        keyState[i] = InputState::RELEASED;
        keyCallbacks[i] = nullptr;
    }
}

void KeyEvent::setCallback(int key, KeyCallback callback) {
    keyCallbacks[key] = callback;
}

bool KeyEvent::isKeyPressed(int key) const {
    return keyState[key] == InputState::PRESSED;
}

bool KeyEvent::isKeyReleased(int key) const {
    return keyState[key] == InputState::RELEASED;
}

void KeyEvent::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    if (action == GLFW_PRESS) {
        keyState[key] = InputState::PRESSED;
    } else if (action == GLFW_RELEASE) {
        keyState[key] = InputState::RELEASED;
    }

    if (keyCallbacks[key] != nullptr) {
        keyCallbacks[key](key, scancode, action, mods);
    }
}