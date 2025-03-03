#pragma once

#include <iostream>

#include <glad/glad.h>

#include "Renderer/IRenderer.h"

#include "Scene/Components/Transform.h"
#include "Renderer/Components/MeshRenderer.h"

class OpenglRenderer : public IRenderer {
public:
    OpenglRenderer() = default;
    ~OpenglRenderer() override = default;

    void init( const WindowHandle& windowHandle ) override 
    {
        // Load OpenGL functions
        if (!gladLoadGLLoader((GLADloadproc)windowHandle.procAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    }

    void draw( const SceneManager& scene ) override 
    {
        // Clear the screen
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // // Draw the scene
        // scene.getRegistry().view<Transform, MeshRenderer>().each([](auto entity, Transform& transform, MeshRenderer& mesh) 
        // {

        // });
    }

    void terminate() override 
    {

    }
};