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

    bool load(const std::string& path) override {
        // Load model from file
        // ...
        return true;
    }


private:
    std::vector<Mesh> m_meshes;
};