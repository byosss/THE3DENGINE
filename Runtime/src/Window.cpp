#include "Window.h"

#include "Input/InputManager.h"
#include "Event/EventManager.h"


Window::Window(int width, int height, const std::string& title) : m_Width(width), 
                                                                  m_Height(height), 
                                                                  m_Title(title)
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    // Configuration des hints GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Création de la fenêtre
    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_Window);

    // Event callbacks
    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        InputManager::getInstance().setKey(key, action);
        EventManager::getInstance().addEvent<KeyEvent>(key, action);
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
        InputManager::getInstance().setMouseButton(button, action);
        EventManager::getInstance().addEvent<MouseButtonEvent>(button, action);
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
        InputManager::getInstance().setMousePosition(xpos, ypos);
        EventManager::getInstance().addEvent<MouseMoveEvent>(xpos, ypos);
    });

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
        EventManager::getInstance().addEvent<WindowResizeEvent>(width, height);
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
        EventManager::getInstance().addEvent<WindowCloseEvent>();
    });

    // VSync
    this->setVSync(false);
}

Window::~Window()
{
    if (m_Window) {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }
    glfwTerminate();
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(m_Window);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_Window);
}

void Window::setVSync(bool enabled) {
    glfwSwapInterval(enabled ? 1 : 0);
}

void Window::disableCursor(bool enabled) {
    if (enabled) {
        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    } else {
        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

GLFWwindow* Window::getHandle() const {
    return m_Window;
}
