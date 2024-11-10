#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Components/Component.h"

#include "TimeManager.h"
#include "EventManager.h"

class Entity {
public:
    Entity(const std::string& name);
    ~Entity();

    void addComponent(std::unique_ptr<Component> component);

    template<typename T>
    T* getComponent()
    {
        for (auto& component : components)
        {
            if (dynamic_cast<T*>(component.get()))
            {
                return static_cast<T*>(component.get());
            }
        }

        return nullptr;
    }

    const std::string& getName() const;

private:
    std::string name;
    std::vector<std::unique_ptr<Component>> components;
};
