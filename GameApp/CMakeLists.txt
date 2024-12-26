project(GameApp)

# Configuration globale
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS inc/*.h)

# Add GLFW subdirectory
add_subdirectory(vendor/glfw)

add_executable(GameApp ${SOURCES} ${HEADERS})
target_include_directories(GameApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(GameApp PRIVATE Engine glfw)
