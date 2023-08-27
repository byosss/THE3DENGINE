#pragma once

#include <glad/glad.h> // include glad to get all the required OpenGL headers
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
    // the program ID
    unsigned int ID;
  
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // use/activate the shader
    void use();

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setBool(const std::string &name, bool value1, bool value2) const;
    void setBool(const std::string &name, bool value1, bool value2, bool value3) const;
    void setBool(const std::string &name, bool value1, bool value2, bool value3, bool value4) const;

    void setInt(const std::string &name, int value) const;
    void setInt(const std::string &name, int value1, int value2) const;   
    void setInt(const std::string &name, int value1, int value2, int value3) const;   
    void setInt(const std::string &name, int value1, int value2, int value3, int value4) const;   

    void setFloat(const std::string &name, float value) const;
    void setFloat(const std::string &name, float value1, float value2) const;
    void setFloat(const std::string &name, float value1, float value2, float value3) const;
    void setFloat(const std::string &name, float value1, float value2, float value3, float value4) const;
};