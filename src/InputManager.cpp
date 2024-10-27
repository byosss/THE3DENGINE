#include "InputManager.h"

// constructeur
InputManager::InputManager(GLFWwindow* window) : window(window) {

    glfwSetWindowUserPointer(this->window, this);

    glfwSetKeyCallback(this->window, keyCallbackDispatcher);
    glfwSetMouseButtonCallback(this->window, mouseButtonCallbackDispatcher);
    glfwSetCursorPosCallback(this->window, cursorPositionCallbackDispatcher);

    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  

    this->pollEvents();

    glfwGetCursorPos(window, &mousePosition.x, &mousePosition.y);

    // Initialisation des tableaux de touches
    for (int i = 0; i < GLFW_KEY_LAST; ++i) {
        keyStates[i] = RELEASED;
        keyCallbacks[i] = nullptr;
    }

    for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; ++i) {
        mouseButtonStates[i] = RELEASED;
        mouseButtonCallbacks[i] = nullptr;
    }
}


// Static callback dispatcher
void InputManager::keyCallbackDispatcher(GLFWwindow* window, int key, int scancode, int action, int mods) {
    InputManager* Input = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (Input) {
        Input->inputCallback(key, action, Input->keyStates, Input->keyCallbacks);
    }
}

void InputManager::mouseButtonCallbackDispatcher(GLFWwindow* window, int button, int action, int mods) {
    InputManager* Input = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (Input) {
        Input->inputCallback(button, action, Input->mouseButtonStates, Input->mouseButtonCallbacks);
    }
}

void InputManager::cursorPositionCallbackDispatcher(GLFWwindow* window, double xpos, double ypos) {
    InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (inputManager) {
        inputManager->cursorPositionCallback(xpos, ypos);
    }
}


// Callback pour input et position de la souris
void InputManager::inputCallback(int input, int action, InputState* states, InputCallback* callbacks) {
    if (callbacks[input]) {
        callbacks[input](input, action, GLFW_MOD_SHIFT, GLFW_MOD_CONTROL); // Modifier les arguments pour vos besoins
    }

    if (action == GLFW_PRESS) {
        if (states[input] = RELEASED)
            states[input] = PRESSED;
        else if (states[input] = PRESSED)
            states[input] = REPEATED;
  
    } else if (action == GLFW_RELEASE) {
        states[input] = RELEASED;
    }
}

void InputManager::cursorPositionCallback(double xpos, double ypos) {

    // Fonction appelée lors du déplacement du curseur
    mousePosition = glm::dvec2(xpos, ypos);

    //std::cout << "Position du curseur : X = " << mousePos.x << ", Y = " << mousePos.y << std::endl;
}


// Setter de callback pour input clavier et souris
void InputManager::setKeyCallback(int key, InputCallback callback) {
    keyCallbacks[key] = callback;
}

void InputManager::setMouseButtonCallback(int button, InputCallback callback) {
    mouseButtonCallbacks[button] = callback;
}


// truc cool
bool InputManager::isKeyPressed(int key) {
    return keyStates[key] == PRESSED;
}

bool InputManager::isKeyRepeated(int key) {
    return keyStates[key] == REPEATED;
}

bool InputManager::isKeyReleased(int key) {
    return keyStates[key] == RELEASED;
}

glm::dvec2 InputManager::getMousePosition() {
    return this->mousePosition;
}

void InputManager::pollEvents() {
    glfwPollEvents();
}
