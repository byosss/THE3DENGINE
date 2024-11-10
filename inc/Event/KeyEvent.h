#pragma once

#include <GLFW/glfw3.h>

#include "Event/InputState.h"

using KeyCallback = void (*)(int, int, int, int);

class KeyEvent {
public:
    KeyEvent(GLFWwindow* window);
    
    void setCallback(int key, KeyCallback callback);

    bool isKeyPressed(int key) const;
    bool isKeyReleased(int key) const;

private:
    static InputState keyState[GLFW_KEY_LAST];
    static KeyCallback keyCallbacks[GLFW_KEY_LAST];

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};