#pragma once

#include "Component.h"

struct Transform : public Component
{
    float x, y, z;

    Transform() : x(0), y(0), z(0) {}
    Transform(float x, float y, float z) : x(x), y(y), z(z) {}
};