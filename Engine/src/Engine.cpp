#include "Engine.h"

Engine::Engine() : Time(TimeManager()) 
{
    // Constructor
    // -----------
    m_swapBuffersCallback = nullptr;
    m_pollEventsCallback = nullptr;
    m_windowShouldCloseCallback = nullptr;
}

void Engine::init(GLADloadproc gladLoadProc)
{
    // Load OpenGL function pointers
    // -----------------------------
    if (!gladLoadGLLoader( gladLoadProc )) 
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

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

    // Run the engine
    // --------------
    while (!m_windowShouldCloseCallback()) 
    {
        Time.tick();

        m_pollEventsCallback();

        update();
        
        draw(); 

        m_swapBuffersCallback();
    }
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
    std::cout << "Fps: " << 60 / Time.getDeltaTime() << std::endl;
}

void Engine::draw() 
{
    // Draw the next frame
    // -------------------
    glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::setSwapBuffersCallback(std::function<void()> callback) 
{
    m_swapBuffersCallback = callback;
}

void Engine::setPollEventsCallback(std::function<void()> callback) 
{
    m_pollEventsCallback = callback;
}

void Engine::setWindowShouldCloseCallback(std::function<int()> callback) 
{
    m_windowShouldCloseCallback = callback;
}