#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <string>
#include <vector>
#include <iostream>

class Texture
{
public:
    GLuint id;
    std::string type; // ambientTexture, diffuseTexture, specularTexture
    std::string path;

    Texture();
    Texture(std::string Path);
    void load(std::string Path);
    void loadCubemap(std::vector<std::string> faces);
};


#endif