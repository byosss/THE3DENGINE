#include "SceneManager.h"

#include "Components/Transform.h"

void SceneManager::setup( TimeManager& Time, EventManager& Event, InputManager& Input ) {
    // Setup the scene
}

void SceneManager::update( TimeManager& Time, EventManager& Event, InputManager& Input ) {
    // Update game logic
}

entt::entity SceneManager::createEntity( entt::entity parent, bool isActive, bool isStatic ) {

    // Create an entity
    auto entity = m_registry.create();

    // Add entity data
    EntityData entityData;
    entityData.parent = parent;
    entityData.children = {};
    entityData.isActive = isActive;
    entityData.isStatic = isStatic;

    // Add the entity data to the entity
    m_entityData[entity] = entityData;

    // Create a transform component
    Transform transform;
    transform.px = 0.0f;
    transform.py = 0.0f;
    transform.pz = 0.0f;
    transform.rx = 0.0f;
    transform.ry = 0.0f;
    transform.rz = 0.0f;
    transform.sx = 1.0f;
    transform.sy = 1.0f;
    transform.sz = 1.0f;

    // Add the transform component to the entity
    m_registry.emplace<Transform>( entity, transform );

    // Return the entity
    return entity;
}

void SceneManager::destroyEntity( entt::entity entity ) {
    // Destroy an entity
    m_registry.destroy( entity );

    // Remove entity data
    m_entityData.erase( entity );

    // Remove the entity linked to the entity
    // todo
}

std::vector<entt::entity> SceneManager::getChildren( entt::entity parent ) {
    // Get the children of an entity
    std::vector<entt::entity> children;

    for ( auto& [entity, data] : m_entityData ) {
        if ( data.parent == parent ) {
            children.push_back( entity );
        }
    }

    return children;
}

void SceneManager::addChild( entt::entity child, entt::entity parent ) {
    // Add a child to an entity
    m_entityData[parent].children.push_back( child );
    m_entityData[child].parent = parent;
}

void SceneManager::removeChild( entt::entity child, entt::entity parent ) {
    // Remove a child from an entity
    m_entityData[parent].children.erase( std::remove( m_entityData[parent].children.begin(), m_entityData[parent].children.end(), child ), m_entityData[parent].children.end() );
    m_entityData[child].parent = entt::null;
}

entt::entity SceneManager::getParent( entt::entity child ) {
    // Get the parent of an entity
    return m_entityData[child].parent;
}

void SceneManager::setParent( entt::entity child, entt::entity parent ) {
    // Set the parent of an entity
    m_entityData[child].parent = parent;
    m_entityData[parent].children.push_back( child );
}

void SceneManager::removeParent( entt::entity child ) {
    // Remove the parent of an entity
    m_entityData[m_entityData[child].parent].children.erase( std::remove( m_entityData[m_entityData[child].parent].children.begin(), m_entityData[m_entityData[child].parent].children.end(), child ), m_entityData[m_entityData[child].parent].children.end() );
    m_entityData[child].parent = entt::null;
}

bool SceneManager::isStatic( entt::entity entity ) {
    return m_entityData[entity].isStatic;
}

void SceneManager::setStatic( entt::entity entity, bool isStatic ) {
    m_entityData[entity].isStatic = isStatic;
}

bool SceneManager::isActive( entt::entity entity ) {
    return m_entityData[entity].isActive;
}

void SceneManager::setActive( entt::entity entity, bool isActive ) {
    m_entityData[entity].isActive = isActive;
}