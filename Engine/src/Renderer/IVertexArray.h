#pragma once

#include <memory>

#include "Renderer/IVertexBuffer.h"
#include "Renderer/IIndexBuffer.h"

enum class VertexAttributeType {
    FLOAT1, FLOAT2, FLOAT3, FLOAT4,
    INT1, INT2, INT3, INT4,
    UINT1, UINT2, UINT3, UINT4,
    MAT2, MAT3, MAT4,
    BOOL
};

class IVertexArray {
public:
    virtual ~IVertexArray() = default;

    virtual void addVertexBuffer(std::shared_ptr<IVertexBuffer> vb, VertexAttributeType type, bool normalized) = 0;
    virtual void setIndexBuffer(std::shared_ptr<IIndexBuffer> ib) = 0;

    virtual void bind() const = 0;
};
