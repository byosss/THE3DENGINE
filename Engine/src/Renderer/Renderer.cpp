#include "Renderer/Renderer.h"

Api Renderer::s_Api = Api::OPENGL;

std::unique_ptr<IRenderer> Renderer::createRenderer(Api api)
{
    s_Api = api;

    switch (api) {
        case Api::OPENGL: return std::make_unique<OpenglRenderer>();
        case Api::VULKAN: return std::make_unique<VulkanRenderer>();
        default: return nullptr;
    }
}

std::shared_ptr<IVertexArray> Renderer::createVertexArray() 
{
    switch (s_Api) {
        case Api::OPENGL: return std::make_shared<OpenglVertexArray>();
        // case Api::VULKAN: return std::make_shared<VulkanVertexArray>();
        default: return nullptr;
    }
}

std::shared_ptr<IVertexBuffer> Renderer::createVertexBuffer()
{
    switch (s_Api) {
        case Api::OPENGL: return std::make_shared<OpenglVertexBuffer>();
        // case Api::VULKAN: return std::make_shared<VulkanVertexBuffer>();
        default: return nullptr;
    }
}

std::shared_ptr<IIndexBuffer> Renderer::createIndexBuffer()
{
    switch (s_Api) {
        case Api::OPENGL: return std::make_shared<OpenglIndexBuffer>();
        // case Api::VULKAN: return std::make_shared<VulkanIndexBuffer>();
        default: return nullptr;
    }
}