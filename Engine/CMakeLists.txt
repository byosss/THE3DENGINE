project("Engine")

# add files from the source directory
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

# add the shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# link the libraries
target_link_libraries(${PROJECT_NAME} PUBLIC glad glfw EnTT::EnTT lua)
