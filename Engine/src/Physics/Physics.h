#pragma once

#include <entt/entity/registry.hpp>

namespace Physics {

    // update the position of all entities based on the applied forces
    void update_position( entt::registry& registry );

    // check for collisions between entities
    void check_collisions( entt::registry& registry );

    // resolve collisions between entities
    void resolve_collisions( entt::registry& registry );
    
}