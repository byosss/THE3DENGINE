project("Engine")

# add files from the source directory
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

# add the shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})
set_target_properties(Engine PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# link the libraries
target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC EnTT::EnTT)
target_link_libraries(${PROJECT_NAME} PRIVATE lua)
#target_link_libraries(${PROJECT_NAME} PRIVATE assimp -static-libgcc -static-libstdc++)
