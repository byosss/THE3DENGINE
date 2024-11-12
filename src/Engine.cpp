#include "Engine.h"

Engine::Engine(GLFWwindow* window) : //Physics(), 
                                     Renderer(window), 
                                     Time(),
                                     Event(window),
                                     Resources(),
                                     scene()
{
}

void Engine::load()
{
    scene.load();
}

void Engine::tick()
{
    Time.update();
}

void Engine::pollEvents()
{
    Event.update();
}

void Engine::update()
{
    scene.update( Time, Event );
    // Physics.update();
}

void Engine::render()
{
    Renderer.clear();
    // Renderer.draw( &scene );
    Renderer.swapBuffers();
}