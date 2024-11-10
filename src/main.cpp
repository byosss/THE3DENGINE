#include "Engine.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const char* SCR_TITLE = "THE3DENGINE";
GLFWwindow* window;


void innit() 
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return ;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
    
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return ;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);
}

void run()
{
    Engine engine(window);

    // load project resources
    // ----------------------
    engine.load();
    
    // game loop
    // ---------
    while (!glfwWindowShouldClose(window))
    {
        // time update
        // -----------
        engine.tick();

        // poll events
        // -----------
        engine.pollEvents();

        // update 
        // ------
        engine.update();

        // render
        // ------
        engine.render();   
    }
}

void terminate() 
{
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

int main()
{
    innit();
    run();
    terminate();

    return 0;
}