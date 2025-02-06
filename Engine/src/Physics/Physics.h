#pragma once

namespace Physics {

    // update the position of all entities based on the applied forces
    void update_position();

    // check for collisions between entities
    void check_collisions();

    // resolve collisions between entities
    void resolve_collisions();
    
}