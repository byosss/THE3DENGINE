#pragma once

#include <string>

class Resource {
public:
    virtual ~Resource() = 0;

    virtual void load(const std::string& filePath) = 0;
};