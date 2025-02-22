#pragma once

#include "Window/WindowManager.h"

#include "Scene/SceneManager.h"
#include "Physic/PhysicSystem.h"
#include "Render/RenderSystem.h"

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
    // RenderSystem Render;

    TimeManager Time;
    InputManager Input;
    EventManager Event;

    bool isRunning;
};