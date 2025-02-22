#include "Event/EventManager.h"

void EventManager::dispatchEvents() {
    for (const auto& event : m_events) {
        for (const auto& listener : m_listeners[event->getType()]) {
            listener(*event);
        }
    }
    m_events.clear();
}
