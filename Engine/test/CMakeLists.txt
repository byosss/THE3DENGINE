
add_executable(test_TimeManager test_TimeManager.cpp)
target_link_libraries(test_TimeManager Engine)

add_test(NAME TimeManager COMMAND test_TimeManager)