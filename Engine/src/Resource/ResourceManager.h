#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include "Resources/Resource.h"
#include "Resources/Texture.h"
#include "Resources/Shader.h"
#include "Resources/Model.h"

class ResourceManager {
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    template<typename T>
    std::shared_ptr<T> load(const std::string& path) {

        // Trouver le chemin absolu de la ressource
        // todo...

        // Vérifier si la ressource est déjà chargée
        auto it = m_resources.find(path);
        if (it != m_resources.end()) {
            return std::static_pointer_cast<T>(it->second);
        }

        // Charger la ressource depuis le stockage
        auto resource = std::make_shared<T>();
        if (!resource->load(path)) {
            return nullptr;
        }

        // Stocker la ressource dans le cache
        m_resources[path] = resource;
        return resource;
    }

    void unload(const std::string& path) {
        auto it = m_resources.find(path);
        if (it != m_resources.end()) {
            m_resources.erase(it);
        }
    }

    void unloadAll() {
        m_resources.clear();
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Resource>> m_resources;
};