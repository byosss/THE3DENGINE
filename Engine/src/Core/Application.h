#pragma once

#include "Core/Window.h"
#include "Time/TimeManager.h"
#include "Event/EventManager.h"
#include "Input/InputManager.h"

class Application {
public:
    Application();

    void init();
    void run();
    void terminate();

private:
    Window window;

    TimeManager& Time;
    EventManager& Event;
    InputManager& Input;

    // std::unique_ptr<Scene> Scene;
    // std::unique_ptr<Renderer> Renderer;
    // std::unique_ptr<Physics> Physics;
};
