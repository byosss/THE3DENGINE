#pragma once

#include <GLFW/glfw3.h>

#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"
#include "Event/WindowEvent.h"

class EventManager {
public:
    EventManager(GLFWwindow* window);
    ~EventManager();

    void update();

    KeyEvent Key;
    MouseEvent Mouse;
    WindowEvent Window;

private:
    GLFWwindow* window;
};