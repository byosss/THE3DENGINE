#pragma once

#include <span>

struct Mesh
{
    std::span<float> positions;
    std::span<float> normals;
    std::span<float> uvs;
    std::span<unsigned int> indices;
};