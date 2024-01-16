#ifndef LIGHT_H
#define LIGHT_H

#include "Objects/Node.h"

class Light : public Node
{
public:
    glm::vec3 color;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    float constant;
    float linear;
    float quadratic;

    Light();
};

#endif