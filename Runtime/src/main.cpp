#include <iostream>

#include "Window.h"

#include "Scene/Scene.h"
#include "Physics/Physics.h"
#include "Renderer/Renderer.h"

#include "Time/TimeManager.h"
#include "Input/InputManager.h"
#include "Event/EventManager.h"

#include "Log/Logger.h"

int main() {

    Window window(1280, 720, "Runtime");

    Renderer::setWindowContext( (GLADloadproc)glfwGetProcAddress );

    auto& Time = TimeManager::getInstance();
    auto& Input = InputManager::getInstance();
    auto& Event = EventManager::getInstance();

    auto& log = Logger::getInstance();

    Scene scene;

    while ( !window.shouldClose() ) {

        Time.tick();

        window.pollEvents();

        Input.update();

        Event.dispatchEvents();

        scene.update();

        while (Time.fixedTimeStep()) {

            scene.simulate();

            Time.fixedTimeStepEnd();

        }

        scene.draw();

        window.swapBuffers();

        log.flush();
    }

    return 0;
}