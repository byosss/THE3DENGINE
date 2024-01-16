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

    activeShader = new Shader("../assets/shaders/light/shader.vert", "../assets/shaders/light/shader.frag");

    loadScene();
}

void Engine::run() 
{
    // Call the _ready() method of all objects in the scene
    activeCamera->_ready(Time, Input);

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
    delete Time;
    delete Input;

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

void Engine::loadScene() 
{
    activeCamera = new Camera(glm::vec3(-3.0, 0.0, 0.0));

    Model3D* cube1 = new Model3D;
    cube1->LoadModel("../assets/objects/backpack/backpack.obj");
    cube1->position = glm::vec3(0.0, 0.0, 0.0);
    cube1->rotation = glm::vec3(0.0, 0.0, 0.0);
    // cube1->scale = glm::vec3(0.2, 0.2, 0.2);

    Model3D* cube2 = new Model3D;
    cube2->LoadModel("../assets/objects/sphereLisseWhite/sphere.obj");
    cube2->position = glm::vec3(0.0, 2.5, 0.0);
    cube2->scale = glm::vec3(0.2, 0.2, 0.2);
    
    Light* pointLight1 = new Light;
    pointLight1->position = glm::vec3(0.0, 2.5, 0.0);
    pointLight1->color = glm::vec3(1.0, 1.0, 1.0);

    DirectionalLight* sun = new DirectionalLight;
    sun->direction = glm::vec3(-0.2f, -1.0f, -0.3f);

    Models3D.push_back(cube1);
    Models3D.push_back(cube2);
    Lights.push_back(pointLight1);
    dirLights.push_back(sun);

}   

void Engine::update() {

    // Call the _process() method of all objects in the scene
    activeCamera->_process(Time, Input);

    //Models3D[0]->rotation += glm::vec3(0.0f, 0.0f, 15.0f) * glm::vec3(Time->getDeltaTime());
}

void Engine::draw() {

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    activeShader->use();

    // POINTLIGHTS - DIRLIGHTS - SPOTLIGHTS //
    //--------------------------------------//

    // Point Lights
    int numLights = 0;
    for (size_t i = 0; i < Lights.size(); ++i) 
    {
        std::string indexString = std::to_string(i);

        activeShader->setVec3("pointLights["+ indexString +"].position", Lights[i]->position);
        activeShader->setVec3("pointLights["+ indexString +"].color", Lights[i]->color);

        activeShader->setVec3("pointLights["+ indexString +"].ambient", Lights[i]->ambient); 
        activeShader->setVec3("pointLights["+ indexString +"].diffuse", Lights[i]->diffuse); 
        activeShader->setVec3("pointLights["+ indexString +"].specular", Lights[i]->specular);

        activeShader->setFloat("pointLights["+ indexString +"].constant", Lights[i]->constant); 
        activeShader->setFloat("pointLights["+ indexString +"].linear", Lights[i]->linear); 
        activeShader->setFloat("pointLights["+ indexString +"].quadratic", Lights[i]->quadratic); 

        numLights++;
    }
    activeShader->setInt("numPointLights", numLights);

    // Directional Lights
    numLights = 0;
    for (size_t i = 0; i < dirLights.size(); ++i) 
    {
        std::string indexString = std::to_string(i);

        activeShader->setVec3("dirLights["+ indexString +"].direction", dirLights[i]->direction);
        activeShader->setVec3("dirLights["+ indexString +"].color", dirLights[i]->color);

        activeShader->setVec3("dirLights["+ indexString +"].ambient", dirLights[i]->ambient); 
        activeShader->setVec3("dirLights["+ indexString +"].diffuse", dirLights[i]->diffuse); 
        activeShader->setVec3("dirLights["+ indexString +"].specular", dirLights[i]->specular);

        numLights++;
    }
    activeShader->setInt("numDirLights", numLights);

    // Spot Lights
    numLights = 0;
    for (size_t i = 0; i < spotLights.size(); ++i) 
    {
        std::string indexString = std::to_string(i);

        activeShader->setVec3("spotLights["+ indexString +"].position", spotLights[i]->position);
        activeShader->setVec3("spotLights["+ indexString +"].direction", spotLights[i]->direction);
        activeShader->setVec3("spotLights["+ indexString +"].color", spotLights[i]->color);

        activeShader->setVec3("spotLights["+ indexString +"].ambient", spotLights[i]->ambient); 
        activeShader->setVec3("spotLights["+ indexString +"].diffuse", spotLights[i]->diffuse); 
        activeShader->setVec3("spotLights["+ indexString +"].specular", spotLights[i]->specular);

        activeShader->setFloat("spotLights["+ indexString +"].constant", spotLights[i]->constant); 
        activeShader->setFloat("spotLights["+ indexString +"].linear", spotLights[i]->linear); 
        activeShader->setFloat("spotLights["+ indexString +"].quadratic", spotLights[i]->quadratic);

        activeShader->setFloat("spotLights["+ indexString +"].cutOff", spotLights[i]->cutOff); 
        activeShader->setFloat("spotLights["+ indexString +"].outerCutOff", spotLights[i]->outerCutOff); 

        numLights++;
    }
    activeShader->setInt("numSpotLights", numLights);


    // POSITION - ROTATION - SCALING //
    //-------------------------------//
    glm::mat4 modelMatrix;

    for (Model3D* model3D : Models3D) 
    {
        modelMatrix = glm::mat4(1.0f);

        modelMatrix = glm::translate(modelMatrix, model3D->position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotation autour de l'axe X (Pitch)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotation autour de l'axe Y (Yaw)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation autour de l'axe Z (Roll)
        modelMatrix = glm::scale(modelMatrix, model3D->scale);

        activeShader->setMat4("projection", activeCamera->getProjMatrix());
        activeShader->setMat4("view", activeCamera->getViewMatrix());
        activeShader->setMat4("model", modelMatrix);

        activeShader->setVec3("viewPos", activeCamera->position);

        model3D->Draw(*activeShader);
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