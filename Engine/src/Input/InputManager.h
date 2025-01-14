#pragma once

#include <array>

#include "Event/EventManager.h"
#include "Input/Key.h"

class InputManager {
    friend class Application;
    friend class Window;

public:
    static InputManager& getInstance();

    bool isKeyPressed(int key) const;
    bool isKeyReleased(int key) const;
    bool isKeyRepeated(int key) const;

    bool isMouseButtonPressed(int button) const;
    bool isMouseButtonReleased(int button) const;

    std::pair<double, double> getMousePosition() const;
    std::pair<double, double> getMouseDelta() const;

private:
    void update();

    InputManager();
    ~InputManager() = default;

    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(InputManager&&) = delete;

    std::array<int, KEY::LAST> m_keys;
    std::array<int, MOUSE::LAST> m_mouseButtons;
    std::pair<double, double> m_mousePosition;
    std::pair<double, double> m_mouseLastPosition;
    std::pair<double, double> m_mouseDelta;
};