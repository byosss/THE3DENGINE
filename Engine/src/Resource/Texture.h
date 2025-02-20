#pragma once

#include <iostream>
#include <string>

#include "Resource.h"

class Texture : public Resource {
public:
    explicit Texture(const std::string& path) {
        std::cout << "Chargement de la texture : " << path << std::endl;
    }
    ~Texture() {
        std::cout << "Destruction de la texture" << std::endl;
    }

private:
    // Texture data
    int id;
};