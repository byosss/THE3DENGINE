#include "Model.h"

Model::Model() 
{
    this->load_cube();
}

Model::~Model() 
{
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
}


void Model::_ready(TimeManager* Time, InputManager* Input) 
{
}

void Model::_process(TimeManager* Time, InputManager* Input) 
{
    position += glm::vec3(0.0f, 0.0f, 0.0f) * glm::vec3(Time->getDeltaTime());
    rotation += glm::vec3(25.0f, 25.0f, 0.0f) * glm::vec3(Time->getDeltaTime());
}

void Model::render(Shader* shader) 
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->position);

    model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotation autour de l'axe X (Pitch)
    model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotation autour de l'axe Y (Yaw)
    model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation autour de l'axe Z (Roll)

    model = glm::scale(model, this->scale);
    shader->setMat4("model", model);

    glBindVertexArray(this->getVAO());

    glDrawElements(GL_TRIANGLES, this->getSizei(), GL_UNSIGNED_INT, 0);
}


void Model::load_house() 
{
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    GLfloat vertices[] = {
        // positions         // colors
        0.0f,  0.7f, 0.0f,   1.0f, 0.0f, 0.0f, // hat
        -0.5f, 0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // top left
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // bottom left
        0.5f,  -0.5f, 0.0f,  1.0f, 1.0f, 0.0f, // bottom right
        0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f, // top right
        
    };
    GLuint indices[] = {  
        0, 1, 4, // first triangle
        1, 4, 3,  // second triangle
        1, 2, 3  // third triangle
    };

    
    // ..:: Initialization code :: ..
    // 1. bind Vertex Array Object
    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 3. copy our index array in a element buffer for OpenGL to use
    glGenBuffers(1, &this->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 4. then set the vertex attributes pointers
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    this->sizei = 9;
}

void Model::load_cube() 
{
    //vertex data --- position and color
    //vertex position data has been duplicated to ensure constant color across each face
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, //0
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, //1
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, //2
        -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, //3
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, //4
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, //5
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 1.0f, //6
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, //7
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, //8   0'
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, //9   1'
        0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, //10   2'
        -0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, //11   3'
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, //12   4'
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, //13   5'
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f, //14   6'
        -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f, //15   7'
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, //16   0''
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, //17   1''
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f, //18   2''
        -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f, //19   3''
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, //20   4''
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, //21   5''
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, //22   6''
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, //23   7''
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

    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 3. copy our index array in a element buffer for OpenGL to use
    glGenBuffers(1, &this->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 4. then set the vertex attributes pointers
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);


    this->sizei = 36;
}


GLuint Model::getVAO() 
{
    return this->VAO;
}

unsigned int  Model::getSizei() 
{
    return this->sizei;
}