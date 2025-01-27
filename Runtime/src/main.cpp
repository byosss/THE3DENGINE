#include <iostream>

#include "Window.h"

#include "Scene/Scene.h"
#include "Physics/Physics.h"
#include "Renderer/Renderer.h"

#include "Time/TimeManager.h"
#include "Input/InputManager.h"
#include "Event/EventManager.h"

int main() {

    Window window(1280, 720, "Runtime");

    auto& Time = TimeManager::getInstance();
    auto& Input = InputManager::getInstance();
    auto& Event = EventManager::getInstance();

    Scene scene;

    Physics physics;

    Renderer renderer;
    renderer.setWindowContext( (GLADloadproc)glfwGetProcAddress );

    // scene._start();

    while ( !window.shouldClose() ) {

        Time.tick();

        window.pollEvents();

        Input.update();

        Event.dispatchEvents();

        // while (Time.fixedTimeStep()) {

        //     scene._fixedUpdate();

        // }

        // scene._update();

        physics.simulate( scene );

        renderer.draw( scene );

        window.swapBuffers();
    }

    return 0;
}