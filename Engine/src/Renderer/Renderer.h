#pragma once

#include <iostream>

#include <glad/glad.h>

namespace Renderer {

    // set the window context
    void setWindowContext( GLADloadproc loadproc );

    // Clear the screen
    void clear();

}