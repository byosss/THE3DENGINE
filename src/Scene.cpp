#include "Scene.h"

#include <string.h>

Scene::Scene(char sceneName[], char filePath[])
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

Scene::Scene(char sceneName[], Object *rootObject)
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


void Scene::loadScene(char filePath[])
{

}

void Scene::loadScene(Object *object)
{
    this->rootObject = rootObject;
}