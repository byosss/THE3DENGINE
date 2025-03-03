#pragma once

#include <cstddef>

class IVertexBuffer {
public:
    virtual ~IVertexBuffer() = default;

    virtual void load(const void* data, std::size_t size) = 0;
    virtual std::size_t size() const = 0;
};
