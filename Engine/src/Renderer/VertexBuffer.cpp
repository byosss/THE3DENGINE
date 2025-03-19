#include "Renderer/VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, std::size_t size)
{
    glCreateBuffers(1, &m_id);
    glNamedBufferData(m_id, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_id);
}

GLuint VertexBuffer::getId() const
{
    return m_id;
}