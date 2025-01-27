project("Runtime")

# add files from the source directory
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# link the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# link the engine
target_link_libraries(${PROJECT_NAME} PRIVATE Engine)