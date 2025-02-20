#pragma once

#include <iostream>
#include <string>

#include "Resource.h"

class Shader : public Resource {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath) {
        std::string vertexCode = loadShaderFromFile(vertexPath);
        std::string fragmentCode = loadShaderFromFile(fragmentPath);
        
        std::cout << "Création du programme shader avec les fichiers : "
                    << vertexPath << " et " << fragmentPath << std::endl;
        compileShader(vertexCode, fragmentCode);
    }

    ~Shader() {
        std::cout << "Destruction du programme shader" << std::endl;
    }

private:
    std::string loadShaderFromFile(const std::string& path) {
        return path;
    }

    void compileShader(const std::string& vertexCode, const std::string& fragmentCode) {
        std::cout << "Compilation des shaders..." << std::endl;
        std::cout << "Vertex Shader (extrait) : " << vertexCode.substr(0, 30) << "..." << std::endl;
        std::cout << "Fragment Shader (extrait) : " << fragmentCode.substr(0, 30) << "..." << std::endl;
    }
};