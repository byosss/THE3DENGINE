#pragma once

#include <functional>

struct WindowHandle {
    void* handle;
    void* procAddress;
    int width, height;
};