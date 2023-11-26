#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Model
{
public:
    GLuint VAO;
    unsigned int sizei;

    Model();
    ~Model();

private:
    GLuint VBO, EBO;

    void load_house();
    void load_cube();
};