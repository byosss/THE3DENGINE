#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include "Resource.h"

class Shader : public Resource {
public:
    ~Shader() override = default;

    void load(const std::string& filePath) override 
    {
        // Load shader code from file
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        std::stringstream stream;
        stream << file.rdbuf();
        shaderCode = stream.str();

        file.close();
    }

    const std::string& getCode() const {
        return shaderCode;
    }

private:
    std::string shaderCode;
};

