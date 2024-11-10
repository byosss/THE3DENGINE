#include "Scene/Entity.h"

Entity::Entity(const std::string& name) : name(name)
{
}

Entity::~Entity()
{
}

void Entity::addComponent(std::unique_ptr<Component> component)
{
    components.push_back(std::move(component));
}

const std::string& Entity::getName() const
{
    return name;
}
