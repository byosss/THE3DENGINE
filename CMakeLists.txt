cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

project(THE3DENGINE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_MODULE_STD 1)

add_subdirectory(Engine)
add_subdirectory(Client)