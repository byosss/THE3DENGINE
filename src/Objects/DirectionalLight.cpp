#include "Objects/DirectionalLight.h"

DirectionalLight::DirectionalLight() 
{
    this->color = glm::vec3(1.0f, 1.0f, 1.0f);
    this->direction = glm::vec3(-0.2f, -1.0f, -0.3f);

    this->ambient  = glm::vec3(0.05f, 0.05f, 0.05f);
    this->diffuse  = glm::vec3(0.4f, 0.4f, 0.4f);
    this->specular = glm::vec3(0.5f, 0.5f, 0.5f);
}
