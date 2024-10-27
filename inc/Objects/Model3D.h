#ifndef MODEL3D_H
#define MODEL3D_H

#include <glm/gtc/matrix_transform.hpp>

#include "Objects/Node.h"
#include "Resource/Shader.h"
#include "Resource/Texture.h"


class Model3D : public Node
{
public:
    GLuint VAO, VBO, EBO;

    Texture diffuse, specular;

    Model3D();
    ~Model3D();

    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;

    GLuint getVAO();
    unsigned int getSizei();

    void setShader(const char*, const char*);
    Shader getShader();

    void load_cube();
    void load_cube2();
    void load_coloredCube(float, float, float);

private:
    unsigned int sizei;

    Shader shader;
};

#endif