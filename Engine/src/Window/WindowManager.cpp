#include "Window/WindowManager.h"

WindowManager::WindowManager(EventManager& Event, InputManager& Input) : m_Event(Event), m_Input(Input)
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
    m_Window = glfwCreateWindow(800, 600, "test", nullptr, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    m_Handle.handle = m_Window;
    m_Handle.procAddress = reinterpret_cast<void*>(glfwGetProcAddress);
    m_Handle.width = 800;
    m_Handle.height = 600;

    glfwMakeContextCurrent(m_Window);

    glfwSetWindowUserPointer(m_Window, this);

    // Event callbacks
    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto* wm = static_cast<WindowManager*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event.addEvent<KeyEvent>(key, action);
            wm->m_Input.setKey(key, action);
        }
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
        auto* wm = static_cast<WindowManager*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event.addEvent<MouseButtonEvent>(button, action);
            wm->m_Input.setMouseButton(button, action);
        }
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
        auto* wm = static_cast<WindowManager*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event.addEvent<MouseMoveEvent>(xpos, ypos);
            wm->m_Input.setMousePosition(xpos, ypos);
        }
    });

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
        auto* wm = static_cast<WindowManager*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Handle.width = width;
            wm->m_Handle.height = height;
            wm->m_Event.addEvent<WindowResizeEvent>(width, height);
        }
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
        auto* wm = static_cast<WindowManager*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event.addEvent<WindowCloseEvent>();
        }
    });
}

WindowManager::~WindowManager()
{
    if (m_Window) {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }
    glfwTerminate();
}

void WindowManager::pollEvents() {
    glfwPollEvents();
}

void WindowManager::swapBuffers() {
    glfwSwapBuffers(m_Window);
}

bool WindowManager::shouldClose() const {
    return glfwWindowShouldClose(m_Window);
}

void WindowManager::setVSync(bool enabled) {
    glfwSwapInterval(enabled ? 1 : 0);
}

void WindowManager::disableCursor(bool enabled) {
    if (enabled) {
        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    } else {
        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

int WindowManager::getWidth() const {
    return m_Handle.width;
}

int WindowManager::getHeight() const {
    return m_Handle.height;
}

const WindowHandle& WindowManager::getHandle() const {
    return m_Handle;
}
