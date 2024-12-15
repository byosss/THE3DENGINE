#include "Engine.h"

#include <math.h>

Engine::Engine() : Time(TimeManager()) 
{
    // Initialize the engine
    // ---------------------
    R = 0.0f;
    G = 0.0f;
    B = 0.0f;
}

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
    Time.update();

    R = sin(Time.getElapsedTime()) / 2.0f + 0.5f;
    G = sin(Time.getElapsedTime() + 2.0f) / 2.0f + 0.5f;
    B = sin(Time.getElapsedTime() + 4.0f) / 2.0f + 0.5f;

    std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;
    std::cout << "FPS: " << Time.getFPS() << std::endl;
    std::cout << "DeltaTime: " << Time.getDeltaTime() << std::endl;
}

void Engine::draw() 
{
    // Clear the color and depth buffers
    glClearColor(R, G, B, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
