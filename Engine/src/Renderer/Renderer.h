#pragma once

#include <iostream>

#include <glad/glad.h>

#include <entt/entity/registry.hpp>

namespace Renderer {

    // set the window context
    void setWindowContext( GLADloadproc loadproc );

    // Clear the screen
    void clear();

}