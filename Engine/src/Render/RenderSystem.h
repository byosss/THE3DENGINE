#pragma once

#include <iostream>

#include <glad/glad.h>

#include "Window/WindowManager.h"
#include "Scene/SceneManager.h"

namespace RenderSystem 
{
    // set the window context
    void init( WindowManager& window );

    // draw the scene
    void draw( entt::registry& registry );

    // Clear the screen
    void clear();
}