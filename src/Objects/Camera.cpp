#include "Objects/Camera.h"

// constructor with vectors
Camera::Camera(glm::vec3 position, float yaw, float pitch)
{
    this->position = position;
    this->rotation = glm::vec3(pitch, yaw, 0.0f);

    this->Front    = glm::vec3(0.0f, 0.0f, -1.0f);
    this->Up       = glm::vec3(0.0f, 1.0f, 0.0f);
    this->Right    = glm::vec3(1.0f, 0.0f, 0.0f);

    this->WorldUp  = glm::vec3(0.0f, 1.0f, 0.0f);

    this->MovementSpeed    = SPEED;
    this->MouseSensitivity = SENSITIVITY;
    this->fov              = FOV;

    updateCameraVectors();
}


// constructor with scalar values
Camera::Camera(float posX, float posY, float posZ, float yaw, float pitch)
{
    this->position = glm::vec3(posX, posY, posZ);
    this->rotation = glm::vec3(pitch, yaw, 0.0f);

    this->Front    = glm::vec3(0.0f, 0.0f, -1.0f);
    this->Up       = glm::vec3(0.0f, 1.0f, 0.0f);
    this->Right    = glm::vec3(1.0f, 0.0f, 0.0f);

    this->WorldUp  = glm::vec3(0.0, 1.0, 0.0);

    this->MovementSpeed    = SPEED;
    this->MouseSensitivity = SENSITIVITY;
    this->fov              = FOV;

    updateCameraVectors();
}

// method called once at start
void Camera::_ready(TimeManager* Time, InputManager* Input)
{
    this->mouseLastPos = Input->getMousePosition();
}

// method called each frame
void Camera::_process(TimeManager* Time, InputManager* Input)
{
    this->ProcessKeyboardInput(Time->getDeltaTime(), Input);

    this->ProcessMouseMovement(Input->getMousePosition());

    this->mouseLastPos = Input->getMousePosition();

    /*
    std::cout << "---------------------------" << std::endl;
    std::cout << "Front : x_" << Front.x << " y_" << Front.y << " z_" << Front.z << std::endl;
    std::cout << "Up : x_" << Up.x << " y_" << Up.y << " z_" << Up.z << std::endl;
    std::cout << "Right : x_" << Right.x << " y_" << Right.y << " z_" << Right.z << std::endl;
    std::cout << "Yaw : " << Yaw << std::endl;
    std::cout << "Pitch : " << Pitch << std::endl;
    */
}

void Camera::render(Shader*)
{
}

// processes input received from a keyboard input system.
void Camera::ProcessKeyboardInput(double deltaTime, InputManager* Input)
{
    float velocity = MovementSpeed * deltaTime;
    if (Input->isKeyRepeated(GLFW_KEY_W))
        position += Front * velocity;
    if (Input->isKeyRepeated(GLFW_KEY_S))
        position -= Front * velocity;
    if (Input->isKeyRepeated(GLFW_KEY_A))
        position -= Right * velocity;
    if (Input->isKeyRepeated(GLFW_KEY_D))
        position += Right * velocity;
    
    if (Input->isKeyRepeated(GLFW_KEY_LEFT_SHIFT))
        position += WorldUp * velocity;
    if (Input->isKeyRepeated(GLFW_KEY_LEFT_CONTROL))
        position -= WorldUp * velocity;
}

// processes input received from a mouse input system.
void Camera::ProcessMouseMovement(glm::dvec2 mousePosition, GLboolean constrainPitch)
{
    this->rotation.y += (mousePosition.x - mouseLastPos.x) * MouseSensitivity;
    this->rotation.x += (mouseLastPos.y - mousePosition.y) * MouseSensitivity; // reversed since y-coordinates go from bottom to top

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (rotation.x > 89.0f)
            rotation.x = 89.0f;
        if (rotation.x < -89.0f)
            rotation.x = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}


// calculates the front vector from the Camera's (updated) Euler Angles
void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
    front.y = sin(glm::radians(rotation.x));
    front.z = sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
    Front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up    = glm::normalize(glm::cross(Right, Front));
}

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(position, position + Front, Up);
}