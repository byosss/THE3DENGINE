#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <memory>
#include <algorithm>

#include "Event.h"

class EventManager {
public:
    EventManager() = default;
    ~EventManager() = default;

    void dispatchEvents();

    template<typename EventType>
    using EventCallback = std::function<void(const EventType&)>;

    template<typename EventType>
    void addListener(EventCallback<EventType> callback) {
        auto& listeners = m_listeners[typeid(EventType)];
        listeners.push_back([callback](const Event& event) {
            callback(static_cast<const EventType&>(event));
        });
    }

    template<typename EventType>
    void removeListener(EventCallback<EventType> callback) {
        auto& listeners = m_listeners[typeid(EventType)];
        listeners.erase(std::remove(listeners.begin(), listeners.end(), callback), listeners.end());
    }

    template<typename EventType, typename... Args>
    void addEvent(Args&&... args) {
        m_events.push_back(std::make_unique<EventType>(std::forward<Args>(args)...));
    }

private:
    std::vector<std::unique_ptr<Event>> m_events;
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> m_listeners;
};