#include "Objects/Model3D.h"

Model3D::Model3D() 
{
    this->load_cube();

    this->shader = Shader();  // set the default shaders configured
}

Model3D::~Model3D() 
{
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
}


void Model3D::_ready(TimeManager* Time, InputManager* Input) 
{
}

void Model3D::_process(TimeManager* Time, InputManager* Input) 
{
    position += glm::vec3(0.0f, 0.0f, 0.0f) * glm::vec3(Time->getDeltaTime());
    rotation += glm::vec3(25.0f, 25.0f, 0.0f) * glm::vec3(Time->getDeltaTime());
}



void Model3D::load_cube() 
{
    //vertex data --- position and color
    //vertex position data has been duplicated to ensure constant color across each face
    GLfloat vertices[] = {

        // positions          // colors           // normals
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,   0.0f, -1.0,  0.0,   //  0
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,   0.0f, -1.0,  0.0,   //  1
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,   0.0f, -1.0,  0.0,   //  2
        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,   0.0f, -1.0,  0.0,   //  3
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,   0.0f,  0.0, -1.0,   //  4
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,   0.0f,  0.0, -1.0,   //  5
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f,   1.0f,  0.0,  0.0,   //  6
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0,  0.0,   //  7
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,   0.0f,  0.0, -1.0,   //  8
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,   0.0f,  0.0, -1.0,   //  9
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f,   1.0f,  0.0,  0.0,   // 10
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0,  0.0,   // 11
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0,  0.0,   // 12
         0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,   1.0f,  0.0,  0.0,   // 13
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,   0.0f,  1.0,  0.0,   // 14
        -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,   0.0f,  1.0,  0.0,   // 15
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0,  0.0,   // 16
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,   1.0f,  0.0,  0.0,   // 17
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,   0.0f,  0.0,  1.0,   // 18
        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,   0.0f,  0.0,  1.0,   // 19
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,   0.0f,  1.0,  0.0,   // 20
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,   0.0f,  1.0,  0.0,   // 21
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,   0.0f,  0.0,  1.0,   // 22
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,   0.0f,  0.0,  1.0,   // 23
    };

    GLuint indices[] = {
        0, 1, 2, 0, 2, 3, // bottom plane triangles
        8, 9, 5, 8, 5, 4, // back plane triangles
        17, 10, 6, 17, 6, 13, // right plane triangles
        16, 12, 7, 16, 7, 11, // left plane triangles
        20, 21, 14, 20, 14, 15, // top plane triangles
        19, 18, 22, 19, 22, 23 // front plane triangles
    };

    // ..:: Initialization code ::..
    // 1. bind Vertex Array Object
    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    // 2. vertices array in VBO
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 3. index array in EBO
    glGenBuffers(1, &this->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    // normal attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6* sizeof(float)));
    glEnableVertexAttribArray(2);


    this->sizei = 36;
}


GLuint Model3D::getVAO() 
{
    return this->VAO;
}

unsigned int Model3D::getSizei() 
{
    return this->sizei;
}


void Model3D::setShader(const char* vertexPath, const char* fragmentPath)
{
    this->shader = Shader(vertexPath, fragmentPath);
}

Shader Model3D::getShader()
{
    return this->shader;
}