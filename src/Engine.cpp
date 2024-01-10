#include "Engine.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
GLFWwindow* window;


void keyCallbackExample(int, int, int, int);
void keyCallbackExitApp(int, int, int, int);
void framebuffer_size_callback(GLFWwindow*, int, int);


void Engine::innit() 
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return ;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
    

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
       std::cout << "Failed to initialize GLAD" << std::endl;
        return ;
    }

    // Initialize the TimeManager
    // --------------------------
    Time = new TimeManager(window);

    // Initialize the Input manager
    // --------------------------
    Input = new InputManager(window);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // setting the key callback
    // -----------------------------
    Input->setKeyCallback(GLFW_KEY_Q, keyCallbackExample);
    Input->setKeyCallback(GLFW_KEY_ESCAPE, keyCallbackExitApp);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load Scene
    Node* worldNode = new Node;

    Camera* camera = new Camera(glm::vec3(-3.0, 0.0, 0.0));

    Model3D* jack = new Model3D;
    jack->load_cube2();

    Light* pointLight = new Light;
    pointLight->position = glm::vec3(0.0, 1.5, 0.0);
    pointLight->color = glm::vec3(1.0, 1.0, 1.0);

    Model3D* lightCube = new Model3D;
    lightCube->load_coloredCube(1.0, 1.0, 1.0);
    lightCube->position = glm::vec3(0.0, 1.5, 0.0);
    lightCube->scale = glm::vec3(0.2, 0.2, 0.2);

    Light* pointLight2 = new Light;
    pointLight2->position = glm::vec3(0.0, -1.5, 0.0);
    pointLight2->color = glm::vec3(1.0, 1.0, 0.0);

    Model3D* lightCube2 = new Model3D;
    lightCube2->load_coloredCube(1.0, 1.0, 0.0);
    lightCube2->position = glm::vec3(0.0, -1.5, 0.0);
    lightCube2->scale = glm::vec3(0.2, 0.2, 0.2);

    // DirectionalLight* sun = new DirectionalLight;
    // sun->color = glm::vec3(1.0, 0.0, 1.0);

    // SpotLight* spotLight = new SpotLight;


    this->mainMap = new Scene("Scene_Main", worldNode);
    this->mainMap->addChild(worldNode, camera);
    this->mainMap->addChild(worldNode, jack);
    this->mainMap->addChild(worldNode, pointLight);
    this->mainMap->addChild(worldNode, lightCube);
    this->mainMap->addChild(worldNode, pointLight2);
    this->mainMap->addChild(worldNode, lightCube2);
    // this->mainMap->addChild(worldNode, sun);
    // this->mainMap->addChild(worldNode, spotLight);
    this->mainMap->setActiveCamera(camera);
}

void Engine::run() 
{
    // Call the _ready() method of all objects in the scene
    mainMap->_readyObjects(Time, Input);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // update deltaTime and the FPS counter
        // ------------------------------------
        Time->update();

        // update poll IO events (keys pressed/released, mouse moved etc.)
        // ---------------------------------------------------------------
        Input->pollEvents();

        // update objects
        // --------------
        update();

        // draw objects
        // ------------
        draw();
    }
}

void Engine::terminate() 
{
    // Nettoyage de la mémoire
    // for (Object* object : objects) {
    //     delete object; // Libération de la mémoire allouée
    // }

    delete Time;
    delete Input;

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}



void Engine::update() {

    // Call the _process() method of all objects in the scene
    mainMap->_processObjects(Time, Input);

    mainMap->Models3D[0]->position += glm::vec3(0.0f, 0.0f, 0.0f) * glm::vec3(Time->getDeltaTime());
    mainMap->Models3D[0]->rotation += glm::vec3(25.0f, 25.0f, 0.0f) * glm::vec3(Time->getDeltaTime());

}

