#include <iostream>

#include "Engine.h"
#include <glfw/glfw3.h>

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "THE3DENGINE", NULL, NULL);

    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize the engine
    Engine engine;
    engine.init((GLADloadproc)glfwGetProcAddress);

    // Set the swap buffers callback
    engine.setSwapBuffersCallback([&]() { glfwSwapBuffers(window); });

    // Set the poll events callback
    engine.setPollEventsCallback([&]() { glfwPollEvents(); });

    // Set the window should close callback
    engine.setWindowShouldCloseCallback([&]() { return glfwWindowShouldClose(window); });

    engine.run();
    engine.terminate();

    // Terminate GLFW
    glfwTerminate();

    return 0;
}
