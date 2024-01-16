#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "Objects/Node.h"

class SpotLight : public Node
{
public:
    glm::vec3 color;
    glm::vec3 direction;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    float constant;
    float linear;
    float quadratic;

    float cutOff;
    float outerCutOff;

    SpotLight();
};

#endif