void Engine::draw() {

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 modelMatrix;

    for (Model3D* model3D : mainMap->Models3D) 
    {
        model3D->getShader().use();

        // POSITION - ROTATION - SCALING //
        //-------------------------------//

        modelMatrix = glm::mat4(1.0f);

        modelMatrix = glm::translate(modelMatrix, model3D->position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotation autour de l'axe X (Pitch)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotation autour de l'axe Y (Yaw)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation autour de l'axe Z (Roll)
        modelMatrix = glm::scale(modelMatrix, model3D->scale);

        model3D->getShader().setMat4("projection", mainMap->getActiveCamera()->getProjMatrix());
        model3D->getShader().setMat4("view", mainMap->getActiveCamera()->getViewMatrix());
        model3D->getShader().setMat4("model", modelMatrix);

        model3D->getShader().setVec3("viewPos", mainMap->getActiveCamera()->position);


        // POINTLIGHTS - DIRLIGHTS - SPOTLIGHTS //
        //--------------------------------------//

        // Point Lights
        int numLights = 0;
        for (size_t i = 0; i < mainMap->Lights.size(); ++i) 
        {
            std::string indexString = std::to_string(i);

            model3D->getShader().setVec3("pointLights["+ indexString +"].position", mainMap->Lights[i]->position);
            model3D->getShader().setVec3("pointLights["+ indexString +"].color", mainMap->Lights[i]->color);

            model3D->getShader().setVec3("pointLights["+ indexString +"].ambient", mainMap->Lights[i]->ambient); 
            model3D->getShader().setVec3("pointLights["+ indexString +"].diffuse", mainMap->Lights[i]->diffuse); 
            model3D->getShader().setVec3("pointLights["+ indexString +"].specular", mainMap->Lights[i]->specular);

            model3D->getShader().setFloat("pointLights["+ indexString +"].constant", mainMap->Lights[i]->constant); 
            model3D->getShader().setFloat("pointLights["+ indexString +"].linear", mainMap->Lights[i]->linear); 
            model3D->getShader().setFloat("pointLights["+ indexString +"].quadratic", mainMap->Lights[i]->quadratic); 

            numLights++;
        }
        model3D->getShader().setInt("numPointLights", numLights);

        // Directional Lights
        numLights = 0;
        for (size_t i = 0; i < mainMap->dirLights.size(); ++i) 
        {
            std::string indexString = std::to_string(i);

            model3D->getShader().setVec3("dirLights["+ indexString +"].direction", mainMap->dirLights[i]->direction);
            model3D->getShader().setVec3("dirLights["+ indexString +"].color", mainMap->dirLights[i]->color);

            model3D->getShader().setVec3("dirLights["+ indexString +"].ambient", mainMap->dirLights[i]->ambient); 
            model3D->getShader().setVec3("dirLights["+ indexString +"].diffuse", mainMap->dirLights[i]->diffuse); 
            model3D->getShader().setVec3("dirLights["+ indexString +"].specular", mainMap->dirLights[i]->specular);

            numLights++;
        }
        model3D->getShader().setInt("numDirLights", numLights);

        // Spot Lights
        numLights = 0;
        for (size_t i = 0; i < mainMap->spotLights.size(); ++i) 
        {
            std::string indexString = std::to_string(i);

            model3D->getShader().setVec3("spotLights["+ indexString +"].position", mainMap->spotLights[i]->position);
            model3D->getShader().setVec3("spotLights["+ indexString +"].direction", mainMap->spotLights[i]->direction);
            model3D->getShader().setVec3("spotLights["+ indexString +"].color", mainMap->spotLights[i]->color);

            model3D->getShader().setVec3("spotLights["+ indexString +"].ambient", mainMap->spotLights[i]->ambient); 
            model3D->getShader().setVec3("spotLights["+ indexString +"].diffuse", mainMap->spotLights[i]->diffuse); 
            model3D->getShader().setVec3("spotLights["+ indexString +"].specular", mainMap->spotLights[i]->specular);

            model3D->getShader().setFloat("spotLights["+ indexString +"].constant", mainMap->spotLights[i]->constant); 
            model3D->getShader().setFloat("spotLights["+ indexString +"].linear", mainMap->spotLights[i]->linear); 
            model3D->getShader().setFloat("spotLights["+ indexString +"].quadratic", mainMap->spotLights[i]->quadratic);

            model3D->getShader().setFloat("spotLights["+ indexString +"].cutOff", mainMap->spotLights[i]->cutOff); 
            model3D->getShader().setFloat("spotLights["+ indexString +"].outerCutOff", mainMap->spotLights[i]->outerCutOff); 

            numLights++;
        }
        model3D->getShader().setInt("numSpotLights", numLights);


        // MATERIALS //
        //-----------//
        model3D->getShader().setInt("material.diffuse", 0);
        model3D->getShader().setInt("material.specular", 1);
        model3D->getShader().setFloat("material.shininess", 32.0f);

        // bind diffuse map
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, model3D->diffuse.ID);
        // bind specular map
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, model3D->specular.ID);
        


        glBindVertexArray(model3D->getVAO()); // Liaison du VAO

        if (model3D->EBO == 0) {
            glDrawArrays(GL_TRIANGLES, 0, model3D->getSizei());
        }
        else {
            glDrawElements(GL_TRIANGLES, model3D->getSizei(), GL_UNSIGNED_INT, 0);
        }
        
        glBindVertexArray(0); // Déliaison du VAO après avoir fini de dessiner
    }

    // swap buffers
    // ------------
    glfwSwapBuffers(window);
}



// Exemple d'utilisation de keyCallbacks (InputManager)
void keyCallbackExample(int key, int action, int shiftKeyPressed, int controlKeyPressed) {
    if (action == GLFW_PRESS) {
        std::cout << "Touche " << key << " appuyee !" << std::endl;
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else if (action == GLFW_RELEASE) {
        std::cout << "Touche " << key << " relachee !" << std::endl;
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

void keyCallbackExitApp(int key, int action, int shiftKeyPressed, int controlKeyPressed) {
    if (action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}