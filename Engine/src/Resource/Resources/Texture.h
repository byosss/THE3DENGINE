#pragma once

#include "Resource.h"

// #include <stb_image.h>

class Texture : public Resource {
public:
    explicit Texture(const std::string& path) {
        // Load texture from file
        // ...
    }
    ~Texture() {
        // Release texture data
        // ...
    }

private:
    unsigned char* data;
    int width, height;
    int nrChannels;
};