#pragma once

#include "Resource.h"

// #include <stb_image.h>

class Texture : public Resource {
public:
    ~Texture() {
        // Release texture data
        // ...
    }

    void load(const std::string& filePath) override {
        // Load texture from file
        // ...
    }

private:
    unsigned char* data;
    int width, height;
    int nrChannels;
};