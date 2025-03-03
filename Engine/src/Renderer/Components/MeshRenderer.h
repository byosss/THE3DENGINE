#pragma once

#include <memory>

#include "Renderer/Renderer.h"

#include "Resource/Resources/Mesh.h"
#include "Resource/Resources/Material.h"

struct MeshRenderer
{
    std::shared_ptr<IVertexArray> vertexArray;

    std::shared_ptr<Material> material;

    // MeshRenderer(const Mesh& mesh) {

    //     vertexArray = Renderer::createVertexArray();

    //     // Position buffer
    //     auto positionBuffer = Renderer::createVertexBuffer();
    //     positionBuffer->load(mesh.positions.data(), mesh.positions.size());
    //     vertexArray->addVertexBuffer(positionBuffer, VertexAttributeType::FLOAT3, false);

    //     // Normal buffer
    //     auto normalBuffer = Renderer::createVertexBuffer();
    //     normalBuffer->load(mesh.normals.data(), mesh.normals.size());
    //     vertexArray->addVertexBuffer(normalBuffer, VertexAttributeType::FLOAT3, false);

    //     // UV buffer
    //     auto uvBuffer = Renderer::createVertexBuffer();
    //     uvBuffer->load(mesh.uvs.data(), mesh.uvs.size());
    //     vertexArray->addVertexBuffer(uvBuffer, VertexAttributeType::FLOAT2, false);

    //     // Index buffer
    //     auto indexBuffer = Renderer::createIndexBuffer();
    //     indexBuffer->load(mesh.indices.data(), mesh.indices.size());
    //     vertexArray->setIndexBuffer(indexBuffer);
    // }
};
