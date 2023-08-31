#pragma once

#include <glad/glad.h>

#include <iostream>

class Texture
{
public:
    // the texture ID
    unsigned int ID;

    // constructor reads and parse the texture
    Texture(const char* texturePath);

    void use();
};