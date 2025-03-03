#pragma once

#include <iostream>

#include "Renderer/IIndexBuffer.h"

class OpenglIndexBuffer : public IIndexBuffer {
public:
    OpenglIndexBuffer() = default;
    ~OpenglIndexBuffer() override = default;

    void load(const void* data, std::size_t size) override {
        std::cout << "OpenglIndexBuffer::load" << std::endl;
    }

    std::size_t size() const override {
        std::cout << "OpenglIndexBuffer::size" << std::endl;
        return 0;
    }
};