#include "Renderer.h"

void Renderer::setWindowContext( GLADloadproc loadproc ) 
{
    // set glad 
    if ( !gladLoadGLLoader( loadproc ) ) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    // set viewport
    glViewport( 0, 0, 1280, 720 );
    
    // set depth test
    glEnable(GL_DEPTH_TEST);
}

void Renderer::clear() {
    // Clear the screen
    glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}