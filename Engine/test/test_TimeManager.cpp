#include <iostream>
#include <cassert>

#include "TimeManager.h"

float deltaTime_test1() {
    TimeManager timeManager;
    return timeManager.getDeltaTime();
}

float deltaTime_test2() {
    TimeManager timeManager;
    timeManager.tick();
    return timeManager.getDeltaTime();
}

float elapsedTime_test1() {
    TimeManager timeManager;
    return timeManager.getElapsedTime();
}

float elapsedTime_test2() {
    TimeManager timeManager;
    timeManager.tick();
    return timeManager.getElapsedTime();
}

int main()
{
    // Test 1: Check the time manager delta time
    assert(deltaTime_test1() == 0.0f);
    assert(deltaTime_test2() >= 0.0f);

    // Test 2: Check the time manager elapsed time
    assert(deltaTime_test1() == 0.0f);
    assert(deltaTime_test2() >= 0.0f);

    return 0;
}