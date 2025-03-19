#pragma once

#include <glad/glad.h>

class ShaderProgram
{
public:
    ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
    ~ShaderProgram();

    void bind() const;
    void unbind() const;

    GLuint getId() const;

private:
    GLuint m_id;
};