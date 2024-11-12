#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Scene/Scene.h"

class RendererEngine
{
public:
    RendererEngine(GLFWwindow* window);
    ~RendererEngine();

    void clear();
    void draw( Scene* scene );
    void swapBuffers();

private:
    GLFWwindow* window;
};