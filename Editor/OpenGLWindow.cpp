#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow() 
{
    // set screen size
    setTitle("THE3DENGINE");
    resize(800, 600);


}

OpenGLWindow::~OpenGLWindow() {
    // engine.terminate();
}

void OpenGLWindow::initializeGL() {

    // Check context
    if (!QOpenGLContext::currentContext()) {
        std::cerr << "Failed to get OpenGL context" << std::endl;
        return;
    }

    // Initialiser GLAD
    if (!initGlad()) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    // Initialiser le moteur
    engine.init();
}

void OpenGLWindow::paintGL() 
{
    engine.update();
    engine.draw();
    update();
}

bool OpenGLWindow::initGlad() 
{
    // Fonction pour charger les fonctions OpenGL avec GLAD
    auto getProcAddress = [](const char* name) -> void* {
        return reinterpret_cast<void*>(QOpenGLContext::currentContext()->getProcAddress(name));
    };

    return gladLoadGLLoader((GLADloadproc)getProcAddress) != 0;
}