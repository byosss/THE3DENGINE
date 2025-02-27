#pragma once

#include "Resource.h"

class Shader : public Resource {
public:
    ~Shader() {
        // Release shader data
    }

    bool load(const std::string& path) override {
        // Load shader from file
        // ...
        return true;
    }

private:
    std::string shaderCode;
};

