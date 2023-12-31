# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project Name: "Aurora"
project("Aurora" LANGUAGES C CXX)

# Define source files
set(SOURCES
    src/main.cpp
    src/Engine.cpp
    src/Renderer.cpp
    src/InputManager.cpp
    src/TimeManager.cpp
    src/ResourceManager.cpp
    src/Scene.cpp

    src/Resource/Resource.cpp
    src/Resource/Shader.cpp
    src/Resource/Texture.cpp
    src/Resource/Vertex.cpp
    src/Resource/Material.cpp

    src/Objects/Object.cpp
    src/Objects/Node.cpp
    src/Objects/Camera.cpp
    src/Objects/Model3D.cpp
    src/Objects/Light.cpp
    vendor/glad/glad.c
)

# Define source files
# file(GLOB_RECURSE SOURCES "src/*.c")

# Define include directories
set(INCLUDES 
    include/
    vendor/
)


# Define lib files & directory
link_directories(lib)
set(LIBS
    libglfw3.a
    opengl32
    gdi32
)

# Create an executable named "Aurora"
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the include directory
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

# Link the library files (.a, .so, .lib, .dll)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})

# Compile all source files using g++ (not gcc)
set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE CXX)