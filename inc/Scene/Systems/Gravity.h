#pragma once

#include "System.h"

class Gravity : public System
{
public:
    void update( std::vector<std::unique_ptr<Entity>>& entities, TimeManager& time, EventManager& event ) override {
        for (auto& entity : entities)
        {
            auto transform = entity->getComponent<Transform>();
            if (transform)
            {
                transform->y -= 9.8f * time.getDeltaTime();
            }
        }
    }
};