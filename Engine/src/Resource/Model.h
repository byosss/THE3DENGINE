#pragma once

#include <iostream>
#include <string>

#include "Resource.h"
#include "Mesh.h"

class Model : public Resource {
public:
    explicit Model(const std::string& path) {
        // Load model from file
        // ...
        std::cout << "Chargement du model 3d : " << path << std::endl;
    }
    ~Model() {
        // Release model data
        // ...
        std::cout << "Destruction du model 3d" << std::endl;
    }

private:
    std::vector<Mesh> m_meshes;
};