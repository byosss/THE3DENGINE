#pragma once

#include <array>

#include "Input/Key.h"

class InputManager {
public:
    InputManager();
    ~InputManager() = default;

    void update();

    bool isKeyPressed(int key) const;
    bool isKeyReleased(int key) const;
    bool isKeyRepeated(int key) const;

    bool isMouseButtonPressed(int button) const;
    bool isMouseButtonReleased(int button) const;

    std::pair<double, double> getMousePosition() const;
    std::pair<double, double> getMouseDelta() const;

    void setKey(int key, int action);
    void setMouseButton(int button, int action);
    void setMousePosition(double x, double y);

private:
    std::array<int, KEY::LAST> m_keys;
    std::array<int, MOUSE::LAST> m_mouseButtons;
    std::pair<double, double> m_mousePosition;
    std::pair<double, double> m_mouseLastPosition;
    std::pair<double, double> m_mouseDelta;
};