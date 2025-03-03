#pragma once

#include <memory>

#include "Renderer/IRenderer.h"
#include "Renderer/IVertexArray.h"
#include "Renderer/IVertexBuffer.h"
#include "Renderer/IIndexBuffer.h"

#include "Renderer/Api/Opengl/OpenglRenderer.h"
#include "Renderer/Api/Opengl/OpenglVertexArray.h"
#include "Renderer/Api/Opengl/OpenglVertexBuffer.h"
#include "Renderer/Api/Opengl/OpenglIndexBuffer.h"

#include "Renderer/Api/Vulkan/VulkanRenderer.h"

enum class Api { OPENGL, VULKAN };

class Renderer {
public:
    static std::unique_ptr<IRenderer> createRenderer(Api api);

    static std::shared_ptr<IVertexArray> createVertexArray();
    static std::shared_ptr<IVertexBuffer> createVertexBuffer();
    static std::shared_ptr<IIndexBuffer> createIndexBuffer();

private:
    Renderer() = default;
    ~Renderer() = default;

    static Api s_Api;
};