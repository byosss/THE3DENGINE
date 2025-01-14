cmake_minimum_required(VERSION 3.5)

project("THE3DENGINE" LANGUAGES CXX)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add external libraries
add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/imgui)

# Add subdirectories
add_subdirectory(Editor)
add_subdirectory(Engine)