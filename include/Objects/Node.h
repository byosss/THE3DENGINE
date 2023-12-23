#ifndef NODE_H
#define NODE_H

#include "Objects/Object.h"

class Node : public Object
{
public:

    // Attributs communs à toutes les sous-classes
    glm::vec3 position;  // ( x, y, z)
    glm::vec3 rotation;  // ( Pitch, Yaw, Roll )
    glm::vec3 scale;     // ( x, y, z)

    Node();

    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;
    void render() override;
};

#endif