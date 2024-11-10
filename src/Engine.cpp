#include "Engine.h"

Engine::Engine(GLFWwindow* window) : //Physics(), 
                                     Renderer(window), 
                                     Time(),
                                     Event(window),
                                     Resources(),
                                     sceneManager()
{
}

void Engine::load()
{
    sceneManager.loadScene();
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
    sceneManager.getCurrentScene()->update( Time, Event );
    // Physics.update();
}

void Engine::render()
{
    Renderer.clear();
    // Renderer.draw( SceneManager.getScene() );
    Renderer.swapBuffers();
}