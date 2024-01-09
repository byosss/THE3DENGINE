#ifndef SCENE_H
#define SCENE_H

#include "Objects/Object.h"
#include "Objects/Camera.h"
#include "Objects/Model3D.h"
#include "Objects/Light.h"

class Scene
{
private:
    char name[50];
    Object *rootObject;
    Camera *activeCamera;

    void _readyRecursive(Object* obj, TimeManager*, InputManager*);
    void _processRecursive(Object* obj, TimeManager*, InputManager*);

public:
    
    std::vector<Model3D*> Models3D;
    std::vector<Light*> Lights;

    int numMeshs;
    int numLights;

    Scene(const char sceneName[], const char filePath[]);
    Scene(const char sceneName[], Object *object);

    void loadScene(const char filePath[]);
    void loadScene(Object *object);

    void addChild(Object* parent, Object* child);

    void _readyObjects(TimeManager*, InputManager*);
    void _processObjects(TimeManager*, InputManager*);

    void setActiveCamera(Camera*);
    Camera* getActiveCamera();
};

#endif