#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

// Defines several possible options for key state.
enum InputState {
    RELEASED,
    PRESSED,
    REPEATED
};

using InputCallback = void (*)(int, int, int, int);

class InputManager
{
private:

    GLFWwindow* window;

    InputState keyStates[GLFW_KEY_LAST];
    InputState mouseButtonStates[GLFW_MOUSE_BUTTON_LAST];

    InputCallback keyCallbacks[GLFW_KEY_LAST];
    InputCallback mouseButtonCallbacks[GLFW_MOUSE_BUTTON_LAST];

    glm::dvec2 mousePosition;

    // Méthode appelée à chaque fois qu'une touche est enfoncée
    static void keyCallbackDispatcher(GLFWwindow*, int, int, int, int);
    static void mouseButtonCallbackDispatcher(GLFWwindow*, int, int, int);
    static void cursorPositionCallbackDispatcher(GLFWwindow*, double, double);

    // Méthode appelée à chaque fois que la fenêtre est resize (OS où user resize)
    static void framebuffer_size_callback(GLFWwindow*, int, int);


    // Méthode pour mettre à jour l'état des touches de clavier et des keyCallback
    void inputCallback(int, int, InputState*, InputCallback*);

    // Méthode pour mettre à jour la position de la souris et des keyCallback
    void cursorPositionCallback(double, double);


public:

    InputManager(GLFWwindow* window);

    // Méthode pour définir une fonction de rappel pour une touche spécifique
    void setKeyCallback(int key, InputCallback callback);
    void setMouseButtonCallback(int button, InputCallback callback);

    // update poll IO events (keys pressed/released, mouse moved etc.)
    void pollEvents();

    bool isKeyPressed(int key);
    bool isKeyRepeated(int key);
    bool isKeyReleased(int key);

    glm::dvec2 getMousePosition();
};