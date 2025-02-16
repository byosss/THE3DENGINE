#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "Mesh.h"
#include "Texture.h"

class ResourceManager
{
public:
    static ResourceManager& getInstance();

    std::shared_ptr<Texture> loadTexture(const std::string& path);
    std::shared_ptr<Mesh> loadMesh(const std::string& path);

private:
    ResourceManager();
    ~ResourceManager() = default;

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    std::unordered_map<std::string, std::shared_ptr<Mesh>> m_meshes;
    std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
};