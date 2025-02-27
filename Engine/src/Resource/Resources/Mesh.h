#pragma once

#include <vector>

#include "Resource.h"
#include "Material.h"

struct Vertex {
    float px, py, pz; // Position
    float nx, ny, nz; // Normal
    float tx, ty;     // Texture coordinates
};

class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const Material& material) {
        // Generate vertex array object
    }
    ~Mesh() {
        // Delete vertex array object
    }

    Material material;
};