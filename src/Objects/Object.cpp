#include "Objects/Object.h"


void Object::addChild(Object* child) {
    this->children.push_back(child);
}