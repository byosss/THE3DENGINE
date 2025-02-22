#include "SceneManager.h"

#include "Components/TransformComponent.h"

void SceneManager::load() 
{
    // Create a camera entity
    auto camera = createEntity();

    // Add a transform component to the camera entity
    TransformComponent cameraTransform;
    cameraTransform.px = 0.0f;
    cameraTransform.py = 0.0f;
    cameraTransform.pz = 0.0f;
    cameraTransform.rx = 0.0f;
    cameraTransform.ry = 0.0f;
    cameraTransform.rz = 0.0f;
    cameraTransform.sx = 1.0f;
    cameraTransform.sy = 1.0f;
    cameraTransform.sz = 1.0f;

    // Add the transform component to the camera entity
    m_registry.emplace<TransformComponent>( camera, cameraTransform );
}

void SceneManager::setup( TimeManager& Time, EventManager& Event, InputManager& Input ) {
    // Setup the scene
}

void SceneManager::update( TimeManager& Time, EventManager& Event, InputManager& Input ) {
    // Update game logic
}

entt::entity SceneManager::createEntity( entt::entity parent, bool isStatic ) {
    // Create an entity
    auto entity = m_registry.create();

    // Add entity data
    m_entityData[entity] = { parent, {}, true, isStatic };

    // Return the entity
    return entity;
}

void SceneManager::destroyEntity( entt::entity entity ) {
    // Destroy an entity
    m_registry.destroy( entity );

    // Remove entity data
    m_entityData.erase( entity );
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

void SceneManager::addChild( entt::entity parent, entt::entity child ) {
    // Add a child to an entity
    m_entityData[parent].children.push_back( child );
    m_entityData[child].parent = parent;
}

void SceneManager::removeChild( entt::entity parent, entt::entity child ) {
    // Remove a child from an entity
    m_entityData[parent].children.erase( std::remove( m_entityData[parent].children.begin(), m_entityData[parent].children.end(), child ), m_entityData[parent].children.end() );
    m_entityData[child].parent = entt::null;
}

entt::entity SceneManager::getParent( entt::entity child ) {
    // Get the parent of an entity
    return m_entityData[child].parent;
}

void SceneManager::setParent( entt::entity parent, entt::entity child ) {
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
    // Check if an entity is static
    return m_entityData[entity].isStatic;
}

void SceneManager::setStatic( entt::entity entity, bool isStatic ) {
    // Set an entity to be static
    m_entityData[entity].isStatic = isStatic;
}
