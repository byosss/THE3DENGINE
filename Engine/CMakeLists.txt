project(Engine)

# Configuration globale
file(GLOB_RECURSE ENGINE_SOURCES src/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS inc/*.h)

# glad library
list(APPEND ENGINE_SOURCES vendor/glad/glad.c)

# Engine library
add_library(Engine SHARED ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor)
