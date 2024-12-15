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

    // connect to the OpenGL context
    QOpenGLContext* context = QOpenGLContext::currentContext();

    if (!context) {
        std::cerr << "Failed to get OpenGL context" << std::endl;
        return;
    }

    // Adapter getProcAddress pour GLAD
    auto getProcAddress = [](const char* name) -> void* {
        return reinterpret_cast<void*>(QOpenGLContext::currentContext()->getProcAddress(name));
    };

    // Initialiser GLAD avec la lambda
    if (!gladLoadGLLoader((GLADloadproc)getProcAddress)) {
        std::cerr <<  "Failed to initialize GLAD!" << std::endl;
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
