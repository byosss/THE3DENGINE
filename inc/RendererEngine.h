#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RendererEngine
{
public:
    RendererEngine(GLFWwindow* window);
    ~RendererEngine();

    void clear();
    void draw();
    void swapBuffers();

private:
    GLFWwindow* window;
};