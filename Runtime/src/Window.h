#pragma once

#include <iostream>
#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    void pollEvents();
    void swapBuffers();
    bool shouldClose() const;
    void setVSync(bool enabled);
    void disableCursor(bool enabled);

    GLFWwindow* getHandle() const;

private:
    GLFWwindow* m_Window;
    int m_Width, m_Height;
    std::string m_Title;
};