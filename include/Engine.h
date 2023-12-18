#pragma once

#include <iostream>
#include <vector>

#include "Objects/Object.h"
#include "Objects/Camera.h"
#include "Objects/Model3D.h"

class Engine 
{
public:

    TimeManager* Time;
    InputManager* Input;
    Shader* shader;

    std::vector<Object*> objects;

    Engine();

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

