#pragma once

#include <memory>

#include "api/OpenGL/OpenGLRenderer.h"
#include "api/Vulkan/VulkanRenderer.h"

enum class API { OpenGL, Vulkan };

class Renderer
{
public:
    static std::unique_ptr<IRenderer> Create(API api) 
    {
        switch (api) {
            case API::OpenGL: return std::make_unique<OpenGLRenderer>();
            case API::Vulkan: return std::make_unique<VulkanRenderer>();
            default: return nullptr;
        }
    }

private:
    Renderer() = default;
    ~Renderer() = default;
};