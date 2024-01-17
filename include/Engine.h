#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <vector>

#include "Objects/Node.h"
#include "Objects/Camera.h"
#include "Objects/Model3D.h"
#include "Objects/Light.h"
#include "Objects/DirectionalLight.h"
#include "Objects/SpotLight.h"
#include "Objects/Skybox.h"

class Engine 
{
public:

    TimeManager* Time;
    InputManager* Input;

    Camera* activeCamera;
    Skybox* skybox;

    std::vector<Model3D*> Models3D;
    std::vector<Light*> Lights;
    std::vector<DirectionalLight*> dirLights;
    std::vector<SpotLight*> spotLights;

    void innit();
    void run();
    void terminate();

    bool cube2;
    bool cube4;
    bool newLight;
    bool delLight;

private:

    void loadScene();
    void update();
    void draw();
};

#endif