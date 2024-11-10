#pragma once

#include <string>

#include <glad/glad.h>

class Texture
{
public:
    Texture(std::string path);
    ~Texture();

    GLuint getID() const;

private:
    GLuint id;
};