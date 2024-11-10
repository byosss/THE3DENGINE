#pragma once

#include <GLFW/glfw3.h>

#include "Event/InputState.h"

using MouseButtonCallback = void (*)(int, int, int);
using MousePositionCallback = void (*)(double, double);
using MouseScrollCallback = void (*)(double, double);

class MouseEvent {
public:
    MouseEvent(GLFWwindow* window);

    void setMouseButtonCallback(int button, MouseButtonCallback callback);
    void setMousePositionCallback(MousePositionCallback callback);
    void setMouseScrollCallback(MouseScrollCallback callback);

    bool isButtonPressed(int button) const;
    bool isButtonReleased(int button) const;

    double getXpos() const;
    double getYpos() const;

    double getScrollX() const;
    double getScrollY() const;

private:
    static InputState mouseButtonState[GLFW_MOUSE_BUTTON_LAST];
    static MouseButtonCallback mouseButtonCallbacks[GLFW_MOUSE_BUTTON_LAST];
    
    static double mouseX;
    static double mouseY;
    static MousePositionCallback mousePositionCallbacks;
    
    static double scrollX;
    static double scrollY;
    static MouseScrollCallback mouseScrollCallbacks;

    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void mousePositionCallback(GLFWwindow* window, double x, double y);
    static void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
};