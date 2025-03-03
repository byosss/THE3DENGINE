#pragma once

#include <iostream>

#include "Renderer/IVertexArray.h"

class OpenglVertexArray : public IVertexArray {
public:
    OpenglVertexArray() = default;
    ~OpenglVertexArray() override = default;

    void addVertexBuffer(std::shared_ptr<IVertexBuffer> vb, VertexAttributeType type, bool normalized) override {
        std::cout << "Adding vertex buffer to OpenGL vertex array" << std::endl;
    }

    void setIndexBuffer(std::shared_ptr<IIndexBuffer> ib) override {
        std::cout << "Setting index buffer to OpenGL index array" << std::endl;
    }

    void bind() const override {
        std::cout << "Binding OpenGL vertex array" << std::endl;
    }
};