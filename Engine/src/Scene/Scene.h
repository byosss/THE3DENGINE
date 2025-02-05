#pragma once

#include <entt/entity/registry.hpp>

class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    // void _start();
    // void _update();
    // void _fixedUpdate();

private:
    entt::registry m_registry;
};