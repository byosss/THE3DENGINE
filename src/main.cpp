#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>

#include "TimeManager.h"
#include "InputManager.h"
#include "Shader.h"
#include "Camera.h"
#include "Model.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
GLFWwindow* window;




void keyCallbackExample(int, int, int, int);
void keyCallbackExitApp(int, int, int, int);

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
       std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);
    
    // build and compile our shader program
    // ------------------------------------
    Shader shader("assets/shaders/shader.vert", "assets/shaders/shader.frag");

    // Initialize the TimeManager
    // --------------------------
    TimeManager Time(window);

    // Initialize the Input manager
    // --------------------------
    InputManager Input(window);

    Input.setKeyCallback(GLFW_KEY_Q, keyCallbackExample);
    Input.setKeyCallback(GLFW_KEY_ESCAPE, keyCallbackExitApp);

    // Initialize the Camera
    Camera camera(glm::vec3(-3.0, 0.0, 0.0));
    // Initialize the Model
    Model jack;

    camera._ready(Time, Input);
    jack._ready(Time, Input);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {

        // update deltaTime and the FPS counter
        // ------
        Time.update();

        // update poll IO events (keys pressed/released, mouse moved etc.)
        // ---------------------------------------------------------------
        Input.pollEvents();


        // update objects
        // ------
        camera._process(Time, Input);
        jack._process(Time, Input);

        // update rendering
        // ------
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        // apply shaders to the triangle
        shader.use();

        // pass projection matrix to shader
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        shader.setMat4("projection", projection);

        // pass camera/view transformation to shader
        glm::mat4 view = camera.GetViewMatrix();
        shader.setMat4("view", view);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, jack.position);

        model = glm::rotate(model, glm::radians(jack.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotation autour de l'axe X (Pitch)
        model = glm::rotate(model, glm::radians(jack.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotation autour de l'axe Y (Yaw)
        model = glm::rotate(model, glm::radians(jack.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation autour de l'axe Z (Roll)

        model = glm::scale(model, jack.scale);
        shader.setMat4("model", model);

        glBindVertexArray(jack.VAO);
        glDrawElements(GL_TRIANGLES, jack.sizei, GL_UNSIGNED_INT, 0);

        // swap buffers
        // ------------
        glfwSwapBuffers(window);
       
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    
    return 0;
}

// Exemple d'utilisation de keyCallback (InputManager)
void keyCallbackExample(int key, int action, int shiftKeyPressed, int controlKeyPressed) {
    if (action == GLFW_PRESS) {
        std::cout << "Touche " << key << " appuyee !" << std::endl;
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else if (action == GLFW_RELEASE) {
        std::cout << "Touche " << key << " relachee !" << std::endl;
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

// Autre xemple d'utilisation de keyCallback
void keyCallbackExitApp(int key, int action, int shiftKeyPressed, int controlKeyPressed) {
    if (action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}