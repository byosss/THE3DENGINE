#pragma once

#include <iostream>

#include "Renderer/IRenderer.h"

class VulkanRenderer : public IRenderer {
public:
    VulkanRenderer() = default;
    ~VulkanRenderer() override = default;

    void init( const WindowHandle& windowHandle ) override {
        std::cout << "VulkanRenderer::init" << std::endl;
    }

    void draw( const SceneManager& scene ) override {
        std::cout << "VulkanRenderer::draw" << std::endl;
    }

    void terminate() override {
        std::cout << "VulkanRenderer::terminate" << std::endl;
    }
};