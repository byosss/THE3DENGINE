project(Engine)

# Configuration globale
file(GLOB_RECURSE ENGINE_SOURCES src/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS inc/*.h)

# glad library
add_library(glad STATIC vendor/glad/glad.c)
target_include_directories(glad PUBLIC vendor/glad)

# Engine library
add_library(Engine SHARED ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

# Link glad library
target_link_libraries(Engine glad)

# add test subdirectory
add_subdirectory(test)