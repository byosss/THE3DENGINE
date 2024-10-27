cmake_minimum_required(VERSION 3.10)

# Set the project name
project("THE3DENGINE")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set var for different directory
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/inc")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(VENDOR_DIR "${CMAKE_SOURCE_DIR}/vendor")

# Add the source and header files
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.h" )

# Add glad.c to the sources
list(APPEND SOURCES "${VENDOR_DIR}/glad/glad.c")

# Include directories
include_directories(${INCLUDE_DIR}
                    ${VENDOR_DIR})

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link the GLFW library
target_link_libraries(${PROJECT_NAME} ${LIB_DIR}/libglfw3.a)