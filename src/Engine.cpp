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

    // build and compile our shader program
    // ------------------------------------
    //shader = new Shader("../assets/shaders/shader.vert", "../assets/shaders/shader.frag");


    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    
    // setting the key callback
    // -----------------------------
    Input->setKeyCallback(GLFW_KEY_Q, keyCallbackExample);
    Input->setKeyCallback(GLFW_KEY_ESCAPE, keyCallbackExitApp);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load Scene
    // Initialize the Camera
    Camera* camera = new Camera(glm::vec3(-3.0, 0.0, 0.0));
    this->setActiveCamera(camera);

    // Initialize the Model
    Model3D* jack = new Model3D;

    Light* pointLight = new Light;
    Model3D* lightCube = new Model3D;
    lightCube->setShader("../assets/shaders/basic/shader.vert", "../assets/shaders/basic/shader.frag");
    lightCube->position = glm::vec3(0.0, 2.0, 0.0);
    lightCube->scale = glm::vec3(0.2, 0.2, 0.2);


    objects.push_back(camera);
    objects.push_back(jack);
    objects.push_back(pointLight);
    objects.push_back(lightCube);

    Node* worldNode = new Node;
    worldNode->addChild(camera);
    worldNode->addChild(jack);
    worldNode->addChild(pointLight);
    worldNode->addChild(lightCube);

    char sceneName[] = "Scene_Main";
    Scene mainScene(sceneName, worldNode);
}

void Engine::run() 
{
    for (Object* object : objects) {
        object->_ready(Time, Input);
    }

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

        // swap buffers
        // ------------
        glfwSwapBuffers(window);
       
    }
}

void Engine::terminate() 
{
    // Nettoyage de la mémoire
    for (Object* object : objects) {
        delete object; // Libération de la mémoire allouée
    }

    delete Time;
    delete Input;
    delete shader;

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}



void Engine::update() {

    // Utilisation des objets via la classe de base
    for (Object* object : objects) {
        object->_process(Time, Input); // Appel polymorphique à la méthode dessiner()
    }

}

void Engine::draw() {

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    Shader::projectionMatrix = glm::perspective(glm::radians(getActiveCamera()->fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    Shader::viewMatrix = getActiveCamera()->GetViewMatrix();

    /*
    Model3D haaa = objects[1];
    lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    lightingShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    lightingShader.setVec3("lightPos", lightPos);
    lightingShader.setVec3("viewPos", camera.Position);
    */


    for (Object* object : objects) {
        object->render();
    }
}



void Engine::setActiveCamera(Camera* camera)
{
    this->activeCamera = camera;
}

Camera* Engine::getActiveCamera()
{
    return this->activeCamera;
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