#include "Objects/Model3D.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void Model3D::LoadModel(std::string fileName) {

    std::string basePath = fileName.substr(0, fileName.find_last_of('/')) + "/";
    ReadOBJ(fileName, basePath);
}

void Model3D::LoadModel(std::string fileName, std::string basePath)	{

    ReadOBJ(fileName, basePath);
}


void Model3D::Draw(Shader shaderProgram) {

    for (int i = 0; i < meshes.size(); i++)
        meshes[i].Draw(shaderProgram);
}

void Model3D::ReadOBJ(std::string fileName, std::string basePath) {

    std::cout << "Loading : " << fileName << std::endl;
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    int materialId;

    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, fileName.c_str(), basePath.c_str(), GL_TRUE);

    if (!err.empty()) {

        // `err` may contain warning message.
        std::cerr << err << std::endl;
    }

    if (!ret) {

        exit(1);
    }

    std::cout << "# of shapes    : " << shapes.size() << std::endl;
    std::cout << "# of materials : " << materials.size() << std::endl;

    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {

        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        std::vector<Texture> textures;

        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {

            int fv = shapes[s].mesh.num_face_vertices[f];

            //gps::Texture currentTexture = LoadTexture("index1.png", "ambientTexture");
            //textures.push_back(currentTexture);

            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++) {

                // access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

                float vx = attrib.vertices[3 * idx.vertex_index + 0];
                float vy = attrib.vertices[3 * idx.vertex_index + 1];
                float vz = attrib.vertices[3 * idx.vertex_index + 2];
                float nx = attrib.normals[3 * idx.normal_index + 0];
                float ny = attrib.normals[3 * idx.normal_index + 1];
                float nz = attrib.normals[3 * idx.normal_index + 2];
                float tx = 0.0f;
                float ty = 0.0f;

                if (idx.texcoord_index != -1) {

                    tx = attrib.texcoords[2 * idx.texcoord_index + 0];
                    ty = attrib.texcoords[2 * idx.texcoord_index + 1];
                }

                glm::vec3 vertexPosition(vx, vy, vz);
                glm::vec3 vertexNormal(nx, ny, nz);
                glm::vec2 vertexTexCoords(tx, ty);

                Vertex currentVertex;
                currentVertex.Position = vertexPosition;
                currentVertex.Normal = vertexNormal;
                currentVertex.TexCoords = vertexTexCoords;

                vertices.push_back(currentVertex);

                indices.push_back((GLuint)(index_offset + v));
            }

            index_offset += fv;
        }

        // get material id
        // Only try to read materials if the .mtl file is present
        size_t a = shapes[s].mesh.material_ids.size();

        if (a > 0 && materials.size()>0) {

            materialId = shapes[s].mesh.material_ids[0];
            if (materialId != -1) {

                Material currentMaterial;
                currentMaterial.ambient = glm::vec3(materials[materialId].ambient[0], materials[materialId].ambient[1], materials[materialId].ambient[2]);
                currentMaterial.diffuse = glm::vec3(materials[materialId].diffuse[0], materials[materialId].diffuse[1], materials[materialId].diffuse[2]);
                currentMaterial.specular = glm::vec3(materials[materialId].specular[0], materials[materialId].specular[1], materials[materialId].specular[2]);

                //ambient texture
                std::string ambientTexturePath = materials[materialId].ambient_texname;

                if (!ambientTexturePath.empty()) {

                    Texture currentTexture;
                    currentTexture = LoadTexture(basePath + ambientTexturePath, "ambientTexture");
                    textures.push_back(currentTexture);
                }

                //diffuse texture
                std::string diffuseTexturePath = materials[materialId].diffuse_texname;

                if (!diffuseTexturePath.empty()) {

                    Texture currentTexture;
                    currentTexture = LoadTexture(basePath + diffuseTexturePath, "diffuseTexture");
                    textures.push_back(currentTexture);
                }

                //specular texture
                std::string specularTexturePath = materials[materialId].specular_texname;

                if (!specularTexturePath.empty()) {

                    Texture currentTexture;
                    currentTexture = LoadTexture(basePath + specularTexturePath, "specularTexture");
                    textures.push_back(currentTexture);
                }
            }
        }

        meshes.push_back(Mesh(vertices, indices, textures));
    }
}

Texture Model3D::LoadTexture(std::string path, std::string type) {

    for (int i = 0; i < loadedTextures.size(); i++) {

        if (loadedTextures[i].path == path)	{

            //already loaded texture
            return loadedTextures[i];
        }
    }

    Texture currentTexture;
    currentTexture.id = readTextureFromFile(path.c_str());
    currentTexture.type = std::string(type);
    currentTexture.path = path;

    loadedTextures.push_back(currentTexture);

    return currentTexture;
}

GLuint Model3D::readTextureFromFile(char const * path)
{
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}


Model3D::~Model3D() {

    for (size_t i = 0; i < loadedTextures.size(); i++) {

        glDeleteTextures(1, &loadedTextures.at(i).id);
    }

    for (size_t i = 0; i < meshes.size(); i++) {

        GLuint VBO = meshes.at(i).VBO;
        GLuint EBO = meshes.at(i).EBO;
        GLuint VAO = meshes.at(i).VAO;
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glDeleteVertexArrays(1, &VAO);
    }
}