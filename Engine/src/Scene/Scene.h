#pragma once

#include <vector>

#include <entt/entity/registry.hpp>

#include "Physics/Physics.h"
#include "Renderer/Renderer.h"

class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    // Setup the scene
    void setup();
    
    // Update game logic
    void update();

    // Simulate physics
    void simulate();

    // Draw the scene
    void draw();

private:
    entt::registry m_registry;

    std::vector<void*> m_gameLogicSystems;
    std::vector<void*> m_physicsSystems;
    std::vector<void*> m_renderSystems;
};