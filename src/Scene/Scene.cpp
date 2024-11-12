#include "Scene/Scene.h"

#include "Scene/Systems/Gravity.h"

void Scene::load()
{
    Entity* entity = new Entity("Entity");
    entity->addComponent(std::make_unique<Transform>());
    this->addEntity(std::unique_ptr<Entity>(entity));

    Entity* entity2 = new Entity("Entity2");
    entity2->addComponent(std::make_unique<Transform>());
    this->addEntity(std::unique_ptr<Entity>(entity2));

    this->addSystem(std::make_unique<Gravity>());
}

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