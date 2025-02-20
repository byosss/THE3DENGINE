#include <iostream>

#include "Window.h"

#include "Scene/Scene.h"
#include "Physics/Physics.h"
#include "Renderer/Renderer.h"

#include "Time/TimeManager.h"
#include "Input/InputManager.h"
#include "Event/EventManager.h"

#include "Log/Logger.h"

#include "Resource/ResourceManager.h"

bool isRunning = true;

void setShouldClose( const WindowCloseEvent& event ) {
    isRunning = false;
}

int main() {

    Window window(1280, 720, "Runtime");

    Renderer::setWindowContext( (GLADloadproc)glfwGetProcAddress );

    auto& Time = TimeManager::getInstance();
    auto& Input = InputManager::getInstance();
    auto& Event = EventManager::getInstance();

    auto& log = Logger::getInstance();

    Event.addListener<WindowCloseEvent>(setShouldClose);

    Scene scene;

    scene.setup();

    auto shad1 = ResourceManager::getInstance().load<Model>("res/shaders/default.vert");

    while ( isRunning ) {

        // Update delta time
        Time.tick();

        // Poll events
        window.pollEvents();

        // Update input
        Input.update();

        // Dispatch events
        Event.dispatchEvents();

        // Update Game Logic
        scene.update();

        // Fixed Time Step
        while (Time.fixedTimeStep()) {

            // Update Physics
            scene.simulate();

            // Accumulate Time
            Time.fixedTimeStepEnd();
        }

        // Render
        scene.draw();

        // Swap Buffers
        window.swapBuffers();

        // Clear Buffers
        log.flush();
    }

    return 0;
}