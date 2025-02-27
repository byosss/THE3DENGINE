#pragma once

#include <memory>

#include "Texture.h"

struct Material {
    float albedo[3];
    float metallic;
    float roughness;
    float ao;

    std::shared_ptr<Texture> albedoMap;
    std::shared_ptr<Texture> normalMap;
    std::shared_ptr<Texture> metallicMap;
    std::shared_ptr<Texture> roughnessMap;
    std::shared_ptr<Texture> aoMap;
};