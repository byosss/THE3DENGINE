#ifndef LIGHT_H
#define LIGHT_H

#include "Objects/Object.h"

class Light : public Object
{
public:
    glm::vec3 color;

    Light();
    
    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;
    void render(Shader*) override;
};


#endif