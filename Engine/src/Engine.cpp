#include "Engine.h"

#include <math.h>

void Engine::init() 
{
    // Print OpenGL version
    // --------------------
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);   
}

void Engine::terminate() 
{
    // Terminate the engine
    // --------------------
}

void Engine::update() 
{
    // Update the engine
    // -----------------

    static auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::duration<float, std::chrono::seconds::period>(std::chrono::high_resolution_clock::now() - startTime).count();

    R = sin(currentTime) / 2.0f + 0.5f;
    G = sin(currentTime + 2.0f) / 2.0f + 0.5f;
    B = sin(currentTime + 4.0f) / 2.0f + 0.5f;

    std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;
}

void Engine::draw() 
{
    // Clear the color and depth buffers
    glClearColor(R, G, B, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
