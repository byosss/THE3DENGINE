#pragma once

// #include <assimp/Importer.hpp>
// #include <assimp/scene.h>
// #include <assimp/postprocess.h>

#include "Resource.h"
#include "Mesh.h"

class Model : public Resource {
public:
    ~Model() {
        // Release model data
        // ...
    }

    void load(const std::string& filePath) override {
        // Load model from file
        // ...
    }

private:
    std::vector<Mesh> m_meshes;
    std::vector<Material> m_materials;
};