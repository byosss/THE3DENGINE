#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "Resource.h"
#include "Texture.h"
#include "Shader.h"
#include "Model.h"

class ResourceManager {
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    // Fonction générique pour charger toutes les ressources, sans avoir à fournir d'ID
    template <typename T, typename... Args>
    std::shared_ptr<T> load(Args&&... args) {
        // Utilise les arguments pour générer une clé unique (ici basée sur le chemin)
        std::string key = generateKey(std::forward<Args>(args)...);

        // Vérifie si la ressource a déjà été chargée
        if (resources.find(key) != resources.end()) {
            return std::static_pointer_cast<T>(resources[key]);
        }

        // Crée la ressource, l'ajoute au gestionnaire et retourne le pointeur partagé
        std::shared_ptr<T> resource = std::make_shared<T>(std::forward<Args>(args)...);
        resources[key] = resource;
        return resource;
    }

    // Fonction pour netttoyer une ressource spécifique
    void clear(const std::string& key) {
        resources.erase(key);
    }

    // Méthode pour nettoyer toutes les ressources
    void clearAll() {
        resources.clear();
    }

private:
    ResourceManager() = default;
    ~ResourceManager() = default;

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    // Map pour stocker toutes les ressources, utilisant une clé unique par ressource
    std::unordered_map<std::string, std::shared_ptr<Resource>> resources;

    // Générateur de clé unique basé sur les arguments (path de fichiers ou autres)
    template <typename... Args>
    std::string generateKey(Args&&... args) {
        // Pour simplifier, on génère une clé unique à partir du premier argument (le chemin de fichier)
        return generateKeyFromArgs(std::forward<Args>(args)...);
    }

    // Génération de clé à partir d'un seul argument (par exemple un chemin de fichier)
    std::string generateKeyFromArgs(const std::string& arg) {
        return arg;
    }

    // Si on veut générer une clé à partir de plusieurs arguments (par exemple pour les shaders)
    std::string generateKeyFromArgs(const std::string& vertexPath, const std::string& fragmentPath) {
        return vertexPath + "|" + fragmentPath;
    }
};