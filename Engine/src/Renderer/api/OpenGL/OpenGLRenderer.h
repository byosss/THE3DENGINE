#pragma once

#include "Renderer/IRenderer.h"

#include <glad/glad.h>

class OpenGLRenderer : public IRenderer
{
public:
    virtual void init( const WindowHandle& windowHandle ) override
    {
        // std::cout << "OpenGLRenderer::init()" << std::endl;
        // //-------------------------------------------------

        // Load OpenGL functions
        if (!gladLoadGLLoader((GLADloadproc)windowHandle.procAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    }

    virtual void draw( SceneManager& scene ) override
    {
        // std::cout << "OpenGLRenderer::draw()" << std::endl;
        // //-------------------------------------------------

        // Clear the screen
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }

    virtual void shutdown() override
    {
        // std::cout << "OpenGLRenderer::shutdown()" << std::endl;
        // //-----------------------------------------------------
    }

};