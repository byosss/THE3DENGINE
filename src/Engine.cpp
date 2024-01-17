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

    // activeShader = new Shader("../assets/shaders/light/shader.vert", "../assets/shaders/light/shader.frag");

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
    activeCamera = new Camera(glm::vec3(0.0, 0.0, 0.0));

    skybox = new Skybox;
    skybox->load();

    Model3D* cube1 = new Model3D;
    cube1->LoadModel("../assets/objects/crate/crate.obj");
    cube1->position = glm::vec3(-7.0, -3.19, -0.3);
    cube1->rotation = glm::vec3(0.0, 0.0, 0.0);
    cube1->scale = glm::vec3(1.5, 1.5, 1.5);

    Model3D* backpack = new Model3D;
    backpack->LoadModel("../assets/objects/backpack/backpack.obj");
    backpack->position = glm::vec3(-7.0, 0.0, 0.0);
    backpack->rotation = glm::vec3(0.0, 0.0, 0.0);
    // backpack->scale = glm::vec3(0.2, 0.2, 0.2);

    Model3D* whiteSphere1 = new Model3D;
    whiteSphere1->LoadModel("../assets/objects/sphereLisseWhite/sphere.obj");
    whiteSphere1->setShader("../assets/shaders/basic/shader.vert", "../assets/shaders/basic/shader.frag");
    whiteSphere1->position = glm::vec3(-4.0, 0.0, 0.0);
    whiteSphere1->scale = glm::vec3(0.2, 0.2, 0.2);
    
    Light* pointLight1 = new Light;
    pointLight1->position = glm::vec3(-4.0, 0.0, 0.0);
    pointLight1->color = glm::vec3(1.0, 1.0, 1.0);

    // ---------------------------------------------------------- //

    Model3D* cube2 = new Model3D;
    cube2->LoadModel("../assets/objects/crate/crate.obj");
    cube2->position = glm::vec3(8.0, 0.0, -3.0);
    cube2->rotation = glm::vec3(0.0, 0.0, 0.0);
    cube2->scale = glm::vec3(0.5, 0.5, 0.5);

    Model3D* cube3 = new Model3D;
    cube3->LoadModel("../assets/objects/crate/crate.obj");
    cube3->position = glm::vec3(8.0, 0.0, 0.0);
    cube3->rotation = glm::vec3(0.0, 0.0, 0.0);
    cube3->scale = glm::vec3(0.5, 0.5, 0.5);

    Model3D* cube4 = new Model3D;
    cube4->LoadModel("../assets/objects/crate/crate.obj");
    cube4->position = glm::vec3(8.0, 0.0, 3.0);
    cube4->rotation = glm::vec3(0.0, 0.0, 0.0);
    cube4->scale = glm::vec3(0.5, 0.5, 0.5);

    SpotLight* spotLight1 = new SpotLight;
    spotLight1->position = glm::vec3(8.0, -1.0, -9.0);
    spotLight1->direction = glm::vec3(-1.0, -1.0, 0.0);
    spotLight1->color = glm::vec3(0.5, 1.0, 0.3);

    Model3D* lampe = new Model3D;
    lampe->LoadModel("../assets/objects/crate/crate.obj");
    lampe->setShader("../assets/shaders/basic/shader.vert", "../assets/shaders/basic/shader.frag");
    lampe->position = glm::vec3(8.0, -1.0, -9.0);
    lampe->rotation = glm::vec3(0.0, 0.0, -45.0);
    lampe->scale = glm::vec3(0.05, 0.3, 0.05);


    // ---------------------------------------------------------- //
    

    Models3D.push_back(cube1);
    Models3D.push_back(backpack);
    Models3D.push_back(cube2);
    Models3D.push_back(cube3);
    Models3D.push_back(cube4);
    Models3D.push_back(lampe);
    Models3D.push_back(whiteSphere1);
    Lights.push_back(pointLight1);
    spotLights.push_back(spotLight1);

    DirectionalLight* sun = new DirectionalLight;
    sun->direction = glm::vec3(-0.2f, -1.0f, -0.3f);

    dirLights.push_back(sun);


    // ---------------------------------------------------------- //

    Model3D* plats[10][10];

    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            plats[i][j] = new Model3D;
            plats[i][j]->LoadModel("../assets/objects/crate/crate.obj");
            plats[i][j]->position = glm::vec3((4.0*i)-18.0, -6.7, (4.0*j)-18.0);
            plats[i][j]->scale = glm::vec3(2.0, 2.0, 2.0);
            Models3D.push_back(plats[i][j]);
        }
    }


    newLight = false;
    delLight = false;

}   

