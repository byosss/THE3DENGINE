#include "Event/EventManager.h"

EventManager& EventManager::getInstance() {
    static EventManager instance;
    return instance;
}

void EventManager::dispatchEvents() {
    for (const auto& event : m_events) {
        for (const auto& listener : m_listeners[event->getType()]) {
            listener(*event);
        }
    }
    m_events.clear();
}
