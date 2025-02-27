#pragma once

#include <memory>
#include <unordered_map>

#include "Window/WindowHandle.h"
#include "Scene/SceneManager.h"
#include "Resource/ResourceManager.h"

class IRenderer
{
public:
    virtual ~IRenderer() = default;

    virtual void init( const WindowHandle& windowHandle ) = 0;
    virtual void draw( SceneManager& scene ) = 0;
    virtual void shutdown() = 0;
};