#include "Resources/Mesh.h"

#include <iostream>

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices) : sizei(indices.size()) {

    // Créer et lier le VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Créer et lier le VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    // Créer et lier l'EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Configurer les attributs de vertex
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

    // Désactiver le VAO
    glBindVertexArray(0);

    calculateBoundingBox(vertices);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Mesh::calculateBoundingBox(const std::vector<Vertex>& vertices) {
    if (vertices.empty()) return;

    // Initialiser le centre de la boîte englobante avec la position du premier sommet
    boundingBox.center = vertices[0].Position;
    boundingBox.halfSize = glm::vec3(0.0f);

    // Calculer les coins minimaux et maximaux de la boîte englobante
    for (const auto& vertex : vertices) {
        boundingBox.center += vertex.Position;
        boundingBox.halfSize = glm::max(boundingBox.halfSize, glm::abs(vertex.Position - boundingBox.center));
    }

    // Normaliser le centre
    boundingBox.center /= static_cast<float>(vertices.size());
}


const GLuint& Mesh::getVAO() const { return VAO; }
const GLsizei& Mesh::getSizei() const { return sizei; }
const BoundingBox& Mesh::getBoundingBox() const { return boundingBox; }
