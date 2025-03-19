#include "Window/Window.h"

Window::Window() : m_Window(nullptr), m_Event(nullptr), m_Input(nullptr)
{
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Window::~Window()
{
    if (m_Window) {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }
    glfwTerminate();
}

void Window::createWindow(int width, int height, const std::string& title)
{
    // Create window
    m_Window = glfwCreateWindow(800, 600, "test", nullptr, nullptr);
    if (!m_Window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // Make the window's context current
    glfwMakeContextCurrent(m_Window);

    // Set user pointer
    glfwSetWindowUserPointer(m_Window, this);
}

void Window::init(EventManager& Event, InputManager& Input)
{
    m_Event = &Event;
    m_Input = &Input;

    // Event callbacks
    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto* wm = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event->addEvent<KeyEvent>(key, action);
            wm->m_Input->setKey(key, action);
        }
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
        auto* wm = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event->addEvent<MouseButtonEvent>(button, action);
            wm->m_Input->setMouseButton(button, action);
        }
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
        auto* wm = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event->addEvent<MouseMoveEvent>(xpos, ypos);
            wm->m_Input->setMousePosition(xpos, ypos);
        }
    });

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
        auto* wm = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event->addEvent<WindowResizeEvent>(width, height);
        }
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
        auto* wm = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (wm) {
            wm->m_Event->addEvent<WindowCloseEvent>();
        }
    });
}

void Window::pollEvents() {
    glfwPollEvents();
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

std::unique_ptr<RenderContext> Window::getRenderContext() const {
    
    RenderContext context;
    context.windowHandle = m_Window;

    return std::make_unique<RenderContext>( context );
}
