#pragma once

#include <iostream>
#include <memory>
#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Event/EventManager.h"
#include "Input/InputManager.h"

#include "RenderContext.h"

class Window {
public:
    Window();
    ~Window();

    void init(EventManager& Event, InputManager& Input);
    void createWindow(int width, int height, const std::string& title);

    void pollEvents();
    void setVSync(bool enabled);
    void disableCursor(bool enabled);

    std::unique_ptr<RenderContext> getRenderContext() const;

private:
    GLFWwindow* m_Window;

    EventManager* m_Event;
    InputManager* m_Input;
};