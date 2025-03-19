#pragma once

#include "Renderer/VertexArray.h"
#include "Renderer/ShaderProgram.h"
#include "Renderer/CullingLayerMask.h"

#include "Resource/Resources/Material.h"

struct MeshRenderer
{
    VertexArray vertexArray;

    ShaderProgram shader;

    struct Mat {
        float albedo[3];
        float metallic;
        float roughness;
        float ao;

        GLuint albedoMap;
        GLuint normalMap;
        GLuint metallicMap;
        GLuint roughnessMap;
        GLuint aoMap;
    } material;

    // CullingLayerMask cullingMask;
};
