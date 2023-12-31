#ifndef OBJECT_H
#define OBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "TimeManager.h"
#include "InputManager.h"

#include <vector>

class Object {
public:

    // Enfants de l'objet
    std::vector<Object*> children;

    // method called once at start
    virtual void _ready(TimeManager*, InputManager*) = 0;
    // method called each frame
    virtual void _process(TimeManager*, InputManager*) = 0;
    // method called each frame
    virtual void render() = 0;

    void addChild(Object* child);
};

#endif