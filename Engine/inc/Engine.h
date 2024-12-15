#pragma once

#include <iostream>

#include "glad.h"

#include "TimeManager.h"

class Engine {
public:
    Engine();

    void init();
    void terminate();

    void update();
    void draw();

private:
    float R, G, B;

    TimeManager Time;
};
