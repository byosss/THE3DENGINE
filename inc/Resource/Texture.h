#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <iostream>

unsigned int loadTexture(const char *path);

class Texture
{
public:
    unsigned int ID;

    Texture();
    Texture(char const * path);
    unsigned int loadTexture(char const * path);
};

#endif