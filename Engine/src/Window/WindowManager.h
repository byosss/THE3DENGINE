#pragma once

#include <iostream>
#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Event/EventManager.h"
#include "Input/InputManager.h"

#include "WindowHandle.h"

class WindowManager {
public:
    WindowManager( EventManager& Event, InputManager& Input );
    ~WindowManager();

    void pollEvents();
    void swapBuffers();
    bool shouldClose() const;
    void setVSync(bool enabled);
    void disableCursor(bool enabled);

    int getWidth() const;
    int getHeight() const;

    const WindowHandle& getHandle() const;

private:
    GLFWwindow* m_Window;

    WindowHandle m_Handle;

    EventManager& m_Event;
    InputManager& m_Input;
};