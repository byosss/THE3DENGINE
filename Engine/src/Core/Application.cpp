#include "Application.h"

#include <iostream>

Application::Application() : Time(TimeManager::getInstance()),
                             Event(EventManager::getInstance()),
                             Input(InputManager::getInstance()),
                             window(1280, 720, "Game Engine")
                             
{

}

void Application::init()
{
    window.init();
    // window.setVSync(true);
    // window.setDisabledCursor(true);

    // Scene = std::make_unique<Scene>();
    // Renderer = std::make_unique<Renderer>();
    // Physics = std::make_unique<Physics>();    
}

void Application::run() 
{
    // Scene->start();

    while (!window.shouldClose()) {
        
        // Time update
        Time.tick();

        // Event & Input handling
        window.pollEvents();
        Input.update();
        Event.dispatchEvents();
        
        // Logic & simulation
        // Scene->update();
        // Physic->update(scene.get());
        
        // Rendering
        // Renderer->draw(scene.get());
        window.swapBuffers();

        std::cout << "FPS: " << Time.getFPS() << std::endl;
    }
}

void Application::terminate() 
{
    window.terminate();
}