void Engine::update() {

    activeCamera->_process(Time, Input);

    // --------------------------------------------------- //
    
    glm::vec3 m1 = Models3D[1]->position;
    glm::vec3 m2 = Models3D[6]->position;

    float newX = m1.x + cos(Time->getDeltaTime()) * (m2.x - m1.x) - sin(Time->getDeltaTime()) * (m2.z - m1.z);
    float newZ = m1.z + sin(Time->getDeltaTime()) * (m2.x - m1.x) + cos(Time->getDeltaTime()) * (m2.z - m1.z);

    

    Models3D[6]->position = glm::vec3(newX, m1.y, newZ);
    Lights[0]->position = glm::vec3(newX, m1.y, newZ);


    // --------------------------------------------------- //
    
    if (cube2)
        Models3D[2]->position += glm::vec3(0.0f, 1.0f, 0.0f) * glm::vec3(Time->getDeltaTime());
    else
        Models3D[2]->position -= glm::vec3(0.0f, 1.0f, 0.0f) * glm::vec3(Time->getDeltaTime());
    if (Models3D[2]->position.y < -1.5f)
        cube2 = true;
    if (Models3D[2]->position.y > 1.5f)
        cube2 = false;

    Models3D[3]->rotation += glm::vec3(25.0f, 25.0f, 0.0f) * glm::vec3(Time->getDeltaTime());

    if (cube4)
        Models3D[4]->scale += glm::vec3(0.3f, 0.3f, 0.3f) * glm::vec3(Time->getDeltaTime());
    else
        Models3D[4]->scale -= glm::vec3(0.3f, 0.3f, 0.3f) * glm::vec3(Time->getDeltaTime());
    if (Models3D[4]->scale.x < 0.3f)
        cube4 = true;
    if (Models3D[4]->scale.x > 0.8f)
        cube4 = false;

    // --------------------------------------------------- //

    if (Input->isKeyRepeated(GLFW_KEY_UP))
    {
        if (!newLight) {
            if (Lights.size() < 25) {
                Light* pointLight = new Light;
                pointLight->position = glm::vec3(12.0, 0.0, 1.0*Lights.size()-12.0);
                pointLight->color = glm::vec3(1.0, 1.0, 1.0);

                Model3D* whiteSphere = new Model3D;
                whiteSphere->LoadModel("../assets/objects/sphereLisseWhite/sphere.obj");
                whiteSphere->setShader("../assets/shaders/basic/shader.vert", "../assets/shaders/basic/shader.frag");
                whiteSphere->position = pointLight->position;
                whiteSphere->scale = glm::vec3(0.2, 0.2, 0.2);

                Lights.push_back(pointLight);
                Models3D.push_back(whiteSphere);
            }
            newLight = true;
        }
    }
    if (Input->isKeyReleased(GLFW_KEY_UP))
    {
        newLight = false;
    }

    if (Input->isKeyRepeated(GLFW_KEY_DOWN))
    {
        if (!delLight) {

            if (Lights.size() > 1){
                Lights.pop_back();
                Models3D.pop_back();
            }

            delLight = true;
        }
    }
    if (Input->isKeyReleased(GLFW_KEY_DOWN))
    {
        delLight = false;
    }

}

