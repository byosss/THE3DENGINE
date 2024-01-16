#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "Objects/Node.h"

class DirectionalLight : public Node
{
public:
    glm::vec3 color;
    glm::vec3 direction;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    DirectionalLight();
};

#endif