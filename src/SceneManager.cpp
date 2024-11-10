#include "SceneManager.h"

#include "Scene/Systems/Gravity.h"

void SceneManager::loadScene() {
    // Crée une nouvelle scène avec le nom fourni
    std::unique_ptr<Scene> newScene = std::make_unique<Scene>();
    
    // Charger la scène (par exemple, ajouter des entités, etc.)
    Entity* entity = new Entity("Entity");
    entity->addComponent(std::make_unique<Transform>());
    newScene->addEntity(std::unique_ptr<Entity>(entity));

    Entity* entity2 = new Entity("Entity2");
    entity2->addComponent(std::make_unique<Transform>());
    newScene->addEntity(std::unique_ptr<Entity>(entity2));

    newScene->addSystem(std::make_unique<Gravity>());
    
    // Changer la scène actuelle
    currentScene = std::move(newScene);
}

Scene* SceneManager::getCurrentScene() const {
    return currentScene.get();
}
