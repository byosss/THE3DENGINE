#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow() 
{
    setTitle("THE3DENGINE");
    resize(800, 600);

    // Set timer
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&OpenGLWindow::update));
    timer->start(0);
}

OpenGLWindow::~OpenGLWindow() 
{
    engine.terminate();
}

void OpenGLWindow::initializeGL() 
{
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
}

void OpenGLWindow::resizeGL(int w, int h) 
{
    // Resize the viewport
    glViewport(0, 0, w, h);
}

bool OpenGLWindow::initGlad() 
{
    // Fonction pour charger les fonctions OpenGL avec GLAD
    auto getProcAddress = [](const char* name) -> void* {
        return reinterpret_cast<void*>(QOpenGLContext::currentContext()->getProcAddress(name));
    };

    return gladLoadGLLoader((GLADloadproc)getProcAddress) != 0;
}