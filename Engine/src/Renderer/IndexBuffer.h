#pragma once

#include <glad/glad.h>

#include <cstddef>

class IndexBuffer
{
public:
    IndexBuffer(const unsigned int* data, std::size_t size);
    ~IndexBuffer();

    GLuint getId() const;
    std::size_t getCount() const;

private:
    GLuint m_id;
    std::size_t count;
};