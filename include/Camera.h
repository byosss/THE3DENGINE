#pragma once

#include <glm/gtc/matrix_transform.hpp>

#include "Object.h"


// Default camera values
const float YAW         =  0.0f;  // regarde droit sur l'axe verticale
const float PITCH       =  0.0f;  // regarde droit sur l'axe horizontale
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f; // field of view ? ( fov )

// An abstract camera class
class Camera : public Object
{
public:

    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    // constructor with scalar values
    Camera(float posX, float posY, float posZ, float yaw, float pitch);

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix();

    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;
    void render(Shader*) override;

private:

    // camera Attributes
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    glm::dvec2 mouseLastPos;

    // processes input received from a keyboard input system.
    void ProcessKeyboardInput(double deltaTime, InputManager*);
    // processes input received from a mouse input system.
    void ProcessMouseMovement(glm::dvec2 mousePosition, GLboolean constrainPitch = true);

    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();
};