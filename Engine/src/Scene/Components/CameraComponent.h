#pragma once

struct CameraComponent
{
    enum class ProjectionType {
        Perspective,
        Orthographic
    };

    ProjectionType type = ProjectionType::Perspective;

    float fov = 45.0f;
    float nearClip = 0.1f;
    float farClip = 1000.0f;

    float orthoSize = 10.0f; // if type == Orthographic

    float depth = 0.0f; // priority in rendering (lower is rendered first)

    // // Matrice de projection
    // glm::mat4 getProjectionMatrix(float aspectRatio) const {
    //     if (projection == ProjectionType::Perspective) {
    //         return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    //     } else {
    //         float halfSize = orthoSize * 0.5f;
    //         return glm::ortho(-halfSize * aspectRatio, halfSize * aspectRatio, -halfSize, halfSize, nearPlane, farPlane);
    //     }
    // }
};
