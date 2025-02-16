#pragma once

#include <vector>
#include <unordered_map>

#include <entt/entity/registry.hpp>

#include "Physics/Physics.h"
#include "Renderer/Renderer.h"

struct EntityData {
    entt::entity parent = entt::null;
    std::vector<entt::entity> children;
    bool isActive = true;
    bool isStatic = false;
};

class Scene {
public:
    void load();     // Load the scene 

    void setup();    // Setup the scene
    void update();   // Update game logic
    void simulate(); // Simulate physics
    void draw();     // Draw the scene

    // Entity management
    entt::entity createEntity( entt::entity parent = entt::null, bool isStatic = false );
    void destroyEntity( entt::entity entity );

    std::vector<entt::entity> getChildren( entt::entity parent );
    void addChild( entt::entity parent, entt::entity child );
    void removeChild( entt::entity parent, entt::entity child );

    entt::entity getParent( entt::entity child );
    void setParent( entt::entity parent, entt::entity child );
    void removeParent( entt::entity child );

    bool isStatic( entt::entity entity );
    void setStatic( entt::entity entity, bool isStatic );

    entt::registry& getRegistry() { return m_registry; }

private:
    entt::registry m_registry;
    std::unordered_map<entt::entity, EntityData> m_entityData;
};

