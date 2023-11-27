#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Object.h"
#include "TimeManager.h"
#include "InputManager.h"

class Model : public Object
{
public:
    GLuint VAO;
    unsigned int sizei;

    Model();
    ~Model();

    void _ready(TimeManager&, InputManager&) override;
    void _process(TimeManager&, InputManager&) override;

private:
    GLuint VBO, EBO;

    void load_house();
    void load_cube();
};