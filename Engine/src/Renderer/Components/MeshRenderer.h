#pragma once

#include "Renderer/Renderer.h"

#include "Resource/Resources/Mesh.h"
#include "Resource/Resources/Material.h"

struct MeshRenderer
{
    std::shared_ptr<IVertexArray> vertexArray;

    std::shared_ptr<Material> material;

    MeshRenderer(const Mesh& mesh) {

        this->vertexArray = Renderer::createVertexArray();
    
        // Position buffer
        std::shared_ptr<IVertexBuffer> positionBuffer = Renderer::createVertexBuffer();
        positionBuffer->load(mesh.positions.data(), mesh.positions.size());
        vertexArray->addVertexBuffer(positionBuffer, VertexAttributeType::FLOAT3, false);
    
        // Normal buffer
        std::shared_ptr<IVertexBuffer> normalBuffer = Renderer::createVertexBuffer();
        normalBuffer->load(mesh.normals.data(), mesh.normals.size());
        vertexArray->addVertexBuffer(normalBuffer, VertexAttributeType::FLOAT3, false);
    
        // UV buffer
        std::shared_ptr<IVertexBuffer> uvBuffer = Renderer::createVertexBuffer();
        uvBuffer->load(mesh.uvs.data(), mesh.uvs.size());
        vertexArray->addVertexBuffer(uvBuffer, VertexAttributeType::FLOAT2, false);
    
        // Index buffer
        std::shared_ptr<IIndexBuffer> indexBuffer = Renderer::createIndexBuffer();
        indexBuffer->load(mesh.indices.data(), mesh.indices.size());
        vertexArray->setIndexBuffer(indexBuffer);
    }
};
