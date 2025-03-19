#include "Renderer/IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, std::size_t size) : count(size / sizeof(unsigned int))
{
    glCreateBuffers(1, &m_id);
    glNamedBufferData(m_id, size, data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_id);
}

GLuint IndexBuffer::getId() const
{
    return m_id;
}

std::size_t IndexBuffer::getCount() const
{
    return count;
}
