#pragma once

#include "PhysicsEngine.h"
#include "RendererEngine.h"

#include "ResourceManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "Scene/Scene.h"


class Engine {
public:
    Engine(GLFWwindow* window);

    void load();
    
    void tick();
    void pollEvents();
    void update();
    void render();

private:
    RendererEngine Renderer;
    // PhysicsEngine Physics;
    TimeManager Time;
    EventManager Event;
    ResourceManager Resources;
    Scene scene;
};
