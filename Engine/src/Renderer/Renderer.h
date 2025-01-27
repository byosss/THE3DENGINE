#pragma once

#include <glad/glad.h>
#include <iostream>

#include "Scene/Scene.h"

class Renderer {
public:
    Renderer() = default;

    void draw( const Scene& scene );
    void shutdown();

    void setWindowContext( GLADloadproc loadproc );
};