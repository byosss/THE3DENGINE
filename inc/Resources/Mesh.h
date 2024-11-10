#pragma once

#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    Vertex() : Position(glm::vec3(0.0f)), Normal(glm::vec3(0.0f)), TexCoords(glm::vec2(0.0f)) {}
    Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texCoords) : Position(position), Normal(normal), TexCoords(texCoords) {}
};

struct BoundingBox {
    glm::vec3 center;
    glm::vec3 halfSize;
};

class Mesh
{
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    const GLuint& getVAO() const;
    const GLsizei& getSizei() const;
    const BoundingBox& getBoundingBox() const;

private:
    GLuint VAO, VBO, EBO; // OpenGL identifiers for buffers
    GLsizei sizei;        // Number of indices

    BoundingBox boundingBox; // Bounding box of the mesh

    void calculateBoundingBox(const std::vector<Vertex>& vertices);
};