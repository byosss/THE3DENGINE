#include "Scene.h"

#include <string.h>

Scene::Scene(const char sceneName[], const char filePath[])
{
    int i = 0;
    while(sceneName[i] != '\0' and i < 50)
    {
        this->name[i] = sceneName[i];
        i++;
    }
    this->name[i] = '\0';

    loadScene(filePath);
}

Scene::Scene(const char sceneName[], Object *rootObject)
{
    int i = 0;
    while(sceneName[i] != '\0' and i < 50)
    {
        this->name[i] = sceneName[i];
        i++;
    }
    this->name[i] = '\0';

    loadScene(rootObject);
}


void Scene::loadScene(const char filePath[])
{

}

void Scene::loadScene(Object *object)
{
    this->rootObject = object;
}

void Scene::addChild(Object* parent, Object* child) {
    if (parent != nullptr && child != nullptr) {

        parent->children.push_back(child);

        if (dynamic_cast<Model3D*>(child) != nullptr) {
            Models3D.push_back(dynamic_cast<Model3D*>(child));
        } 
        else if (dynamic_cast<Light*>(child) != nullptr) {
            Lights.push_back(dynamic_cast<Light*>(child));
        }
    }
}


void Scene::_readyObjects(TimeManager* Time, InputManager* Input) {
    if (rootObject != nullptr) {
        _readyRecursive(rootObject, Time, Input);
    }
}

void Scene::_processObjects(TimeManager* Time, InputManager* Input) {
    if (rootObject != nullptr) {
        _processRecursive(rootObject, Time, Input);
    }
}

void Scene::_readyRecursive(Object* obj, TimeManager* Time, InputManager* Input) {

    obj->_ready(Time, Input);

    for (Object* child : obj->children) {
        _readyRecursive(child, Time, Input);
    }
}

void Scene::_processRecursive(Object* obj, TimeManager* Time, InputManager* Input) {
    obj->_process(Time, Input);

    for (Object* child : obj->children) {
        _processRecursive(child, Time, Input);
    }
}


void Scene::setActiveCamera(Camera* camera)
{
    this->activeCamera = camera;
}

Camera* Scene::getActiveCamera()
{
    return this->activeCamera;
}

