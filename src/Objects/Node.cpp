#include "Objects/Node.h"

Node::Node()
{
    this->position = glm::vec3(0.0f, 0.0f, 0.0f);
    this->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    this->scale    = glm::vec3(1.0f, 1.0f, 1.0f);
}

void Node::_ready(TimeManager* Time, InputManager* Input) 
{ }

void Node::_process(TimeManager* Time, InputManager* Input) 
{ }