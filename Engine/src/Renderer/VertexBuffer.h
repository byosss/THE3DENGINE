#pragma once

#include <glad/glad.h>

#include <cstddef>

class VertexBuffer
{
public:
    VertexBuffer(const void* data, std::size_t size);
    ~VertexBuffer();

    GLuint getId() const;

private:
    GLuint m_id;
};