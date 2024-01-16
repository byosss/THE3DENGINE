#ifndef MESH_H
#define MESH_H

#include "Shader.h"

#include <string>
#include <vector>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    GLuint id;
    std::string type; // ambientTexture, diffuseTexture, specularTexture
    std::string path;
};

struct Material {
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

class Mesh
{
public:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    GLuint VAO, VBO, EBO;

    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);

    void Draw(Shader shader);
};



#endif