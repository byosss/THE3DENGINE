#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "TimeManager.h"
#include "InputManager.h"


class Object {
public:

    // Attributs communs à toutes les sous-classes
    glm::vec3 position;  // ( x, y, z)
    glm::vec3 rotation;  // ( Pitch, Yaw, Roll )
    glm::vec3 scale;     // ( x, y, z)

    // Constructeur / Destructeur
    Object();
    virtual ~Object() {}

    // method called once at start
    virtual void _ready(TimeManager*, InputManager*) = 0;
    // method called each frame
    virtual void _process(TimeManager*, InputManager*) = 0;
    // method called each frame
    virtual void render() = 0;

protected:

};