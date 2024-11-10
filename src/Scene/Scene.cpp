#include "Scene/Scene.h"

void Scene::addEntity(std::unique_ptr<Entity> entity)
{
    entities.push_back(std::move(entity));
}

void Scene::removeEntity(Entity* entity)
{
    auto it = std::find_if(entities.begin(), entities.end(), [entity](const std::unique_ptr<Entity>& e) {
        return e.get() == entity;
    });

    if (it != entities.end())
    {
        entities.erase(it);
    }
}

void Scene::update( TimeManager& time, EventManager& event )
{
    for (auto& system : systems)
    {
        system->update( entities, time, event );
    }
}

void Scene::addSystem(std::unique_ptr<System> system)
{
    systems.push_back(std::move(system));
}