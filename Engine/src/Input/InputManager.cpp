#include "InputManager.h"

InputManager::InputManager() {
    for (auto& key : m_keys) {
        key = false;
    }

    for (auto& button : m_mouseButtons) {
        button = false;
    }

    m_mousePosition = {0.0, 0.0};
    m_mouseLastPosition = {0.0, 0.0};
    m_mouseDelta = {0.0, 0.0};
}

void InputManager::update() {
    // delta mouse position
    m_mouseDelta.first = m_mousePosition.first - m_mouseLastPosition.first;
    m_mouseDelta.second = m_mousePosition.second - m_mouseLastPosition.second;

    m_mouseLastPosition = m_mousePosition;
}

bool InputManager::isKeyPressed(int key) const {
    return (m_keys[key] == KEY::PRESS);
}

bool InputManager::isKeyReleased(int key) const {
    return (m_keys[key] == KEY::RELEASE);
}

bool InputManager::isKeyRepeated(int key) const {
    return (m_keys[key] == KEY::REPEAT);
}

bool InputManager::isMouseButtonPressed(int button) const {
    return (m_mouseButtons[button] == MOUSE::PRESS);
}

bool InputManager::isMouseButtonReleased(int button) const {
    return (m_mouseButtons[button] == MOUSE::RELEASE);
}

std::pair<double, double> InputManager::getMousePosition() const {
    return m_mousePosition;
}

std::pair<double, double> InputManager::getMouseDelta() const {
    return m_mouseDelta;
}

void InputManager::setKey(int key, int action) {
    m_keys[key] = action;
}

void InputManager::setMouseButton(int button, int action) {
    m_mouseButtons[button] = action;
}

void InputManager::setMousePosition(double x, double y) {
    m_mousePosition = {x, y};
}
