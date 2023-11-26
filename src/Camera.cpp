#include "Camera.h"

// constructor with vectors
Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
{
    this->Position = position;
    this->WorldUp  = up;
    this->Yaw      = yaw;
    this->Pitch    = pitch;

    this->Front            = glm::vec3(0.0f, 0.0f, -1.0f);
    this->MovementSpeed    = SPEED;
    this->MouseSensitivity = SENSITIVITY;
    this->Zoom             = ZOOM;

    updateCameraVectors();
}


// constructor with scalar values
Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
{
    this->Position = glm::vec3(posX, posY, posZ);
    this->WorldUp  = glm::vec3(upX, upY, upZ);
    this->Yaw      = yaw;
    this->Pitch    = pitch;

    this->Front            = glm::vec3(0.0f, 0.0f, -1.0f);
    this->MovementSpeed    = SPEED;
    this->MouseSensitivity = SENSITIVITY;
    this->Zoom             = ZOOM;

    updateCameraVectors();
}

// method called once at start
void Camera::_ready(TimeManager& Time, InputManager& Input)
{
    this->mouseLastPos = Input.getMousePosition();
}

// method called each frame
void Camera::_process(TimeManager& Time, InputManager& Input)
{
    this->ProcessKeyboardInput(Time.getDeltaTime(), Input);

    this->ProcessMouseMovement(Input.getMousePosition());

    this->mouseLastPos = Input.getMousePosition();
}

// processes input received from a keyboard input system.
void Camera::ProcessKeyboardInput(double deltaTime, InputManager& Input)
{
    float velocity = MovementSpeed * deltaTime;
    if (Input.isKeyRepeated(GLFW_KEY_W))
        Position += Front * velocity;
    if (Input.isKeyRepeated(GLFW_KEY_S))
        Position -= Front * velocity;
    if (Input.isKeyRepeated(GLFW_KEY_A))
        Position -= Right * velocity;
    if (Input.isKeyRepeated(GLFW_KEY_D))
        Position += Right * velocity;
    
    if (Input.isKeyRepeated(GLFW_KEY_LEFT_SHIFT))
        Position += Up * velocity;
    if (Input.isKeyRepeated(GLFW_KEY_LEFT_CONTROL))
        Position -= Up * velocity;
}

// processes input received from a mouse input system.
void Camera::ProcessMouseMovement(glm::dvec2 mousePosition, GLboolean constrainPitch)
{
    glm::dvec2 offset = glm::dvec2(mousePosition.x - mouseLastPos.x, 
                                   mouseLastPos.y - mousePosition.y); // reversed since y-coordinates go from bottom to top

    offset.x *= MouseSensitivity;
    offset.y *= MouseSensitivity;

    Yaw   += offset.x;
    Pitch += offset.y;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}


// processes input received from a mouse scroll-wheel event.
void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}

// calculates the front vector from the Camera's (updated) Euler Angles
void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up    = glm::normalize(glm::cross(Right, Front));
}

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}