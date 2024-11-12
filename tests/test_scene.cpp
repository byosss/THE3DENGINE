#include <iostream>
#include <cassert>

#include "Scene/Scene.h"

int addition(int a, int b) { return a + b; }

int test_scene_load() {
    Scene scene;
    scene.load();
    return 0;
}

int main() {
    assert(addition(2, 3) == 5);
    assert(addition(-1, 1) == 0);
    std::cout << "Tests d'addition passés !" << std::endl;

    assert(test_scene_load() == 0);

    return 0;
}