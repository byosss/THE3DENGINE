#include "Engine.h"

Engine::Engine() : Time(TimeManager()) 
{
    // Initialize the engine
    // ---------------------

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

void Engine::run() 
{
    if (!m_swapBuffersCallback) 
    {
        std::cerr << "Swap buffers callback is not set" << std::endl;
        return;
    }

    m_isRunning = true;

    // Run the engine
    // --------------
    while (m_isRunning) 
    {
        Time.tick();

        //Event.pollEvents();

        update();
        
        draw(); 

        m_swapBuffersCallback();
    }
}

void Engine::terminate() 
{
    // Terminate the engine
    // --------------------
    m_isRunning = false;
}

void Engine::update() 
{
    // Update the engine
    // -----------------
}

void Engine::draw() 
{
    // Draw the next frame
    // -------------------
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::setSwapBuffersCallback(std::function<void()> callback) 
{
    m_swapBuffersCallback = callback;
}