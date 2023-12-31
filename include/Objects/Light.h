#ifndef LIGHT_H
#define LIGHT_H

#include "Objects/Node.h"

class Light : public Node
{
public:
    glm::vec3 color;

    Light();
    
    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;
};


#endif