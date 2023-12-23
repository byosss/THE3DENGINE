#pragma once

#include <iostream>
#include <vector>

#include "Scene.h"

#include "Objects/Object.h"
#include "Objects/Node.h"
#include "Objects/Camera.h"
#include "Objects/Model3D.h"
#include "Objects/Light.h"

class Engine 
{
public:

    TimeManager* Time;
    InputManager* Input;
    Shader* shader;

    std::vector<Object*> objects;

    void innit();
    void run();
    void terminate();

    void setActiveCamera(Camera*);
    Camera* getActiveCamera();

private:

    Camera* activeCamera;

    void update();
    void draw();
};
