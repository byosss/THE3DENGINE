#pragma once

#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);

    void init();
    void terminate();

    void pollEvents();
    void swapBuffers();
    bool shouldClose() const;
    void setVSync(bool enabled);
    void setDisabledCursor(bool enabled);


    GLFWwindow* getHandle() const;

private:
    GLFWwindow* m_Window;
    int m_Width, m_Height;
    std::string m_Title;
};