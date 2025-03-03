#pragma once

#include <cstddef>

class IIndexBuffer {
public:
    virtual ~IIndexBuffer() = default;

    virtual void load(const void* data, std::size_t size) = 0;
    virtual std::size_t size() const = 0;
};
