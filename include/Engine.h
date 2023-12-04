#pragma once

#include <iostream>
#include <vector>

#include "Object.h"
#include "Camera.h"
#include "Model.h"


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
GLFWwindow* window;

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

