#pragma once

#include <glm/gtc/matrix_transform.hpp>

#include "Objects/Object.h"


class Model3D : public Object
{
public:
    Model3D();
    ~Model3D();

    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;
    void render(Shader*) override;

    GLuint getVAO();
    unsigned int getSizei();

private:
    GLuint VAO, VBO, EBO;

    unsigned int sizei;

    void load_cube();
};