#ifndef SCENE_H
#define SCENE_H

#include "Objects/Object.h"

class Scene
{
private:
    char name[50];
    Object *rootObject;

public:
    Scene(char sceneName[], char filePath[]);
    Scene(char sceneName[], Object *object);

    void loadScene(char filePath[]);
    void loadScene(Object *object);
};

#endif