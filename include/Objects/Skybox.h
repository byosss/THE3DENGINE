#ifndef SKYBOX_H
#define SKYBOX_H

#include <glad/glad.h>
#include <vector>
#include <string>
#include "Resource/Texture.h"
#include "Resource/Shader.h"

class Skybox
{
public:
    GLuint skyboxVAO, skyboxVBO;
    Shader shader;
    Texture texture;
    
    void load();
    void draw(glm::mat4 view, glm::mat4 projection);
};




#endif