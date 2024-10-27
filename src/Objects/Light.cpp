#include "Objects/Light.h"

Light::Light() 
{
    this->color = glm::vec3(1.0f, 1.0f, 1.0f);

    this->ambient  = glm::vec3(0.05f, 0.05f, 0.05f);
    this->diffuse  = glm::vec3(0.8f, 0.8f, 0.8f);
    this->specular = glm::vec3(1.0f, 1.0f, 1.0f);

    this->constant  = 1.0f;
    this->linear    = 0.09f;
    this->quadratic = 0.032f;
}

// method called once at start
void Light::_ready(TimeManager* Time, InputManager* Input)
{
}

// method called each frame
void Light::_process(TimeManager* Time, InputManager* Input)
{
}