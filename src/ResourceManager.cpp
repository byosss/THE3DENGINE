#include "ResourceManager.h"

std::shared_ptr<Shader> ResourceManager::loadShader(std::string vertexPath, std::string fragmentPath) {
    if (shaders.find(vertexPath + fragmentPath) == shaders.end()) {
        shaders[vertexPath + fragmentPath] = std::make_shared<Shader>(vertexPath, fragmentPath);
    }
    return shaders[vertexPath + fragmentPath];
}

std::shared_ptr<Texture> ResourceManager::loadTexture(std::string path) {
    if (textures.find(path) == textures.end()) {
        textures[path] = std::make_shared<Texture>(path);
    }
    return textures[path];
}

void ResourceManager::Clear() {
    shaders.clear();
    textures.clear();
}
