#pragma once

#include "Window/WindowHandle.h"
#include "Scene/SceneManager.h"

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual void init( const WindowHandle& windowHandle ) = 0;
    virtual void draw( const SceneManager& scene ) = 0;
    virtual void terminate() = 0;
};