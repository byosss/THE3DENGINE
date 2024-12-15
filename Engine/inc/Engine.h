#pragma once

#include <iostream>
#include <chrono>

#include "glad/glad.h"

class Engine {
public:
    void init();
    void terminate();

    void update();
    void draw();

private:
    float R, G, B;
};
