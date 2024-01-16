#ifndef NODE_H
#define NODE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "TimeManager.h"
#include "InputManager.h"

#include <vector>

class Node
{
public:

    // Attributs communs à toutes les sous-classes
    glm::vec3 position;  // ( x, y, z)
    glm::vec3 rotation;  // ( Pitch, Yaw, Roll )
    glm::vec3 scale;     // ( x, y, z)

    Node();
};

#endif