cmake_minimum_required(VERSION 3.10)
project(THE3DENGINE LANGUAGES CXX)

# Configuration globale
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Définit le chemin où les binaires seront générés.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Test configuration
enable_testing()

# Add subdirectories
add_subdirectory(Engine)
add_subdirectory(Editor)

