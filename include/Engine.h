#ifndef ENGINE_H
#define ENGINE_H

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

    Scene* mainMap;

    void innit();
    void run();
    void terminate();

private:

    void update();
    void draw();
};

#endif