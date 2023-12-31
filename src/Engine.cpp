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
    Light* pointLight = new Light;
    Model3D* lightCube = new Model3D;

    lightCube->setShader("../assets/shaders/basic/shader.vert", "../assets/shaders/basic/shader.frag");
    lightCube->position = glm::vec3(0.0, 2.0, 0.0);
    lightCube->scale = glm::vec3(0.2, 0.2, 0.2);

    this->mainMap = new Scene("Scene_Main", worldNode);
    this->mainMap->addChild(worldNode, camera);
    this->mainMap->addChild(worldNode, jack);
    this->mainMap->addChild(worldNode, pointLight);
    this->mainMap->addChild(worldNode, lightCube);
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

}

void Engine::draw() {

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 modelMatrix;

    for (Model3D* model3D : mainMap->Models3D) {

        modelMatrix = glm::mat4(1.0f);

        modelMatrix = glm::translate(modelMatrix, model3D->position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotation autour de l'axe X (Pitch)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotation autour de l'axe Y (Yaw)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation autour de l'axe Z (Roll)
        modelMatrix = glm::scale(modelMatrix, model3D->scale);
        
        model3D->getShader().use();

        model3D->getShader().setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f)); 
        model3D->getShader().setVec3("lightPos", glm::vec3(0.0, 4.0, 0.0));
        model3D->getShader().setVec3("viewPos", glm::vec3(-3.0, 0.0, 0.0));

        model3D->getShader().setMat4("projection", mainMap->getActiveCamera()->getProjMatrix());
        model3D->getShader().setMat4("view", mainMap->getActiveCamera()->getViewMatrix());
        model3D->getShader().setMat4("model", modelMatrix);

        glBindVertexArray(model3D->getVAO()); // Liaison du VAO

        glDrawElements(GL_TRIANGLES, model3D->getSizei(), GL_UNSIGNED_INT, 0);

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