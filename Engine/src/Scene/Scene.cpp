#include "Scene.h"

#include "Components/TransformComponent.h"

void Scene::load() 
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

void Scene::setup() {
    // Setup the scene
}

void Scene::update() {
    // Update game logic
}

void Scene::simulate() 
{
    Physics::update_position( m_registry );

    Physics::check_collisions( m_registry );

    Physics::resolve_collisions( m_registry );
}

void Scene::draw() {
    // Draw the scene
    Renderer::clear();
}

entt::entity Scene::createEntity( entt::entity parent, bool isStatic ) {
    // Create an entity
    auto entity = m_registry.create();

    // Add entity data
    m_entityData[entity] = { parent, {}, true, isStatic };

    // Return the entity
    return entity;
}

void Scene::destroyEntity( entt::entity entity ) {
    // Destroy an entity
    m_registry.destroy( entity );

    // Remove entity data
    m_entityData.erase( entity );
}

std::vector<entt::entity> Scene::getChildren( entt::entity parent ) {
    // Get the children of an entity
    std::vector<entt::entity> children;

    for ( auto& [entity, data] : m_entityData ) {
        if ( data.parent == parent ) {
            children.push_back( entity );
        }
    }

    return children;
}

void Scene::addChild( entt::entity parent, entt::entity child ) {
    // Add a child to an entity
    m_entityData[parent].children.push_back( child );
    m_entityData[child].parent = parent;
}

void Scene::removeChild( entt::entity parent, entt::entity child ) {
    // Remove a child from an entity
    m_entityData[parent].children.erase( std::remove( m_entityData[parent].children.begin(), m_entityData[parent].children.end(), child ), m_entityData[parent].children.end() );
    m_entityData[child].parent = entt::null;
}

entt::entity Scene::getParent( entt::entity child ) {
    // Get the parent of an entity
    return m_entityData[child].parent;
}

void Scene::setParent( entt::entity parent, entt::entity child ) {
    // Set the parent of an entity
    m_entityData[child].parent = parent;
    m_entityData[parent].children.push_back( child );
}

void Scene::removeParent( entt::entity child ) {
    // Remove the parent of an entity
    m_entityData[m_entityData[child].parent].children.erase( std::remove( m_entityData[m_entityData[child].parent].children.begin(), m_entityData[m_entityData[child].parent].children.end(), child ), m_entityData[m_entityData[child].parent].children.end() );
    m_entityData[child].parent = entt::null;
}

bool Scene::isStatic( entt::entity entity ) {
    // Check if an entity is static
    return m_entityData[entity].isStatic;
}

void Scene::setStatic( entt::entity entity, bool isStatic ) {
    // Set an entity to be static
    m_entityData[entity].isStatic = isStatic;
}
