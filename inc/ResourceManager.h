#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include "Resources/Shader.h"
#include "Resources/Texture.h"

class ResourceManager {
public:
    std::shared_ptr<Shader> loadShader(std::string vertexPath, std::string fragmentPath);
    std::shared_ptr<Texture> loadTexture(std::string path);
    
    void Clear();

private:
    std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
    std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
};