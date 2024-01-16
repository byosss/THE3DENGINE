#include "Resource/Mesh.h"


Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures) {

    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    // Create buffers/arrays
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);
    // Load data into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

    // Set the vertex attribute pointers
    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    // Vertex Normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
    // Vertex Texture Coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

    glBindVertexArray(0);
}

void Mesh::Draw(Shader shader)	{

    //set textures
    for (GLuint i = 0; i < textures.size(); i++) {

        glActiveTexture(GL_TEXTURE0 + i);
        shader.setInt(this->textures[i].type, i);
        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
    }
    shader.setFloat("shininess", 32.0f);

    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, (GLsizei)this->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    for(GLuint i = 0; i < this->textures.size(); i++) {

        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}