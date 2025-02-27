#pragma once

#include "BufferElement.h"

#include <vector>

class BufferLayout
{
public:
    BufferLayout(const std::initializer_list<BufferElement>& elements) : m_Elements(elements), m_Stride(0)
    {
        uint32_t offset = 0;
        for (auto& element : m_Elements)
        {
            element.Offset = offset;
            offset += element.Size;
        }
        m_Stride = offset;
    }

    inline uint32_t GetStride() const { return m_Stride; }
    inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }

private:
    std::vector<BufferElement> m_Elements;
    uint32_t m_Stride;
};

