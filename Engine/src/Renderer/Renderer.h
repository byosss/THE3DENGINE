#pragma once

#include <glad/glad.h>

#include "Window/RenderContext.h"
#include "Scene/SceneManager.h"

class Renderer {
public:
    void init( std::unique_ptr<RenderContext> renderContext );
    void draw( SceneManager& scene );
    void terminate();

private:
    std::unique_ptr<RenderContext> m_renderContext;
};