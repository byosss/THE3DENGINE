#pragma once

#include <glm/gtc/matrix_transform.hpp>

#include "Objects/Node.h"
#include "Shader.h"


class Model3D : public Node
{
public:
    Model3D();
    ~Model3D();

    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;
    void render() override;

    GLuint getVAO();
    unsigned int getSizei();

    void setShader(const char*, const char*);

private:
    GLuint VAO, VBO, EBO;

    unsigned int sizei;

    Shader shader;

    void load_cube();
};