#ifndef MODEL3D_H
#define MODEL3D_H

#include <glm/gtc/matrix_transform.hpp>

#include "Objects/Node.h"
#include "Resource/Shader.h"
#include "Resource/Mesh.h"

class Model3D : public Node
{
public:
    Shader* shader;

    ~Model3D();

    void LoadModel(std::string fileName);
    void LoadModel(std::string fileName, std::string basePath);

    void setShader(const char* vertexPath, const char* fragmentPath);

    void Draw();    

private:
    std::vector<Mesh> meshes;
    std::vector<Texture> loadedTextures;

    // Does the parsing of the .obj file and fills in the data structure
    void ReadOBJ(std::string fileName, std::string basePath);

    // Retrieves a texture associated with the object - by its name and type
    Texture LoadTexture(std::string path, std::string type);

    // Reads the pixel data from an image file and loads it into the video memory
    GLuint readTextureFromFile(char const * path);
};

#endif