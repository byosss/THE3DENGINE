#pragma once

#include <glad/glad.h>

#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void addVertexBuffer(GLuint id, GLuint binding, GLenum type, GLint size, bool normalized);
    void setIndexBuffer(GLuint id);

    void bind() const;
    void unbind() const;

private:
    GLuint m_id;
};
