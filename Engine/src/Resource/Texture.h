#pragma once

#include <string>

class Texture
{
public:
    Texture( const std::string& filename );
    ~Texture();

    unsigned int id;
};