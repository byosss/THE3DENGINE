#pragma once

#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "Entity.h"
#include "Systems/System.h"

#include "TimeManager.h"
#include "EventManager.h"

class Scene
{
public:
    void addEntity(std::unique_ptr<Entity> entity);
    void removeEntity(Entity* entity);
    void update( TimeManager& time, EventManager& event );
    void addSystem(std::unique_ptr<System> system);

private:
    std::string name;
    std::vector<std::unique_ptr<Entity>> entities;
    std::vector<std::unique_ptr<System>> systems;
};