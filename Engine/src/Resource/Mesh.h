#pragma once

#include <string>
#include <vector>

#include "Texture.h"

struct Vertex {
    float px, py, pz; // Position
    float nx, ny, nz; // Normal
    float tx, ty;     // Texture coordinates
};

struct Material {
    float albedo[3];
    float metallic;
    float roughness;
    float ao;

    // std::shared_ptr<Texture> albedoMap;
    // std::shared_ptr<Texture> metallicMap;
    // std::shared_ptr<Texture> roughnessMap;
    // std::shared_ptr<Texture> aoMap;
    // std::shared_ptr<Texture> normalMap;
};

class Mesh
{
public:
    Mesh( std::vector<Vertex> vertices, std::vector<unsigned int> indices );
    ~Mesh();

    unsigned int id;
};