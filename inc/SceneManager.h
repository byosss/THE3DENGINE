#pragma once

#include <string>
#include <memory>

#include "Scene/Scene.h"

class SceneManager {
public:
    void loadScene();
    Scene* getCurrentScene() const;

private:
    std::unique_ptr<Scene> currentScene;
};
