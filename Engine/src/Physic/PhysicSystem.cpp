#include "PhysicSystem.h"

namespace PhysicSystem 
{
    void simulate( entt::registry& registry ) 
    {
        update_position( registry );
        check_collisions( registry );
        resolve_collisions( registry );
    }

    void update_position( entt::registry& registry ) {
        // update the position of all entities based on the applied forces
    }

    void check_collisions( entt::registry& registry ) {
        // check for collisions between entities
    }

    void resolve_collisions( entt::registry& registry ) {
        // resolve collisions between entities
    }
}