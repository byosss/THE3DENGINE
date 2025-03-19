#pragma once

#include "Renderer/CullingLayerMask.h"

struct Camera
{
    enum class ProjectionType {
        Perspective,
        Orthographic
    } projection = ProjectionType::Perspective;

    // enum class clear color/skybox

    float nearClip = 0.1f;
    float farClip = 1000.0f;

    float fov = 45.0f;       // if type == Perspective
    float orthoSize = 10.0f; // if type == Orthographic

    int priority = 0;

    struct Viewport {
        float x = 0.0f;
        float y = 0.0f;
        float width = 1.0f;
        float height = 1.0f;
    } viewport;

    CullingLayerMask cullingMask;
};
