#pragma once

#include <typeindex>

class Event {
public:
    virtual ~Event() = default;
    virtual std::type_index getType() const = 0;
};

class KeyEvent : public Event {
public:
    KeyEvent(int key, int action) : m_key(key), m_action(action) {}

    std::type_index getType() const override { return typeid(KeyEvent); }

    int getKey() const { return m_key; }
    int getAction() const { return m_action; }

private:
    int m_key;
    int m_action;
};

class MouseButtonEvent : public Event {
public:
    MouseButtonEvent(int button, int action)
        : m_button(button), m_action(action) {}

    std::type_index getType() const override { return typeid(MouseButtonEvent); }

    int getButton() const { return m_button; }
    int getAction() const { return m_action; }

private:
    int m_button;
    int m_action;
};

class MouseMoveEvent : public Event {
public:
    MouseMoveEvent(double x, double y) : m_x(x), m_y(y) {}

    std::type_index getType() const override { return typeid(MouseMoveEvent); }

    double getX() const { return m_x; }
    double getY() const { return m_y; }

private:
    double m_x;
    double m_y;
};

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(int width, int height) : m_width(width), m_height(height) {}

    std::type_index getType() const override { return typeid(WindowResizeEvent); }

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

private:
    int m_width;
    int m_height;
};

class WindowCloseEvent : public Event {
public:
    std::type_index getType() const override { return typeid(WindowCloseEvent); }
};