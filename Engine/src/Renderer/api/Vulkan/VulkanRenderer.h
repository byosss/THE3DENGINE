#pragma once

#include "Renderer/IRenderer.h"

class VulkanRenderer : public IRenderer
{
public:
    ~VulkanRenderer() override = default;

    virtual void init( const WindowHandle& windowHandle ) override {
        // std::cout << "VulkanRenderer::init()" << std::endl;
        // //-------------------------------------------------
    }

    virtual void draw( SceneManager& scene ) override {
        // std::cout << "VulkanRenderer::draw()" << std::endl;
        // //-------------------------------------------------
    }

    virtual void shutdown() override {
        // std::cout << "VulkanRenderer::shutdown()" << std::endl;
        // //-----------------------------------------------------
    }
};