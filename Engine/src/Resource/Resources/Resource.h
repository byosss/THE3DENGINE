#pragma once

#include <string>

class Resource {
public:
    virtual ~Resource() = 0;

    virtual bool load(const std::string& path) = 0;
};