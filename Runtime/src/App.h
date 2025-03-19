#pragma once

#include "Window/Window.h"

#include "Scene/SceneManager.h"
#include "Physic/PhysicSystem.h"
#include "Renderer/Renderer.h"

#include "Time/TimeManager.h"
#include "Input/InputManager.h"
#include "Event/EventManager.h"

class App {
public:
    App();
    ~App();

    void run();

private:
    Window Window;

    SceneManager Scene;
    // PhysicSystem Physic;
    Renderer Render;

    TimeManager Time;
    InputManager Input;
    EventManager Event;

    bool isRunning = false;
};