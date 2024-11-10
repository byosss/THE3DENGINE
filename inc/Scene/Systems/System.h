#pragma once

#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "Scene/Entity.h"

#include "TimeManager.h"
#include "EventManager.h"

#include "Scene/Components/Transform.h"

class System {
public:
    virtual void update( std::vector<std::unique_ptr<Entity>>& entities, TimeManager& time, EventManager& event ) = 0;
};