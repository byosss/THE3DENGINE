#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>

#include "Objects/Node.h"


// Default camera values
const float YAW         =  0.0f;  // regarde droit sur l'axe verticale
const float PITCH       =  0.0f;  // regarde droit sur l'axe horizontale
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float FOV        =  45.0f;

// An abstract camera class
class Camera : public Node
{
public:

    // camera options
    float MovementSpeed;
    float MouseSensitivity;

    // constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    // constructor with scalar values
    Camera(float posX, float posY, float posZ, float yaw, float pitch);

    glm::mat4 getViewMatrix();
    glm::mat4 getProjMatrix();
    void updateViewMatrix();
    void updateProjMatrix();

    void setViewport(unsigned int width, unsigned int height);
    void setFOV(float);

    void _ready(TimeManager*, InputManager*) override;
    void _process(TimeManager*, InputManager*) override;

private:

    // window Viewport
    unsigned int SCR_WIDTH;
    unsigned int SCR_HEIGHT;

    // camera Attributes
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    glm::mat4 projMatrix;
    glm::mat4 viewMatrix;

    float fov;

    glm::dvec2 mouseLastPos; // ça devrait être dans le futur scripting

    // processes input received from a keyboard input system.
    void ProcessKeyboardInput(double deltaTime, InputManager*);
    // processes input received from a mouse input system.
    void ProcessMouseMovement(glm::dvec2 mousePosition, GLboolean constrainPitch = true);

    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();
};

#endif