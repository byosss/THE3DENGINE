#pragma once

#include "Window/WindowManager.h"

#include "Scene/SceneManager.h"
#include "Physic/PhysicSystem.h"
#include "Renderer/Renderer.h"

#include "Time/TimeManager.h"
#include "Input/InputManager.h"
#include "Event/EventManager.h"

class App
{
public:
    App();
    ~App();

    void run();

private:
    WindowManager Window;

    SceneManager Scene;
    // PhysicSystem Physic;
    std::unique_ptr<IRenderer> Renderer;

    TimeManager Time;
    InputManager Input;
    EventManager Event;

    bool isRunning;
};