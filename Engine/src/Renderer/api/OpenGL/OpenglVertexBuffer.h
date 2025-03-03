#pragma once

#include <iostream>

#include "Renderer/IVertexBuffer.h"

class OpenglVertexBuffer : public IVertexBuffer {
public:
    OpenglVertexBuffer() = default;
    ~OpenglVertexBuffer() override = default;

    void load(const void* data, std::size_t size) override
    {
        std::cout << "Loading data into OpenGL vertex buffer" << std::endl;
    }

    std::size_t size() const override
    {
        return 0;
    }
};