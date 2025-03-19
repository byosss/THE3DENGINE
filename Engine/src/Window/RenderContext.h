#pragma once

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>

struct RenderContext {
    
    void* getProcAddress() {
        return (void*)glfwGetProcAddress;
    }

    void swapBuffers() {
        glfwSwapBuffers(windowHandle);
    }

    GLFWwindow* windowHandle;
};
