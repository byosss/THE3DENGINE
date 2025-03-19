#include "Renderer/Renderer.h"

#include "Renderer/Components/Camera.h"
#include "Renderer/Components/MeshRenderer.h"

#include <iostream>

void Renderer::init( std::unique_ptr<RenderContext> renderContext )
{
    // Initialize the renderer
    // -----------------------
    m_renderContext = std::move( renderContext );

    if (!gladLoadGLLoader((GLADloadproc)m_renderContext->getProcAddress())) 
        throw std::runtime_error( "Failed to initialize GLAD" );
    
}

void Renderer::draw( SceneManager& scene )
{
    // Clear the screen
    // --------------
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw the scene
    // --------------


    // Swap the buffers
    // ----------------
    m_renderContext->swapBuffers();
}

void Renderer::terminate()
{
    // Terminate the renderer
    // ----------------------
}