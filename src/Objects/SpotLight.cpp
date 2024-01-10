#include "Objects/SpotLight.h"

SpotLight::SpotLight() 
{
    this->color = glm::vec3(1.0f, 1.0f, 1.0f);
    this->direction = glm::vec3(1.0f, 0.0f, 0.0f);

    this->ambient  = glm::vec3(0.05f, 0.05f, 0.05f);
    this->diffuse  = glm::vec3(0.8f, 0.8f, 0.8f);
    this->specular = glm::vec3(1.0f, 1.0f, 1.0f);

    this->constant  = 1.0f;
    this->linear    = 0.09f;
    this->quadratic = 0.032f;

    this->cutOff      = glm::cos(glm::radians(12.5f));
    this->outerCutOff = glm::cos(glm::radians(15.0f));
}

// method called once at start
void SpotLight::_ready(TimeManager* Time, InputManager* Input)
{
}

// method called each frame
void SpotLight::_process(TimeManager* Time, InputManager* Input)
{
}