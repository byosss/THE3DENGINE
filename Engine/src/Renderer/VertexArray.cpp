#include "Renderer/VertexArray.h"

#include <glad/glad.h>

#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"

VertexArray::VertexArray()
{
    glCreateVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_id);
}

void VertexArray::addVertexBuffer(GLuint id, GLuint binding, GLenum type, GLint size, bool normalized)
{
    glEnableVertexArrayAttrib(m_id, binding);
    glVertexArrayAttribBinding(m_id, id, binding);
    glVertexArrayAttribFormat(m_id, binding, 3, type, normalized, 0);
    glVertexArrayVertexBuffer(m_id, binding, id, 0, size);
}

void VertexArray::setIndexBuffer(GLuint id)
{
    glVertexArrayElementBuffer(m_id, id);
}