void Engine::draw() {

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (Model3D* model3D : Models3D) 
    {
        model3D->shader->use();

        // POINTLIGHTS - DIRLIGHTS - SPOTLIGHTS //
        //--------------------------------------//

        // Point Lights
        int numLights = 0;
        for (size_t i = 0; i < Lights.size(); ++i) 
        {
            std::string indexString = std::to_string(i);

            model3D->shader->setVec3("pointLights["+ indexString +"].position", Lights[i]->position);
            model3D->shader->setVec3("pointLights["+ indexString +"].color", Lights[i]->color);

            model3D->shader->setVec3("pointLights["+ indexString +"].ambient", Lights[i]->ambient); 
            model3D->shader->setVec3("pointLights["+ indexString +"].diffuse", Lights[i]->diffuse); 
            model3D->shader->setVec3("pointLights["+ indexString +"].specular", Lights[i]->specular);

            model3D->shader->setFloat("pointLights["+ indexString +"].constant", Lights[i]->constant); 
            model3D->shader->setFloat("pointLights["+ indexString +"].linear", Lights[i]->linear); 
            model3D->shader->setFloat("pointLights["+ indexString +"].quadratic", Lights[i]->quadratic); 

            numLights++;
        }
        model3D->shader->setInt("numPointLights", numLights);

        // Directional Lights
        numLights = 0;
        for (size_t i = 0; i < dirLights.size(); ++i) 
        {
            std::string indexString = std::to_string(i);

            model3D->shader->setVec3("dirLights["+ indexString +"].direction", dirLights[i]->direction);
            model3D->shader->setVec3("dirLights["+ indexString +"].color", dirLights[i]->color);

            model3D->shader->setVec3("dirLights["+ indexString +"].ambient", dirLights[i]->ambient); 
            model3D->shader->setVec3("dirLights["+ indexString +"].diffuse", dirLights[i]->diffuse); 
            model3D->shader->setVec3("dirLights["+ indexString +"].specular", dirLights[i]->specular);

            numLights++;
        }
        model3D->shader->setInt("numDirLights", numLights);

        // Spot Lights
        numLights = 0;
        for (size_t i = 0; i < spotLights.size(); ++i) 
        {
            std::string indexString = std::to_string(i);

            model3D->shader->setVec3("spotLights["+ indexString +"].position", spotLights[i]->position);
            model3D->shader->setVec3("spotLights["+ indexString +"].direction", spotLights[i]->direction);
            model3D->shader->setVec3("spotLights["+ indexString +"].color", spotLights[i]->color);

            model3D->shader->setVec3("spotLights["+ indexString +"].ambient", spotLights[i]->ambient); 
            model3D->shader->setVec3("spotLights["+ indexString +"].diffuse", spotLights[i]->diffuse); 
            model3D->shader->setVec3("spotLights["+ indexString +"].specular", spotLights[i]->specular);

            model3D->shader->setFloat("spotLights["+ indexString +"].constant", spotLights[i]->constant); 
            model3D->shader->setFloat("spotLights["+ indexString +"].linear", spotLights[i]->linear); 
            model3D->shader->setFloat("spotLights["+ indexString +"].quadratic", spotLights[i]->quadratic);

            model3D->shader->setFloat("spotLights["+ indexString +"].cutOff", spotLights[i]->cutOff); 
            model3D->shader->setFloat("spotLights["+ indexString +"].outerCutOff", spotLights[i]->outerCutOff); 

            numLights++;
        }
        model3D->shader->setInt("numSpotLights", numLights);


        // POSITION - ROTATION - SCALING //
        //-------------------------------//
        glm::mat4 modelMatrix;

    
        modelMatrix = glm::mat4(1.0f);

        modelMatrix = glm::translate(modelMatrix, model3D->position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotation autour de l'axe X (Pitch)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotation autour de l'axe Y (Yaw)
        modelMatrix = glm::rotate(modelMatrix, glm::radians(model3D->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation autour de l'axe Z (Roll)
        modelMatrix = glm::scale(modelMatrix, model3D->scale);

        model3D->shader->setMat4("projection", activeCamera->getProjMatrix());
        model3D->shader->setMat4("view", activeCamera->getViewMatrix());
        model3D->shader->setMat4("model", modelMatrix);

        model3D->shader->setVec3("viewPos", activeCamera->position);

        model3D->Draw();
    }

    skybox->draw(activeCamera->getViewMatrix(), activeCamera->getProjMatrix());

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
