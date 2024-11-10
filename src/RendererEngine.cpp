#include "RendererEngine.h"

RendererEngine::RendererEngine(GLFWwindow* window) : window(window)
{
}

RendererEngine::~RendererEngine()
{
}

void RendererEngine::clear()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererEngine::draw()
{
    // Draw the scene
}

void RendererEngine::swapBuffers()
{
    glfwSwapBuffers(window);
}