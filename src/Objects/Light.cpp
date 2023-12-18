#include "Objects/Light.h"

Light::Light() {
    this->position = glm::vec3(0.0, 0.0, 0.0);
    this->rotation = glm::vec3(0.0, 0.0, 0.0);
    this->scale    = glm::vec3(1.0, 1.0, 1.0);

    this->color    = glm::vec3(1.0, 1.0, 1.0);
}

// method called once at start
void Light::_ready(TimeManager* Time, InputManager* Input)
{
}

// method called each frame
void Light::_process(TimeManager* Time, InputManager* Input)
{
}

void Light::render(Shader*)
{
}